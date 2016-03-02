#include "bitmaps.h"

void drawBackground(unsigned posX, unsigned posY) {
  unsigned int intX = posX >> 3, subX = posX & 0x07;
  unsigned int intY = posY >> 3, subY = posY & 0x07;
  for(byte y = 0; y < (subY ?  9 :  8); y++) {
    for(byte x = 0; x < (subX ? 17 : 16); x++) {
      arduboy.drawSprite(
        ((int)x << 3) - subX,
        ((int)y << 3) - subY,
        tilesheet_bitmap, 8, 8,
        pgm_read_byte(&tilemaps[(((intX + x) >> 3) + ((intY + y) & 0xF8)) >> 1][((intX + x) & 0x0F) + (((intY + y) & 0x07) << 4)]),
        WHITE
      );
    }
  }
}

void setup() {
}

void loop() {
  static float a = 0.0;
  a += 0.001;
  drawBackground(256 + sin(a) * 120, 128 + cos(a) * 60);
}