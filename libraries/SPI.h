#ifndef __SPI_CLASS__
#define __SPI_CLASS__
#include <stdint.h>
#include <emulate.h>


class SPIClass {
  public:
    uint8_t begin();
    uint8_t inline transfer(uint8_t value) {
      arduboy_spi(value);
    };
};

extern SPIClass SPI;
#endif//__SPI_CLASS__
