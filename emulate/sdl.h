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

uint8_t drawr = 0;
uint8_t drawg = 0;
uint8_t drawb = 0;

bool clip = true;

// wrapper for uDAD audio call, 32-bit data
void sdl_audio(void *udata, Uint8 *stream, int len) {
  //int16_t *stream16 = (int16_t*)stream;
  //samp32bit *recv = malloc(len*2), *send=malloc(len*2);
  //audio((samp32bit (*)[2])recv, (samp32bit (*)[2])send, len >> 2);
  //unsigned n;
  //for(n = 0; n < len >> 1; n++) *stream16++ = send[n] >> 16;
  //free(recv);
  //free(send);
}

// Rendering stuff
static void draw_line( double x0, double y0, double x1, double y1 );
static void draw_pixel( short x, short y, Uint8 a );

SDL_Surface *screen;
SDL_Rect rect = {0, 0, 640, 480};

#define ARDUBOY_ENHANCE 2  // ENHANCE!!!

// Draws an alpha-blended pixel, used by draw_line
static void arduboy_pixel( short x, short y, bool white ) {
  SDL_Rect pixel = {
    ((rect.w / 2) - ((64 - x) << ARDUBOY_ENHANCE)),
    ((rect.h / 3) - ((32 - y) << ARDUBOY_ENHANCE)),
    1 << ARDUBOY_ENHANCE,
    1 << ARDUBOY_ENHANCE
  };
  
  uint32_t color;
  
  if(x < 0 || x > 127 || y < 0 || y > 63) {
    color = clip ? 0xFFFFFF : (white ? 0xF0F0F0 : 0xC0C0C0);
  } else {
    color = white ? 0xFFFFFF : 0x000000;
  }
  
  SDL_FillRect(screen, &pixel, color);
}

static void arduboy_frame() {
  SDL_Rect frame = {
    ((rect.w / 2) - (64 << ARDUBOY_ENHANCE)) - 1,
    ((rect.h / 3) - (32 << ARDUBOY_ENHANCE)) - 1,
    (128 << ARDUBOY_ENHANCE) + 1,
    ( 64 << ARDUBOY_ENHANCE) + 1
  };
  draw_line(frame.x, frame.y, frame.x + frame.w, frame.y);
  draw_line(frame.x + frame.w, frame.y, frame.x + frame.w, frame.y + frame.h);
  draw_line(frame.x + frame.w, frame.y + frame.h, frame.x, frame.y + frame.h);
  draw_line(frame.x, frame.y + frame.h, frame.x, frame.y);
}

void draw_begin(bool clear) {
  if(SDL_MUSTLOCK(screen)) if(SDL_LockSurface(screen) < 0) exit(1);
  if(clear) SDL_FillRect(screen, &rect, 0xFFFFFF); // Clear screen
}

void draw_end() {
  arduboy_frame();
  if(SDL_MUSTLOCK(screen)) SDL_UnlockSurface(screen);
  SDL_Flip(screen); 
}

int main(int argc, char* argv[]) {
  SDL_Event e;


  if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) return 1;

  //
  SDL_WM_SetCaption("Let's play Arduboy!", "");
  
  if (!(screen = SDL_SetVideoMode(rect.w, rect.h, 32, SDL_SWSURFACE))) {
    SDL_Quit();
    return 1;
  }

  SDL_AudioSpec fmt;

  // Audio format
  fmt.freq     = 48000;
  fmt.format   = AUDIO_S16;
  fmt.channels = 2;
  fmt.samples  = 1024;
  fmt.callback = sdl_audio;
  fmt.userdata = NULL;

  // Open the audio device
  if ( SDL_OpenAudio(&fmt, NULL) < 0 ) {
    SDL_Quit();
    return 2;
  }

  setup();

  // Start playback
  SDL_PauseAudio(0);
  
  while(1) {
    draw_begin(true); // Start drawing
    loop();
    draw_end();
    // Watch out for quitosaurus rex
    if(SDL_PollEvent(&e))
      if(e.type == SDL_KEYDOWN) {
        if(e.key.keysym.sym == SDLK_ESCAPE) break;
        if(e.key.keysym.sym == SDLK_c) clip = !clip;
        //if(e.key.keysym.sym == SDLK_SPACE) string_pluck();
        //if(e.key.keysym.sym == 'r') string_init();
      }
  } 

  SDL_Quit();
  return 0;
}


