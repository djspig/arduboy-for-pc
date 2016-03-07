#include "Arglib.h"
#include "resource.h"

Arduboy arduboy;

/* == WARNING - CODE PUT HERE BY JO3RI ... SO THIS CAN'T BE CORRECT ! == */


void setup() {
}

void loop() {

  arduboy.clearDisplay();
  for (double x = 0; x < 128; x++)
  {
    for (double y = 0; y < 64; y++)
    {
      int xs = x - 64;
      int ys = y - 32;
      int tex_x = atan2(x/y,y);
      int tex_y = sqrt(x * x + y * y);
      byte pixel = readtex(tex_x, tex_y);
      arduboy.drawPixel(x, y, pixel);
    }
  }
  arduboy.display();
}
/* ========================================================== */
