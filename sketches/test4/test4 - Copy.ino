#include "Arglib.h"
#include "resource.h"

Arduboy arduboy;

void setup() {
/*
  for(word n = 0; n < 8192; n++) {
    printf((n&15) ? " " : "  ");
    printf("0x%02X%02X,", x_lut[8191-n], y_lut[8191-n]);
    if((n & 15) == 15) printf("\n");
  }
*/
}

char sx, sy; // Ship coordinates
char twist;  // Tunnel twist multiplier
word ix;     // Animation indexer

void loop() {
#ifdef __EMULATING__
  delay(30); // Delay for emulator
#endif

  static int hx = 0, hy = 0;  // Tunnel center coordinates

  // Progress animation
  ix += 3;

  // Compute ship position (replace with user control?)
  sx = sin((float)ix / 113) * 64;
  sy = cos((float)ix / 67) * 32;
  twist = sin((float)ix / 283) * 64; // Se below

  // Compute high(er) resolution, low passed ship position
  hx += (sx * 8 - hx) / 64;
  hy += ((sy + 6) * 8 - hy) / 64;
  
  // Convert to tunnel center coordinates
  byte cx = (-hx / 8) + 64, cy = (-hy / 8) + 32;
  
  // Clear drawing area
  arduboy.clearDisplay();
  
  // Draw tunnel using LUTs
  for(byte dy = 0; dy < 64; dy++) {
    word yterm = (63 - (cy < dy ? dy - cy : cy - dy));
    for(byte dx = 0; dx < 128; dx++) {
      word xterm = (127 - (cx < dx ? dx - cx : cx - dx));
      word zterm = 128 * yterm + xterm;
      // Fetch polar coordinates from LUT
      byte ty = pgm_read_byte(&y_lut[zterm]);
      if(ty != 0) { // Distance shadow mask
        byte tx = pgm_read_byte(&x_lut[zterm]);
        if(cy < dy != cx < dx) tx = 255 - tx;
        tx = (tx >> 2) + (((cy < dy ? 2 : 0) + (cx < dx != cy < dy ? 1 : 0)) << 6);
        // Scale and animate
        tx = (tx + ((ty * twist) >> 8) + ix) >> 4; // With twist
        //tx = (tx + ix) >> 4; // Without twist
        ty = (ty + ix) >> 4;
        arduboy.drawPixel(dx, dy, (tx ^ ty) & 1);
      }
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
