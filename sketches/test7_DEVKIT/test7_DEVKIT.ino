#include "Arglib.h"
#include "resource.h"

static Arduboy arduboy;
static SimpleButtons buttons(arduboy);

static byte *video;

// Ship parameters
#define SHIP_DEC   40 // Decelleration
#define SHIP_ACC   20 // Accelleration
#define SHIP_SPD 2000 // Top speed

// Tunnel texture (this needs work for sure)
//#define TEXTURE(A, B, I) ((((A)+(I/2)) ^ ((B)+(I))) & 0x10) // Checkerboard pattern

byte world[] = {
  0b10101010, 0b01010101, 0b10101010, 0b01010101, 0b10101010, 0b01010101, 0b10101010, 0b01010101,
  0b10101010, 0b01010101, 0b10101010, 0b11111111, 0b10101010, 0b01010101, 0b10101010, 0b01010101,
  0b10101010, 0b01010101, 0b10101010, 0b01010101, 0b10101010, 0b01010101, 0b10101010, 0b01010101,
  0b10101010, 0b11111111, 0b10101010, 0b01010101, 0b10101010, 0b01010101, 0b10101010, 0b01010101,
  0b10101010, 0b01010101, 0b11111111, 0b01010101, 0b10101010, 0b01010101, 0b00000000, 0b01010101,
  0b10101010, 0b01010101, 0b10101010, 0b11111111, 0b10101010, 0b01010101, 0b00000000, 0b11111111,
  0b10101010, 0b01010101, 0b10101010, 0b11110000, 0b10101010, 0b01010101, 0b10101010, 0b00000000,
  0b10101010, 0b01010101, 0b11111111, 0b01010101, 0b11111111, 0b01010101, 0b00000000, 0b01010101,
  0b10101010, 0b01010101, 0b10101010, 0b01010101, 0b11001100, 0b11001100, 0b00110011, 0b00110011,
  0b11001100, 0b11001100, 0b00110011, 0b00110011, 0b11110000, 0b11110000, 0b11110000, 0b11110000,
  0b00001111, 0b00001111, 0b00001111, 0b00001111, 0b11110000, 0b11110000, 0b11110000, 0b11110000,
  0b00001111, 0b00001111, 0b00001111, 0b00001111, 0b00000000, 0b00000000, 0b11111111, 0b00000000,
  0b11111111, 0b10001000, 0b01000100, 0b00100010, 0b00010001, 0b10001000, 0b01000100, 0b00100010,
  0b00010001, 0b11111111, 0b00010001, 0b00100010, 0b01000100, 0b10001000, 0b00010001, 0b00100010,
  0b01000100, 0b10001000, 0b11111111, 0b00000000, 0b11111111, 0b00000000, 0b00000000, 0b11101111,
  0b00111000, 0b11111101, 0b00000111, 0b10111111, 0b11100000, 0b11110111, 0b00011100, 0b00000000,
};

__attribute__((always_inline))
static bool inline texturizer(byte x, byte y, word i) {
  return world[((y + i * 2) >> 4) & (sizeof(world) - 1)] & (1 << (((x + i / 4) >> 4) & 7));
}

#define TEXTURE(A, B, I) texturizer(A, B, I)

// Various helper macros
#define INPUT(X) (input & (X))                      // Check for button pressed
#define ISGN(X)  ((X) == 0 ? 0 : (X) > 0 ? -1 : +1) // Inverse sign function
#define MSB(X)   ((X) >> 0x8)                       // Extract most significant byte
#define LSB(X)   ((byte)(X))                        // Extract least significant byte

// Local variables
static int  vx, vy; // Ship velocity
static int  sx, sy; // Ship coordinates
static int  bx, by; // Bullet coordinates
static byte bl;     // Bullet lifetime
static byte twist;  // Tunnel twist multiplier (TAKEN OUT)
static word ix;     // Animation indexer
static int  hx, hy; // Autotracking tunnel centre coordinates

// Startup
void setup() {
  arduboy.start();
  video = arduboy.direct();
}

