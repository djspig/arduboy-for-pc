#include "bitmaps.h"

void drawBackground(unsigned posX, unsigned posY) {
  word intX = posX >> 3, subX = posX & 0x07;
  word intY = posY >> 3, subY = posY & 0x07;
  word ackY = intY;
  for(byte y = 0; y < (subY ?  72 :  64); y += 8, ackY++) {
    byte msiY = (ackY & 0xF8) >> 1;
    byte lsiY = (ackY & 0x07) << 4;
    word ackX = intX;
    for(byte x = 0; x < (subX ? 136 : 128); x += 8, ackX++) {
      arduboy.drawSprite(
        x - subX, y - subY,
        tilesheet_bitmap, 8, 8,
        pgm_read_byte(&tilemaps[(ackX >> 4) + msiY][(ackX & 0x0F) + lsiY]),
        1
      );
    }
  }
}

void setup() {
}

void loop() {
  static float a = 0.0;
  a += 0.001;
  drawBackground(256 + sin(a) * 128, 128 + cos(a) * 64);
}