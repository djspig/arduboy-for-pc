#include "Arglib.h"
#include "resource.h"

Arduboy arduboy;

/* == WARNING - CODE PUT HERE BY JO3RI ... SO THIS CAN'T BE CORRECT ! == */

#define TEX_W 8
#define TEX_H 8
#define SCALE_X 2
#define SCALE_Y 800

const int32_t fppi25 = 201;
const int32_t fppi75 = 603;

void setup() {
  arduboy.start();
}

// Sample texture
byte readtex(unsigned x, unsigned y) {
  // 7's are texture width - 1, height - 1, sizes must be power of two
  x &= (TEX_W-1); y &= (TEX_H-1);
  return (pgm_read_byte(&smiley[x + (y >> 3) * TEX_W]) >> (y & 7)) & 1;
}

// Fast fixed point atn2 approximation, returns 0-1602 (0 and 2PI in Q8 format)
int32_t fp_atn2(int32_t y, int32_t x) {
   int32_t abs_y = abs(y);
   int32_t r = x >= 0 ? ((x - abs_y) << 8) / (x + abs_y) : ((x + abs_y) << 8) / (abs_y - x);
   int32_t a = x >= 0 ? fppi25 - ((fppi25 * r) >> 8) : fppi75 - ((fppi25 * r) >> 8);
   return (y < 0 ? -a : a) + 798;
}

// Indexer for motion
int ix;

void loop() {
  delay(40);
  ix += 2;
  
  arduboy.clearDisplay();
  for (int x = 0; x < 128; x++) {
    for (int y = 0; y < 64; y++) {
      int xs = x - 64;
      int ys = y - 32;
      // avoid divide by zero
      if(xs == 0 && ys == 0) continue;
      // can be further optimized
      int tex_x = ((fp_atn2(ys, xs) + ix) * TEX_W * SCALE_X) / 1602;
      // sqrt needs to be optimized, possibly also division if possible
      int tex_y = (int)((SCALE_Y / sqrt(xs * xs + ys * ys))) + ix;
      // transfer pixel from texture
      byte pixel = readtex(tex_x, tex_y >> 2);
      arduboy.drawPixel(x, y, pixel);
    }
  }
  arduboy.display();
  
}
/* ========================================================== */
