#include <EEPROM.h>
#include <stdio.h>
EEPROMClass EEPROM;

uint8_t EEPROMClass::read(uint16_t address) {
  uint8_t value;
  FILE *f = fopen("eeprom.bin", "rb");
  if(!f) return 0xFF;
  fseek(f, address, SEEK_SET);
  fread(&value, 1, 1, f);
  fclose(f);
  return value;
}

void EEPROMClass::write(uint16_t address, uint8_t value) {
  FILE *f = fopen("eeprom.bin", "wb");
  if(!f) return;
  fseek(f, address, SEEK_SET);
  fwrite(&value, 1, 1, f);
  fclose(f);
}
