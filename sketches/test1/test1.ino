#include "Arglib.h"
#include "bitmaps.h"

Arduboy arduboy;

enum {
  LADDER = 1,
  SECRET = 2,
  
  WALL = 0x80
};

// Read brick type
byte readType(int x, int y) {
  x = (x < 0 ? 0 : (x > 511) ? 511 : x); // Limit X
  y = (y < 0 ? 0 : (y > 511) ? 511 : y); // Limit Y
  byte data = pgm_read_byte(&tilemaps[((x >> 3) + (y & 0xF8)) >> 1][(x & 0x0F) + ((y & 0x07) << 4)]);
  // ------------------------
  return data;
}

// Calculate tile type based on neighboring cells
byte tileType(int x, int y) {
  byte left, over, me = readType(x, y);
  byte wall = me & WALL;
  byte item = me & ~WALL;
  
  if(LADDER == item) {
    // Ladder
    left = x > 0 ? readType(x - 1, y) & 0x7F : 0;
    return (LADDER == left) ? 14 : 13;
  } else if(SECRET == item) {
    // Secret passage
    wall = true;
  }

  if(wall) {
    // Wall
    over = readType(x, y - 1) & WALL;
    return (over ? 15 : 19) + (x & 1) + ((y & 1) << 1);
  } else {
    // Background
    left = readType(x - 1, y) & WALL;
    over = readType(x, y - 1) & WALL;
    return (left & over) ? 0 : ((left ? 5 : over ? 9 : 1) + (x & 1) + ((y & 1) << 1));
  }
}

void drawBackground(unsigned posX, unsigned posY) {
  word intX = posX >> 3, subX = posX & 0x07;
  word intY = posY >> 3, subY = posY & 0x07;
  word ackY = intY;
  for(byte y = 0; y < (subY ?  72 :  64); y += 8, ackY++) {
    word ackX = intX;
    for(byte x = 0; x < (subX ? 136 : 128); x += 8, ackX++) {
      arduboy.drawSprite(
        x - subX, y - subY,
        tilesheet_bitmap, 8, 8,
        tileType(ackX, ackY),
        WHITE
      );
    }
  }
}

void drawBackground_old_data(unsigned posX, unsigned posY) {
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
  arduboy.clearDisplay();
  drawBackground(192 + sin(a * 0.6) * 192, 96 + cos(a * 1.9) * 96);
  arduboy.display();
}