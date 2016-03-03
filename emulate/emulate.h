#ifndef __ARDUBOY_EMULATE_H__
#define __ARDUBOY_EMULATE_H__
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#include "sdl.h"

/* EMULATION SHEITE */
#define PROGMEM
#define B00000000 0
#define B00000001 1
#define B00000010 2
#define B00000100 4
#define B00001000 8
#define B00010000 16
#define B00100000 32
#define B01000000 64
#define B10000000 128
#define B11110000 0xF0

#define SLEEP_MODE_IDLE 0

#define _BV(N) (1 << (N))

typedef uint8_t byte;
typedef uint16_t word;

/* == WMATH ====================== */

void randomSeed(unsigned long seed);
long random(long howbig);
long random(long howsmall, long howbig);
long map(long x, long in_min, long in_max, long out_min, long out_max);

unsigned int makeWord(unsigned int w);
unsigned int makeWord(unsigned char h, unsigned char l);

/* =============================== */

/* Arduino */

void delay(unsigned int ms);
uint32_t millis();
void arduboy_spi(byte c8);
void set_sleep_mode(byte mode);
void sleep_mode();
void drawSprite(int x, int y, const byte *sheet, byte w, byte h, byte index, byte color);

/*
static struct {
  void(*drawSprite)(int, int, const byte *, byte, byte, byte, byte);
} arduboy = {&drawSprite};
*/

static inline byte pgm_read_byte(const byte *wat) {
  return *wat;
}

static class {
  public:
    byte read(uint16_t address) {
      byte value;
      FILE *f = fopen("eeprom.bin", "rb");
      if(!f) return 0xFF;
      fseek(f, address, SEEK_SET);
      fread(&value, 1, 1, f);
      fclose(f);
      return value;
    }
    void write(uint16_t address, byte value) {
      FILE *f = fopen("eeprom.bin", "wb");
      if(!f) return;
      fseek(f, address, SEEK_SET);
      fwrite(&value, 1, 1, f);
      fclose(f);
    }
} EEPROM;

/* END OF SAID SHEITE */
#endif//__ARDUBOY_EMULATE_H__