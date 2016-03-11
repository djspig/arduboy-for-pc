#include "Arglib.h"
#include "resource.h"

Arduboy arduboy;

byte *rambuf;

#define TEXTURE(A, B) (((A) ^ (B)) & 1) // CHECKERS
//#define TEXTURE(A, B) (((A) & 3) == ((B) & 3)) // SPIRAL
//#define TEXTURE(B, A) ((rwlk[(A) + ((B) >> 3) * 256] << ((B) & 7)) & 128) // RAMWALK
//byte rwlk[256*32];

void setup() {
  rambuf = arduboy.direct();
  arduboy.start();
  //for(word n = 0; n < 256*32; n++) rwlk[n] = rand();
  /*
  for(word n = 0; n < 8192; n++) {
    printf((n&15) ? " " : "  ");
    //printf("0x%02X%02X,", x_lut[8191-n], y_lut[8191-n]);
    printf("0x%04X,", (lut[n] & 0xFF) | ((lut[n] & 0xFC00) >> 2));
    if((n & 15) == 15) printf("\n");
  }
*/
}

char sx, sy; // Ship coordinates
char twist;  // Tunnel twist multiplier
word ix;     // Animation indexer

void loop() {
#ifdef __EMULATING__
  delay(33); // Delay for emulator @ 30fps
#endif

  static int hx = 0, hy = 0;  // Tunnel center coordinates

  // Progress animation
  ix += 2;

  // Compute ship position (replace with user control?)
  sx = sin((float)ix / 113) * 64;
  sy = cos((float)ix / 67) * 32;
  twist = sin((float)ix / 283) * 64; // Se below

  // Compute high(er) resolution, low passed ship position
  hx += (sx * 8 - hx) / 64;
  hy += ((sy + 6) * 16 - hy) / 32;
  
  // Convert to tunnel center coordinates
  byte cx = (-hx / 8) + 64, cy = (-hy / 16) + 32;
  
  // Clear drawing area
  arduboy.clearDisplay();

  // Draw tunnel using LUTs
/*
  byte register yterm = cy;
  for(byte register dy = 0; dy < 64; dy++) {
    byte register xterm = cx;
    for(byte register dx = 0; dx < 128; dx++) {
      // Fetch polar coordinates from LUT
      word t = pgm_read_word(&lut[128 * yterm + xterm]);
      byte ty = t; // Texture Y from LSB
      if(ty != 0) { // Distance shadow mask
        byte tx = t >> 8; // Texture x from MSB
        if(cy < dy != cx < dx) tx = 255 - tx;
        tx = (tx >> 2) + (((cy < dy ? 2 : 0) + (cx < dx != cy < dy ? 1 : 0)) << 6);
        // Scale and animate
        tx = (tx + ((ty * twist) >> 8) + ix) >> 4; // With twist
        //tx = (tx + ix) >> 4; // Without twist
        ty = (ty + ix) >> 4;
        arduboy.drawPixel(dx, dy, (tx ^ ty) & 1);
      }
      if(cx < dx) xterm++; else if(cx > dx) xterm--;
    }
  }
*/
  
  // Draw tunnel using LUTs (expanded for performance)
  byte xterm = cx, dx, b8;
  for(dx = b8 = 0; dx < cx; dx++, xterm--) {
    byte yterm = cy, dy;
    for(dy = 0; dy < cy; dy++, yterm--, b8 >>= 1) {
      word t = pgm_read_word(&lut[128 * yterm + xterm]); // Polar coords from LUT
      if((byte)t != 0) { // Distance shadow mask
        byte tx = ((64 + (t >> 8)) + (((byte)t * twist) >> 8) + ix) >> 4; // Scale and animate X
        byte ty = ((byte)t + ix) >> 4;
        if(TEXTURE(tx, ty)) b8 |= 0x80;
      }
      if(7 == (dy & 7)) rambuf[(dy & 0xF8) * 16 + dx] = b8;
    }
    for(; dy < 64; dy++, yterm++, b8 >>= 1) {
      word t = pgm_read_word(&lut[128 * yterm + xterm]); // Polar coords from LUT
      if((byte)t != 0) { // Distance shadow mask
        byte tx = ((64-(t >> 8)) + (((byte)t * twist) >> 8) + ix) >> 4; // Scale and animate
        byte ty = ((byte)t + ix) >> 4;
        if(TEXTURE(tx, ty)) b8 |= 0x80;
      }
      if(7 == (dy & 7)) rambuf[(dy & 0xF8) * 16 + dx] = b8;
    }
  }
  for(; dx < 128; dx++, xterm++) {
    byte yterm = cy, dy;
    for(dy = b8 = 0; dy < cy; dy++, yterm--, b8 >>= 1) {
      word t = pgm_read_word(&lut[128 * yterm + xterm]); // Polar coords from LUT
      if((byte)t != 0) { // Distance shadow mask
        byte tx = ((191 - (t >> 8)) + (((byte)t * twist) >> 8) + ix) >> 4; // Scale and animate
        byte ty = ((byte)t + ix) >> 4;
        if(TEXTURE(tx, ty)) b8 |= 0x80;
      }
      if(7 == (dy & 7)) rambuf[(dy & 0xF8) * 16 + dx] = b8;
    }
    for(; dy < 64; dy++, yterm++, b8 >>= 1) {
      word t = pgm_read_word(&lut[128 * yterm + xterm]); // Polar coords from LUT
      if((byte)t != 0) { // Distance shadow mask
        byte tx = (((t >> 8) | 192) + (((byte)t * twist) >> 8) + ix) >> 4; // Scale and animate
        byte ty = ((byte)t + ix) >> 4;
        if(TEXTURE(tx, ty)) b8 |= 0x80;
      }
      if(7 == (dy & 7)) rambuf[(dy & 0xF8) * 16 + dx] = b8;
    }
  }

  // Draw ship
  int wx = sx + cx - 7;
  int wy = sy + cy;
  arduboy.drawSprite(wx, wy, ship, 16, 16, 0, BLACK);
  arduboy.drawSprite(wx, wy, ship, 16, 16, 1, WHITE);
  if(millis() & 64) arduboy.drawSprite(wx, wy, ship, 16, 16, 2, WHITE); // Engine
  
  // Flip
  arduboy.display();

}
