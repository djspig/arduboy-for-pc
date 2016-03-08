#ifndef __SPI_CLASS__
#define __SPI_CLASS__
#include <stdint.h>
#include <emulate.h>


#define MSBFIRST 1
#define LSBFIRST 0

static __attribute__((always_inline)) inline
uint8_t rbit(uint8_t x) {
  x = (((x & 0xaa) >> 1) | ((x & 0x55) << 1));
  x = (((x & 0xcc) >> 2) | ((x & 0x33) << 2));
  x = (((x & 0xf0) >> 4) | ((x & 0x0f) << 4));
  return x;
}

class SPIClass {
  private:
    uint8_t order = LSBFIRST;
  public:
    uint8_t begin();
    uint8_t inline transfer(uint8_t value) {
      if(order == MSBFIRST) value = rbit(value);
      arduboy_spi(value);
    };
    uint8_t inline setBitOrder(uint8_t order) {
      this->order = order;
    };
};

extern SPIClass SPI;
#endif//__SPI_CLASS__