// ** HELPER STUFF BELOW ********************************************
#ifdef __WIN32__
PCHAR* CommandLineToArgvA( PCHAR CmdLine, int* _argc ) {
  PCHAR *argv;
  PCHAR _argv;
  ULONG len;
  CHAR   a;
  ULONG i, j;
  ULONG argc = 0;

  BOOLEAN in_QM = FALSE;
  BOOLEAN in_TEXT = FALSE;
  BOOLEAN in_SPACE = TRUE;

  len = strlen( CmdLine );
  i = ( ( len + 2 ) / 2 ) * sizeof( PVOID ) + sizeof( PVOID );

  argv = ( PCHAR* )malloc( i + ( len + 2 ) * sizeof( CHAR ) );
  _argv = ( PCHAR )( ( ( PUCHAR ) argv ) + i );
  argv[ 0 ] = _argv;

  i = 0;
  j = 0;

  while( (a = CmdLine[i]) ) {
    if( in_QM ) {
      if( a == '\"' ) {
        in_QM = FALSE;
      } else {
        _argv[ j ] = a;
        j++;
      }
    } else {
      switch( a ) {
        case '\"':
          in_QM = TRUE;
          in_TEXT = TRUE;
          if( in_SPACE ) {
              argv[ argc ] = _argv + j;
              argc++;
          }
          in_SPACE = FALSE;
          break;
        case ' ':
        case '\t':
        case '\n':
        case '\r':
          if( in_TEXT ) {
            _argv[ j ] = '\0';
            j++;
          }
          in_TEXT = FALSE;
          in_SPACE = TRUE;
          break;
        default:
          in_TEXT = TRUE;
          if( in_SPACE ) {
              argv[ argc ] = _argv + j;
              argc++;
          }
          _argv[ j ] = a;
          j++;
          in_SPACE = FALSE;
          break;
      }
    }
    i++;
  }
  _argv[ j ] = '\0';
  argv[ argc ] = NULL;

  *_argc = argc;
  return( argv );
}

int CALLBACK WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ) {
  LPSTR *argv;
  int argc;
  int ret;
  LPSTR lpCmdLine2;
  
  lpCmdLine2 = malloc( strlen( lpCmdLine ) + 5 );
  strcpy( lpCmdLine2, "me " );
  strcat( lpCmdLine2, lpCmdLine );

  argv = CommandLineToArgvA( lpCmdLine2, &argc );
  if ( argv == NULL ) {
    printf( "Console [error]: Command line parsing failed\n" );
    return( 5 );
  }
  
  ret = main( argc, argv );

  free( lpCmdLine2 );
  free( argv );
  return( ret );
}

#endif


// Draws an alpha-blended pixel, used by draw_line
static void draw_pixel( short x, short y, Uint8 a ) {
  Uint8 cr, cg, cb;
  Uint32 cv;
  if( y < 0 || y >= rect.h || x < 0 || x >= rect.w ) return;
  a = 255-a;
  cv = ( *( Uint32* )( ( ( uint8_t* )screen->pixels ) + ( y * screen->pitch + x * 4 ) ) );

  SDL_GetRGB( cv, screen->format, &cr, &cg, &cb );
  cr = ( ( ( int )cr * a ) + ( ( int )drawr * ( 255 - a ) ) ) >> 8;
  cg = ( ( ( int )cg * a ) + ( ( int )drawg * ( 255 - a ) ) ) >> 8;
  cb = ( ( ( int )cb * a ) + ( ( int )drawb * ( 255 - a ) ) ) >> 8;
  cv = SDL_MapRGB( screen->format, cr, cg, cb );

  ( *( Uint32* )( ( ( uint8_t* )screen->pixels ) + ( y * screen->pitch + x * 4 ) ) ) = cv;
}

static void swap(double *a, double *b) {
  double c = *a;
  *a = *b;
  *b = c;
}

static inline double fpart(double d) {
  return d - floor(d);
}

static inline double rfpart(double d) {
  return 1.0 - (d - floor(d));
}

static void draw_line(double x1, double y1, double x2, double y2) {
   bool vertical = abs(y2 - y1) > abs(x2 - x1);
   if (vertical) {
       swap(&x1, &y1);
       swap(&x2, &y2);
   }
   if (x2 < x1) {
       swap (&x1, &x2);
       swap (&y1, &y2);
   }
   double gradient = ((y2 - y1) / (x2 - x1));
   int xend = round(x1);
   double yend = y1 + gradient * (xend - x1);
   double xgap = rfpart(x1);
   int xpxl1 = xend;
   int ypxl1 = floor(yend);
   if(vertical) {
       draw_pixel(ypxl1,     xpxl1, 255 * (rfpart(yend) * xgap));
       draw_pixel(ypxl1 + 1, xpxl1, 255 * ( fpart(yend) * xgap));
   } else {
       draw_pixel(xpxl1, ypxl1,    255 * (rfpart(yend) * xgap));
       draw_pixel(xpxl1, ypxl1 + 1, 255 * ( fpart(yend) * xgap));
   }
   uint32_t intery = (yend + gradient) * 65536;
   xend = round(x2);
   yend = y2 + gradient * (xend - x2);
   xgap = fpart(x2 + 1);
   int xpxl2 = xend;
   int ypxl2 = floor(yend);
   if(vertical) {
       draw_pixel(ypxl2,     xpxl2, 255 * (rfpart(yend) * xgap));
       draw_pixel(ypxl2 + 1, xpxl2, 255 * ( fpart(yend) * xgap));
   } else {
       draw_pixel(xpxl2, ypxl2,    255 * (rfpart(yend) * xgap));
       draw_pixel(xpxl2, ypxl2 + 1, 255 * ( fpart(yend) * xgap));
   }
   uint16_t i;
   uint32_t fixp_gradient = gradient * 65536;
   for(i = xpxl1 + 1; i <= xpxl2 - 1; i++) {
     if(vertical) {
       draw_pixel((intery >> 16),    i, ~(intery >> 8));
       draw_pixel((intery >> 16) + 1, i,  (intery >> 8));
     } else {
       draw_pixel(i, (intery >> 16),     ~(intery >> 8));
       draw_pixel(i, (intery >> 16) + 1,  (intery >> 8));
     }
     intery += fixp_gradient;
    }
}

#endif
