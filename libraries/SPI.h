#ifndef __SPI_CLASS__
#define __SPI_CLASS__
#include <stdint.h>

class SPIClass {
  public:
    uint8_t begin();
    uint8_t transfer(uint8_t value);
};

extern SPIClass SPI;
#endif//__SPI_CLASS__
