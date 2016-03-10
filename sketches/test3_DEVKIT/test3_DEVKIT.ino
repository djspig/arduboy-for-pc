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


// Wrapping texture sampler
byte readtex(unsigned x, unsigned y) {
  // 7's are texture width - 1, height - 1, sizes must be power of two
  x &= (TEX_W-1); y &= (TEX_H-1);
  return (pgm_read_byte(&smiley[x + (y >> 3) * TEX_W]) >> (y & 7)) & 1;
}

// Fast fixed point atn2 approximation, returns 0-1602 (0 and 2PI in Q8 format)
int16_t fp_atn2(int16_t y, int16_t x) {
   int16_t abs_y = abs(y);
   int16_t r = x >= 0 ? ((x - abs_y) << 8) / (x + abs_y) : ((x + abs_y) << 8) / (abs_y - x);
   int16_t a = x >= 0 ? fppi25 - ((fppi25 * r) >> 8) : fppi75 - ((fppi25 * r) >> 8);
   return (y < 0 ? -a : a) + 798;
}

// Fast integer square root
uint8_t i_sqrt(uint16_t val) {
  uint8_t root = 0, temp = 32;
  while(temp) {
    if(((root + temp) * (root + temp)) <= val) root += temp;
    temp = temp >> 1;
  }
  return root; 
}

byte half[128*32/8]; // Half screen buffer

byte ix; // Indexer for motion

void loop() {
#ifdef __MINGW32__
  delay(40);
#endif
  ix++; // TODO: correction on roll over 255 => ? (where ? is currently 0)
  byte *p_half = half;
  SPI.setBitOrder(LSBFIRST);
  for(byte y = 0; y < 32; y += 8) {
    for (byte x = 0; x < 128; x++) {
      int8_t xs = x - 64;
      int8_t ys = y - 32;
      byte cell = 0;
      for(byte z = 0; z < 8; z++, ys++) {
        cell <<= 1;
        // Mask out centre + avoid divide by zero
        if(xs < -10 || xs > 10 || ys < -10 || ys > 10) {
          // Calculate distance from centre, perspective correction costs one division
          byte dst = SCALE_Y / i_sqrt(xs * xs + ys * ys);
          // Mask out centre and apply shadow on far region
          if(dst <= 60 && (dst < 25 || (1 & (xs ^ ys)))) {
            // Animate Y
            byte tex_y = (dst + ix) >> 2;
            // Animate X, calculate angle
            byte tex_x = ((fp_atn2(ys, xs) + ix) * TEX_W * SCALE_X) / 1602;
            // Calculate pixel color
            //bool pixel = readtex(tex_x, tex_y); // USE TEXTURE
            bool pixel = 1 & (tex_x ^ tex_y);   // USE CHECKERS
            cell |= pixel;
          }
        }
      }
      SPI.transfer(*p_half++ = cell);
    }
  }
  SPI.setBitOrder(MSBFIRST);
  for(word n = 0; n != 512; n++) SPI.transfer(*--p_half);
}
/* ========================================================== */
