#include "Arglib.h"
#include "resource.h"

Arduboy arduboy;

/* == WARNING - CODE PUT HERE BY JO3RI ... SO THIS CAN'T BE CORRECT ! == */



const int32_t fppi25 = 201;
const int32_t fppi75 = 603;

void setup() {
  arduboy.start();
  arduboy.setFrameRate(60);
}

byte readtex(unsigned x, unsigned y) {
  x &=7; y &= 7;
  return (smiley[x + (y >> 3)] >> (y & 7)) & 1;
}

int32_t fp_atn2(int32_t y, int32_t x) {
   int32_t abs_y = abs(y);
   int32_t r = x >= 0 ? ((x - abs_y) << 8) / (x + abs_y) : ((x + abs_y) << 8) / (abs_y - x);
   int32_t a = x >= 0 ? fppi25 - ((fppi25 * r) >> 8) : fppi75 - ((fppi25 * r) >> 8);
   return y < 0 ? -a : a;
}

int ix;

void loop() {
  delay(10);
  ix++;
  arduboy.clearDisplay();
  for (int x = 0; x < 128; x++) {
    for (int y = 0; y < 64; y++) {
      int xs = x - 64;
      int ys = y - 32;
      if(xs == 0 && ys == 0) continue;
      int tex_x = ((fp_atn2(ys, xs) + ix) * 16) / 1608;
      int tex_y = ((100 / sqrt(xs * xs + ys * ys)) * 8) + ix;
            
      byte pixel = readtex(tex_x, tex_y >> 2);
      arduboy.drawPixel(x, y, pixel);
    }
  }
  arduboy.display();
}
/* ========================================================== */
