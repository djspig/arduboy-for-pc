// D. TAYLOR 2012
#ifndef __SDLSTUFF_H__
#define __SDLSTUFF_H__

#include <SDL/SDL.h>
#ifdef __WIN32__
#include <Windows.h>
#endif
#include <stdbool.h>
#include <math.h>

void setup();
void loop();

typedef int32_t samp32bit;

void audio(samp32bit recv[][2], samp32bit send[][2], int nsamples);

// Audio output must me generated here
void sdl_audio(void *udata, Uint8 *stream, int len);

void arduboy_pixel( short x, short y, bool white );
void arduboy_color( short x, short y, uint8_t white );

byte arduboy_buttons();

void sdl_beep(uint8_t channel, unsigned int frequency, unsigned long duration);

void sdl_draw_begin(bool clear);
void sdl_draw_end();

#endif
