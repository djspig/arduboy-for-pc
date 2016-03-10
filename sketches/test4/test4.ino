#include "Arglib.h"
#include "resource.h"

Arduboy arduboy;

void setup() {
  
}


int hx, hy;
int cx, cy;
int sx, sy;


unsigned ix;
void loop() {
#ifdef __MINGW32__
  delay(10);
#endif
  ix++;

  sx = sin((float)ix / 113) * 64;
  sy = cos((float)ix / 67) * 32;

  int wx = sx + cx - 7;
  int wy = sy + cy;

  hx += (sx * 32 - hx) / 64;
  hy += (sy * 32 - hy) / 64;
  
  cx = (-hx / 32) + 64;
  cy = (-hy / 32) + 32;
  
  arduboy.clearDisplay();
  for(byte dy = 0; dy < 64; dy++) {
    word yterm = (63 - (cy < dy ? dy - cy : cy - dy));
    for(byte dx = 0; dx < 128; dx++) {
      word xterm = (127 - (cx < dx ? dx - cx : cx - dx));
      word zterm = 128 * yterm + xterm;
      byte tx = pgm_read_byte(&x_lut[zterm]);
      byte ty = pgm_read_byte(&y_lut[zterm]);
      if(ty != 0) {
        if(cy < dy != cx < dx) tx = 255 - tx;
        tx = (tx >> 2) + (((cy < dy ? 2 : 0) + (cx < dx != cy < dy ? 1 : 0)) << 6);
        // Scale and animate
        tx = (tx + ix) >> 4;
        ty = (ty + ix) >> 4;
        arduboy.drawPixel(dx, dy, (tx ^ ty) & 1);
      }
    }
  }
  
  arduboy.drawSprite(wx, wy, ship, 16, 16, 0, BLACK);
  arduboy.drawSprite(wx, wy, ship, 16, 16, 1, WHITE);
  if(millis() & 64) arduboy.drawSprite(wx, wy, ship, 16, 16, 2, WHITE);
  arduboy.display();

}
