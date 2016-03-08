#include "Arglib.h"
#include "resource.h"

Arduboy arduboy;

point {
  x, y
}

points[]

line {
  a,b
}

starty[] {
  y,
  xlist[] {
    x, slope, count
  }
}


/* == WARNING - VERY INEFFICIENT CODE - NEEDS OPTIMIZATION == */
byte tileBit(int x, int y) {
  x = x < 0 ? 0 : x > 511 ? 511 : x;
  y = y < 0 ? 0 : y > 511 ? 511 : y;
  return (pgm_read_byte(&level[y * 4 + x / 8]) >> (x & 7)) & 0x01;
}

byte tileIndex(int x, int y) {
  if(!tileBit(x, y)) return 16;
  return tileBit(x, y - 1) | (tileBit(x - 1, y) << 1) | (tileBit(x + 1, y) << 2) | (tileBit(x, y + 1) << 3);
}

void drawBackground(unsigned posX, unsigned posY) {
  word intX = posX >> 4, subX = posX & 0x0F;
  word intY = posY >> 4, subY = posY & 0x0F;
  word ackY = intY;
  for(byte y = 0; y < (subY ?  72 :  64); y += 16, ackY++) {
    word ackX = intX;
    for(byte x = 0; x < (subX ? 136 : 128); x += 16, ackX++) {
      arduboy.drawSprite(
        x - subX, y - subY,
        tiles, 16, 16,
        tileIndex(ackX, ackY),
        WHITE
      );
    }
  }
}
/* ========================================================== */

void setup() {
}

void loop() {
  static float a = 0.0;
  a = (float)millis() / 1500.0;
  arduboy.clearDisplay();
  drawBackground(192 + sin(a) * (192 - 48), 224 + cos(a * 1.2) * (224 - 64));
  arduboy.display();
}