// Main demo/game code
void loop() {
  // Insert delay when compiling for emulator
#ifdef __EMULATING__
  delay(33);
#endif

  // Poll for user input
  byte input = buttons.poll();

  // Progress animations
  ix += 2;

  // User control
  bool engine = false;
  if(INPUT(DPAD_L)) engine = true, vx = max(-SHIP_SPD, vx - (SHIP_DEC + SHIP_ACC));
  if(INPUT(DPAD_R)) engine = true, vx = min(+SHIP_SPD, vx + (SHIP_DEC + SHIP_ACC));
  if(INPUT(DPAD_U)) engine = true, vy = max(-SHIP_SPD, vy - (SHIP_DEC + SHIP_ACC));
  if(INPUT(DPAD_D)) engine = true, vy = min(+SHIP_SPD, vy + (SHIP_DEC + SHIP_ACC));

  if(INPUT(BTN_B) && !bl) {
    bl = 64; bx = sx; by = sy;
    twist = 120;
  } else if(twist) twist = MSB(twist * 250);

  bx = MSB(bx * 250);
  by = MSB(by * 250);

  if(vx > 0) vx = max(0, vx - SHIP_DEC); else if(vx < 0) vx = min(0, vx + SHIP_DEC);
  if(vy > 0) vy = max(0, vy - SHIP_DEC); else if(vy < 0) vy = min(0, vy + SHIP_DEC);

  // Control ship position
  sx += vx; sy += vy;
  if(sx > +30000) { vx = -vx; sx = +60000 - sx; }
  if(sx < -30000) { vx = -vx; sx = -60000 - sx; }
  if(sy > +15000) { vy = -vy; sy = +30000 - sy; }
  if(sy < -15000) { vy = -vy; sy = -30000 - sy; }
  
  // Compute high(er) resolution, low passed ship position
  hx += ((MSB(sx)) * 8 - hx) / 16;
  hy += ((MSB(sy) + 6) * 16 - hy) / 8;
  
  // Convert to tunnel center coordinates
  byte cx = (-hx / 16) + 64, cy = (-hy / 32) + 32;
  
  // Clear drawing area
  arduboy.clearDisplay();
  
  // Draw tunnel using LUTs (expanded to quads for performance)
  byte xterm = cx, dx, b8;
  for(dx = b8 = 0; dx < cx; dx++, xterm--) {
    byte yterm = cy, dy;
    byte *vptr = &video[dx];
    for(dy = 0; dy < cy; dy++, yterm--, b8 >>= 1) {
      word t = pgm_read_word(&lut[128 * yterm + xterm]); // Quadrant 1
      if(LSB(t) != 0 && TEXTURE(64 + MSB(t), LSB(t), ix)) b8 |= 0x80;
      if(7 == (dy & 7)) *vptr = b8, vptr += 128;
    }
    for(; dy < 64; dy++, yterm++, b8 >>= 1) {
      word t = pgm_read_word(&lut[128 * yterm + xterm]); // Quadrant 2
      if(LSB(t) != 0 && TEXTURE(63 - MSB(t), LSB(t), ix)) b8 |= 0x80;
      if(7 == (dy & 7)) *vptr = b8, vptr += 128;
    }
  }
  for(; dx < 128; dx++, xterm++) {
    byte yterm = cy, dy;
    byte *vptr = &video[dx];
    for(dy = b8 = 0; dy < cy; dy++, yterm--, b8 >>= 1) {
      word t = pgm_read_word(&lut[128 * yterm + xterm]); // Quadrant 3
      if(LSB(t) != 0 && TEXTURE(191 - MSB(t), LSB(t), ix)) b8 |= 0x80;
      if(7 == (dy & 7)) *vptr = b8, vptr += 128;
    }
    for(; dy < 64; dy++, yterm++, b8 >>= 1) {
      word t = pgm_read_word(&lut[128 * yterm + xterm]); // Quadrant 4
      if(LSB(t) != 0 && TEXTURE(192 + MSB(t), LSB(t), ix)) b8 |= 0x80;
      if(7 == (dy & 7)) *vptr = b8, vptr += 128;
    }
  }

  // Screen flashing
  if(twist > 110) {
    byte *vptr = video;
    while(vptr < &video[1024]) *vptr++ = 0xFF;
  } else if(twist > 105 || (twist > 95 && twist < 100)) {
    byte *vptr = video;
    while(vptr < &video[1024]) *vptr++ |= ((intptr_t)vptr & 1) ? 0x55 : 0xAA;
  }
  
  // Coord-system conversion
  int wx, wy;

  // Draw bomb
  if(bl) {
    wx = MSB(bx) + cx - 7;
    wy = MSB(by) + cy;
    arduboy.drawSprite(wx, wy, bullet, 7, 8, (bl >> 3) + (ix & 8 ? 1 : 0), BLACK);
    if(!(ix & 4)) arduboy.drawSprite(wx, wy, bullet, 7, 8, (bl >> 3) + (ix & 8 ? 9 : 1), WHITE);
    bl--;
  }
  
  // Draw lasers
  wx = MSB(sx) + cx;
  wy = MSB(sy) + cy + 2;
  if(INPUT(BTN_A) && (ix & 2)) {
    arduboy.drawLine(wx + (ix & 4 ? -5 : +3), wy, cx + (ix & 4 ? -1 : +1), cy, BLACK);
    arduboy.drawLine(wx + (ix & 4 ? -3 : +5), wy, cx + (ix & 4 ? -1 : +1), cy, BLACK);
    arduboy.drawLine(wx + (ix & 4 ? +4 : -4), wy, cx + (ix & 4 ? +1 : -1), cy, BLACK);
    arduboy.drawLine(wx + (ix & 4 ? -4 : +4), wy, cx + (ix & 4 ? -1 : +1), cy, WHITE);
  }
  
  // Draw ship
  wx = MSB(sx) + cx - 7;
  wy = MSB(sy) + cy;
  arduboy.drawSprite(wx, wy, ship, 15, 16, 0, BLACK);
  arduboy.drawSprite(wx, wy, ship, 15, 16, 1, WHITE);
  if(engine && ix & 4) arduboy.drawSprite(wx, wy, ship, 15, 16, 2, WHITE); // Engine
  
  // Flip
  arduboy.display();

}
