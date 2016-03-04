#ifndef __EEPROM_CLASS__
#define __EEPROM_CLASS__
#include <stdint.h>
class EEPROMClass {
  public:
    uint8_t read(uint16_t address);
    void write(uint16_t address, uint8_t value);
};
extern EEPROMClass EEPROM;
#endif//__EEPROM_CLASS__