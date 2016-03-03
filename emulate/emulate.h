#include <stdio.h>
#include "sdl.h"

/* EMULATION SHEITE */
#define PROGMEM
#define WHITE 0
typedef uint8_t byte;
typedef uint16_t word;

void drawSprite(int x, int y, const byte *sheet, byte w, byte h, byte index, byte color) {
  short base = (unsigned)index * ((w * h) >> 3);
  for(byte u = 0; u < w; u++) {
    for(byte v = 0; v < h; v++) {
      arduboy_pixel(x + u, y + v, (sheet[base + u + (v >> 3) * w] >> (v & 7)) & 1);
    }
  }
  
  //printf("%i,%i\n",x,y);
  //arduboy_pixel(x, y, 0);
}

struct {
  void(*drawSprite)(int, int, const byte *, byte, byte, byte, byte);
} arduboy = {&drawSprite};

byte pgm_read_byte(const byte *wat) {
  return *wat;
}

/* END OF SAID SHEITE */
