#ifndef BITMAPS_H
#define BITMAPS_H

PROGMEM const unsigned char player_plus_mask[] = {
  // width, height
  16, 16,
  // frame 0
  0x0E, 0x1F, 0x07, 0x1F, 0x0F, 0x7F, 0x3A, 0xFF, 0xBC, 0xFE, 0x3E, 0xFF, 0xDE, 0xFF, 0xCE, 0xFF,
  0xBE, 0xFF, 0xBE, 0xFF, 0x3E, 0xFF, 0xBC, 0xFE, 0x3A, 0xFF, 0x0F, 0x7F, 0x07, 0x1F, 0x0E, 0x1F,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0D, 0x1F, 0x1A, 0x7F, 0x53, 0xFF, 0x13, 0xFF,
  0x6B, 0xFF, 0xBB, 0xFF, 0xBA, 0xFF, 0x75, 0xFF, 0x18, 0x7F, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00,

  // frame 1
  0x1E, 0x3F, 0x0F, 0x1F, 0x07, 0x3F, 0x1D, 0xFF, 0xDE, 0xFF, 0x1F, 0xFF, 0xEF, 0xFF, 0xE7, 0xFF,
  0xDF, 0xFF, 0xDF, 0xFF, 0x1F, 0xFF, 0xDE, 0xFF, 0x1D, 0xFF, 0x07, 0x3F, 0x0F, 0x1F, 0x1E, 0x3F,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x37, 0x36, 0x7F, 0x6D, 0xFF, 0x69, 0xFF, 0x09, 0xFF,
  0x35, 0xFF, 0x5D, 0xFF, 0x5D, 0xFF, 0x3A, 0x7F, 0x0C, 0x3F, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00,

  // frame 2
  0x0E, 0x1F, 0x07, 0x1F, 0x0F, 0x7F, 0x3A, 0xFF, 0xBC, 0xFE, 0x3E, 0xFF, 0xDE, 0xFF, 0xCE, 0xFF,
  0xBE, 0xFF, 0xBE, 0xFF, 0x3E, 0xFF, 0xBC, 0xFE, 0x3A, 0xFF, 0x0F, 0x7F, 0x07, 0x1F, 0x0E, 0x1F,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6F, 0x6D, 0xFF, 0x5A, 0xFF, 0x13, 0x7F, 0x13, 0xFF,
  0x6B, 0xFF, 0xBB, 0xFF, 0xBA, 0xFF, 0x75, 0xFF, 0x18, 0x7F, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00,

  // frame 3
  0x1E, 0x3F, 0x0F, 0x1F, 0x07, 0x3F, 0x1D, 0xFF, 0xDE, 0xFF, 0x1F, 0xFF, 0xEF, 0xFF, 0xE7, 0xFF,
  0xDF, 0xFF, 0xDF, 0xFF, 0x1F, 0xFF, 0xDE, 0xFF, 0x1D, 0xFF, 0x07, 0x3F, 0x0F, 0x1F, 0x1E, 0x3F,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x37, 0x36, 0x7F, 0x6D, 0xFF, 0x69, 0xFF, 0x09, 0xFF,
  0x35, 0xFF, 0x5D, 0xFF, 0x5D, 0xFF, 0x3A, 0x7F, 0x0C, 0x3F, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00,

  // frame 4
  0x00, 0x00, 0x00, 0x0C, 0x0C, 0x7E, 0x3E, 0xFF, 0x3F, 0xFF, 0xCF, 0xFF, 0xDE, 0xFF, 0xBE, 0xFF,
  0x3E, 0xFF, 0xBE, 0xFF, 0xBC, 0xFE, 0x7E, 0xFF, 0x77, 0xFF, 0x0F, 0xFF, 0x07, 0x0F, 0x0E, 0x1F,
  0x00, 0x60, 0x60, 0xF0, 0x90, 0xF8, 0xB8, 0xFF, 0x7B, 0xFF, 0x13, 0xFF, 0x6B, 0xFF, 0x6B, 0xFF,
  0x2A, 0xFF, 0x33, 0x7F, 0x1D, 0x3F, 0x00, 0x1D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

  // frame 5
  0x00, 0x00, 0x00, 0x06, 0x06, 0x3F, 0x1F, 0xFF, 0x9F, 0xFF, 0xE7, 0xFF, 0xEF, 0xFF, 0xDF, 0xFF,
  0x1F, 0xFF, 0xDF, 0xFF, 0xDE, 0xFF, 0x3F, 0xFF, 0x3B, 0x7F, 0x07, 0x7F, 0x0F, 0x1F, 0x1E, 0x3F,
  0x00, 0x30, 0x30, 0x78, 0x48, 0xFC, 0x5C, 0xFF, 0x3D, 0x7F, 0x09, 0x7F, 0x15, 0x7F, 0x55, 0xFF,
  0x55, 0xFF, 0x59, 0xFF, 0x0E, 0xDF, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

  // frame 6
  0x00, 0x00, 0x00, 0x0C, 0x0C, 0x7E, 0x3E, 0xFF, 0x3F, 0xFF, 0xCF, 0xFF, 0xDE, 0xFF, 0xBE, 0xFF,
  0x3E, 0xFF, 0xBE, 0xFF, 0xBC, 0xFE, 0x7E, 0xFF, 0x77, 0xFF, 0x0F, 0xFF, 0x07, 0x0F, 0x0E, 0x1F,
  0x00, 0x60, 0x60, 0xF0, 0x90, 0xF8, 0xB8, 0xFF, 0x7B, 0xFF, 0x13, 0xFF, 0x2B, 0x7F, 0x2B, 0x7F,
  0x2A, 0x7F, 0x33, 0x7F, 0x5D, 0xFF, 0x60, 0xFD, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

  // frame 7
  0x00, 0x00, 0x00, 0x06, 0x06, 0x3F, 0x1F, 0xFF, 0x9F, 0xFF, 0xE7, 0xFF, 0xEF, 0xFF, 0xDF, 0xFF,
  0x1F, 0xFF, 0xDF, 0xFF, 0xDE, 0xFF, 0x3F, 0xFF, 0x3B, 0x7F, 0x07, 0x7F, 0x0F, 0x1F, 0x1E, 0x3F,
  0x00, 0x30, 0x30, 0x78, 0x48, 0xFC, 0x5C, 0xFF, 0x3D, 0x7F, 0x09, 0x7F, 0x15, 0x7F, 0x55, 0xFF,
  0x55, 0xFF, 0x59, 0xFF, 0x0E, 0xDF, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

  // frame 8
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x3C, 0xFE, 0xCE, 0xFF, 0x1E, 0xFF, 0xBE, 0xFF, 0xBE, 0xFF,
  0x7E, 0xFF, 0x7E, 0xFF, 0x7E, 0xFF, 0x7B, 0xFF, 0x07, 0x7F, 0x07, 0x0F, 0x03, 0x0F, 0x06, 0x0F,
  0x18, 0x3C, 0x24, 0x7E, 0x3C, 0x7E, 0x3C, 0xFF, 0x43, 0xFF, 0x6A, 0xFF, 0x2B, 0xFF, 0x33, 0x7F,
  0x1A, 0x7F, 0x4D, 0xFF, 0x00, 0xCD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

  // frame 9
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x1E, 0xFF, 0xE7, 0xFF, 0x0F, 0xFF, 0xDF, 0xFF, 0xDF, 0xFF,
  0x3F, 0xFF, 0xBF, 0xFF, 0x3E, 0xFF, 0x3B, 0x7F, 0x07, 0x3F, 0x07, 0x0F, 0x0E, 0x1F, 0x00, 0x1E,
  0x0C, 0x1E, 0x12, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x01, 0x3F, 0x15, 0x7F, 0x55, 0xFF, 0x59, 0xFF,
  0x6D, 0xFF, 0x06, 0x7F, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

  // frame 10
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x3C, 0xFE, 0xCE, 0xFF, 0x1E, 0xFF, 0xBE, 0xFF, 0xBE, 0xFF,
  0x7E, 0xFF, 0x7E, 0xFF, 0x7E, 0xFF, 0x7B, 0xFF, 0x07, 0x7F, 0x07, 0x0F, 0x03, 0x07, 0x06, 0x0F,
  0x18, 0x3C, 0x24, 0x7E, 0x3C, 0x7E, 0x3C, 0xFF, 0x43, 0xFF, 0x2A, 0x7F, 0x2B, 0x7F, 0x33, 0x7F,
  0x5A, 0xFF, 0x6D, 0xFF, 0x40, 0xED, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

  // frame 11
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x1E, 0xFF, 0xE7, 0xFF, 0x0F, 0xFF, 0xDF, 0xFF, 0xDF, 0xFF,
  0x3F, 0xFF, 0xBF, 0xFF, 0x3E, 0xFF, 0x3B, 0x7F, 0x07, 0x3F, 0x07, 0x0F, 0x0E, 0x1F, 0x00, 0x1E,
  0x0C, 0x1E, 0x12, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x01, 0x3F, 0x15, 0x7F, 0x55, 0xFF, 0x59, 0xFF,
  0x6D, 0xFF, 0x06, 0x7F, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

  // frame 12
  0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0xFC, 0xDC, 0xFE, 0x3C, 0xFE, 0x76, 0xFF, 0xEE, 0xFF,
  0xEE, 0xFF, 0xEC, 0xFE, 0xC2, 0xFF, 0xFE, 0xFF, 0xFE, 0xFF, 0x0E, 0xFF, 0x0C, 0x1E, 0x00, 0x1C,
  0x00, 0x00, 0x00, 0x0E, 0x0E, 0x1F, 0x1C, 0x3F, 0x1B, 0xFF, 0x52, 0xFF, 0x59, 0xFF, 0x04, 0x7F,
  0x15, 0x7F, 0x45, 0xFF, 0x09, 0xFF, 0x01, 0x0B, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

  // frame 13
  0x00, 0x00, 0x00, 0x00, 0x00, 0x9C, 0x1C, 0xFE, 0xEE, 0xFF, 0x1E, 0xFF, 0xB3, 0xFF, 0x6F, 0xFF,
  0xEF, 0xFF, 0xDD, 0xFF, 0xC3, 0xFF, 0xFE, 0xFF, 0x7E, 0xFF, 0x0E, 0xFF, 0x1C, 0x3E, 0x00, 0x3C,
  0x00, 0x00, 0x00, 0x07, 0x07, 0x0F, 0x0E, 0x1F, 0x0D, 0x3F, 0x29, 0x7F, 0x6C, 0xFF, 0x42, 0xFF,
  0x0A, 0xFF, 0x22, 0x7F, 0x0C, 0x3F, 0x00, 0x0F, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

  // frame 14
  0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0xFC, 0xDC, 0xFE, 0x3C, 0xFE, 0x76, 0xFF, 0xEE, 0xFF,
  0xEE, 0xFF, 0xEC, 0xFE, 0xC2, 0xFF, 0xFE, 0xFF, 0xFE, 0xFF, 0x0E, 0xFF, 0x0C, 0x1E, 0x00, 0x1C,
  0x00, 0x00, 0x00, 0x0E, 0x0E, 0x1F, 0x1C, 0x7F, 0x5B, 0xFF, 0x52, 0xFF, 0x19, 0x7F, 0x04, 0x3F,
  0x15, 0x7F, 0x65, 0xFF, 0x69, 0xFF, 0x01, 0xEB, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

  // frame 15
  0x00, 0x00, 0x00, 0x00, 0x00, 0x9C, 0x1C, 0xFE, 0xEE, 0xFF, 0x1E, 0xFF, 0xB3, 0xFF, 0x6F, 0xFF,
  0xEF, 0xFF, 0xDD, 0xFF, 0xC3, 0xFF, 0xFE, 0xFF, 0x7E, 0xFF, 0x0E, 0xFF, 0x1C, 0x3E, 0x00, 0x3C,
  0x00, 0x00, 0x00, 0x07, 0x07, 0x0F, 0x0E, 0x1F, 0x0D, 0x3F, 0x29, 0x7F, 0x6C, 0xFF, 0x42, 0xFF,
  0x0A, 0xFF, 0x22, 0x7F, 0x0C, 0x3F, 0x00, 0x0F, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

  // frame 16
  0x1C, 0x3E, 0x0E, 0x1F, 0x1E, 0xFF, 0xDE, 0xFF, 0xEC, 0xFE, 0xFE, 0xFF, 0xFE, 0xFF, 0xFE, 0xFF,
  0xFE, 0xFF, 0xFE, 0xFF, 0xFE, 0xFF, 0xEC, 0xFE, 0xDE, 0xFF, 0x1E, 0xFF, 0x0E, 0x1F, 0x1C, 0x3E,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x05, 0x0F, 0x0B, 0x3F, 0x23, 0x7F, 0x05, 0xFF, 0x65, 0xFF,
  0x65, 0xFF, 0x65, 0xFF, 0x23, 0x7F, 0x0B, 0x3F, 0x05, 0x0F, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00,

  // frame 17
  0x3C, 0x7E, 0x1E, 0x3F, 0x1E, 0xFF, 0xE6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE6, 0xFF, 0x1E, 0xFF, 0x1E, 0x3F, 0x3C, 0x7E,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x07, 0x05, 0x1F, 0x11, 0x3F, 0x2A, 0x7F, 0x0A, 0x7F,
  0x6A, 0xFF, 0x72, 0xFF, 0x31, 0x7F, 0x05, 0x3F, 0x02, 0x07, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,

  // frame 18
  0x1C, 0x3E, 0x0E, 0x1F, 0x1E, 0xFF, 0xDE, 0xFF, 0xEC, 0xFE, 0xFE, 0xFF, 0xFE, 0xFF, 0xFE, 0xFF,
  0xFE, 0xFF, 0xFE, 0xFF, 0xFE, 0xFF, 0xEC, 0xFE, 0xDE, 0xFF, 0x1E, 0xFF, 0x0E, 0x1F, 0x1C, 0x3E,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x05, 0x0F, 0x0B, 0x7F, 0x63, 0xFF, 0x65, 0xFF, 0x55, 0xFF,
  0x15, 0x7F, 0x25, 0x7F, 0x23, 0x7F, 0x0B, 0x3F, 0x05, 0x0F, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00,

  // frame 19
  0x3C, 0x7E, 0x1E, 0x3F, 0x1E, 0xFF, 0xE6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE6, 0xFF, 0x1E, 0xFF, 0x1E, 0x3F, 0x3C, 0x7E,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x07, 0x05, 0x1F, 0x11, 0x3F, 0x2A, 0x7F, 0x0A, 0x7F,
  0x6A, 0xFF, 0x72, 0xFF, 0x31, 0x7F, 0x05, 0x3F, 0x02, 0x07, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,

  // frame 20
  0x00, 0x1C, 0x0C, 0x1E, 0x0E, 0xFF, 0xFE, 0xFF, 0xFE, 0xFF, 0xC2, 0xFF, 0xEC, 0xFE, 0xEE, 0xFF,
  0xEE, 0xFF, 0x76, 0xFF, 0x3C, 0xFE, 0xDC, 0xFE, 0x38, 0xFC, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x0B, 0x09, 0xFF, 0x45, 0xFF, 0x15, 0x7F,
  0x04, 0x7F, 0x59, 0xFF, 0x52, 0xFF, 0x1B, 0xFF, 0x1C, 0x3F, 0x0E, 0x1F, 0x00, 0x0E, 0x00, 0x00,

  // frame 21
  0x00, 0x3C, 0x1C, 0x3E, 0x0E, 0xFF, 0x7E, 0xFF, 0xFE, 0xFF, 0xC3, 0xFF, 0xDD, 0xFF, 0xEF, 0xFF,
  0x6F, 0xFF, 0xB3, 0xFF, 0x1E, 0xFF, 0xEE, 0xFF, 0x1C, 0xFE, 0x00, 0x9C, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0F, 0x0C, 0x3F, 0x22, 0x7F, 0x0A, 0xFF,
  0x42, 0xFF, 0x6C, 0xFF, 0x29, 0x7F, 0x0D, 0x3F, 0x0E, 0x1F, 0x07, 0x0F, 0x00, 0x07, 0x00, 0x00,

  // frame 22
  0x00, 0x1C, 0x0C, 0x1E, 0x0E, 0xFF, 0xFE, 0xFF, 0xFE, 0xFF, 0xC2, 0xFF, 0xEC, 0xFE, 0xEE, 0xFF,
  0xEE, 0xFF, 0x76, 0xFF, 0x3C, 0xFE, 0xDC, 0xFE, 0x38, 0xFC, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0xEB, 0x69, 0xFF, 0x65, 0xFF, 0x15, 0x7F,
  0x04, 0x3F, 0x19, 0x7F, 0x52, 0xFF, 0x5B, 0xFF, 0x1C, 0x7F, 0x0E, 0x1F, 0x00, 0x0E, 0x00, 0x00,

  // frame 23
  0x00, 0x3C, 0x1C, 0x3E, 0x0E, 0xFF, 0x7E, 0xFF, 0xFE, 0xFF, 0xC3, 0xFF, 0xDD, 0xFF, 0xEF, 0xFF,
  0x6F, 0xFF, 0xB3, 0xFF, 0x1E, 0xFF, 0xEE, 0xFF, 0x1C, 0xFE, 0x00, 0x9C, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0F, 0x0C, 0x3F, 0x22, 0x7F, 0x0A, 0xFF,
  0x42, 0xFF, 0x6C, 0xFF, 0x29, 0x7F, 0x0D, 0x3F, 0x0E, 0x1F, 0x07, 0x0F, 0x00, 0x07, 0x00, 0x00,

  // frame 24
  0x06, 0x0F, 0x03, 0x0F, 0x07, 0x0F, 0x07, 0x7F, 0x7B, 0xFF, 0x7E, 0xFF, 0x7E, 0xFF, 0x7E, 0xFF,
  0xBE, 0xFF, 0xBE, 0xFF, 0x1E, 0xFF, 0xCE, 0xFF, 0x3C, 0xFE, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCD, 0x4D, 0xFF, 0x1A, 0x7F,
  0x33, 0x7F, 0x2B, 0xFF, 0x6A, 0xFF, 0x43, 0xFF, 0x3C, 0xFF, 0x3C, 0x7E, 0x24, 0x7E, 0x18, 0x3C,

  // frame 25
  0x00, 0x1E, 0x0E, 0x1F, 0x07, 0x0F, 0x07, 0x3F, 0x3B, 0x7F, 0x3E, 0xFF, 0xBF, 0xFF, 0x3F, 0xFF,
  0xDF, 0xFF, 0xDF, 0xFF, 0x0F, 0xFF, 0xE7, 0xFF, 0x1E, 0xFF, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x7F, 0x6D, 0xFF,
  0x59, 0xFF, 0x55, 0xFF, 0x15, 0x7F, 0x01, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x12, 0x3F, 0x0C, 0x1E,

  // frame 26
  0x06, 0x0F, 0x03, 0x07, 0x07, 0x0F, 0x07, 0x7F, 0x7B, 0xFF, 0x7E, 0xFF, 0x7E, 0xFF, 0x7E, 0xFF,
  0xBE, 0xFF, 0xBE, 0xFF, 0x1E, 0xFF, 0xCE, 0xFF, 0x3C, 0xFE, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x40, 0xED, 0x6D, 0xFF, 0x5A, 0xFF,
  0x33, 0x7F, 0x2B, 0x7F, 0x2A, 0x7F, 0x43, 0xFF, 0x3C, 0xFF, 0x3C, 0x7E, 0x24, 0x7E, 0x18, 0x3C,

  // frame 27
  0x00, 0x1E, 0x0E, 0x1F, 0x07, 0x0F, 0x07, 0x3F, 0x3B, 0x7F, 0x3E, 0xFF, 0xBF, 0xFF, 0x3F, 0xFF,
  0xDF, 0xFF, 0xDF, 0xFF, 0x0F, 0xFF, 0xE7, 0xFF, 0x1E, 0xFF, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x7F, 0x6D, 0xFF,
  0x59, 0xFF, 0x55, 0xFF, 0x15, 0x7F, 0x01, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x12, 0x3F, 0x0C, 0x1E,

  // frame 28
  0x0E, 0x1F, 0x07, 0x0F, 0x0F, 0xFF, 0x77, 0xFF, 0x7E, 0xFF, 0xBC, 0xFE, 0xBE, 0xFF, 0x3E, 0xFF,
  0xBE, 0xFF, 0xDE, 0xFF, 0xCF, 0xFF, 0x3F, 0xFF, 0x3E, 0xFF, 0x0C, 0x7E, 0x00, 0x0C, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1D, 0x1D, 0x3F, 0x33, 0x7F, 0x2A, 0xFF,
  0x6B, 0xFF, 0x6B, 0xFF, 0x13, 0xFF, 0x7B, 0xFF, 0xB8, 0xFF, 0x90, 0xF8, 0x60, 0xF0, 0x00, 0x60,

  // frame 29
  0x1E, 0x3F, 0x0F, 0x1F, 0x07, 0x7F, 0x3B, 0x7F, 0x3F, 0xFF, 0xDE, 0xFF, 0xDF, 0xFF, 0x1F, 0xFF,
  0xDF, 0xFF, 0xEF, 0xFF, 0xE7, 0xFF, 0x9F, 0xFF, 0x1F, 0xFF, 0x06, 0x3F, 0x00, 0x06, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x0E, 0xDF, 0x59, 0xFF, 0x55, 0xFF,
  0x55, 0xFF, 0x15, 0x7F, 0x09, 0x7F, 0x3D, 0x7F, 0x5C, 0xFF, 0x48, 0xFC, 0x30, 0x78, 0x00, 0x30,

  // frame 30
  0x0E, 0x1F, 0x07, 0x0F, 0x0F, 0xFF, 0x77, 0xFF, 0x7E, 0xFF, 0xBC, 0xFE, 0xBE, 0xFF, 0x3E, 0xFF,
  0xBE, 0xFF, 0xDE, 0xFF, 0xCF, 0xFF, 0x3F, 0xFF, 0x3E, 0xFF, 0x0C, 0x7E, 0x00, 0x0C, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0xFD, 0x5D, 0xFF, 0x33, 0x7F, 0x2A, 0x7F,
  0x2B, 0x7F, 0x2B, 0x7F, 0x13, 0xFF, 0x7B, 0xFF, 0xB8, 0xFF, 0x90, 0xF8, 0x60, 0xF0, 0x00, 0x60,

  // frame 31
  0x1E, 0x3F, 0x0F, 0x1F, 0x07, 0x7F, 0x3B, 0x7F, 0x3F, 0xFF, 0xDE, 0xFF, 0xDF, 0xFF, 0x1F, 0xFF,
  0xDF, 0xFF, 0xEF, 0xFF, 0xE7, 0xFF, 0x9F, 0xFF, 0x1F, 0xFF, 0x06, 0x3F, 0x00, 0x06, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x0E, 0xDF, 0x59, 0xFF, 0x55, 0xFF,
  0x55, 0xFF, 0x15, 0x7F, 0x09, 0x7F, 0x3D, 0x7F, 0x5C, 0xFF, 0x48, 0xFC, 0x30, 0x78, 0x00, 0x30,

};


PROGMEM const unsigned char zombie_plus_mask[] = {
  // width, height
  16, 16,
  // frame 0
  0x00, 0x00, 0x00, 0x80, 0x80, 0xC0, 0x80, 0xC0, 0x80, 0xFC, 0x3C, 0xFF, 0x67, 0xFF, 0x67, 0xFF,
  0xAF, 0xFF, 0xB9, 0xFF, 0xB9, 0xFF, 0x9F, 0xFF, 0x4B, 0xFF, 0x8C, 0xDF, 0x00, 0x8C, 0x00, 0x00,
  0x00, 0x03, 0x03, 0x07, 0x01, 0x03, 0x03, 0xBF, 0xB9, 0xFF, 0xDD, 0xFF, 0xBC, 0xFF, 0x0B, 0xBF,
  0x09, 0x1F, 0x1B, 0xBF, 0xBD, 0xFF, 0xDD, 0xFF, 0xE3, 0xFF, 0x03, 0xE7, 0x00, 0x03, 0x00, 0x00,
  // frame 1
  0x00, 0x00, 0x00, 0x80, 0x80, 0xC0, 0x80, 0xC0, 0x80, 0xFC, 0x3C, 0xFF, 0x67, 0xFF, 0x67, 0xFF,
  0xAF, 0xFF, 0xB9, 0xFF, 0xB9, 0xFF, 0x9F, 0xFF, 0x4B, 0xFF, 0x8C, 0xDF, 0x00, 0x8C, 0x00, 0x00,
  0x00, 0x03, 0x03, 0x07, 0x01, 0x03, 0x03, 0x07, 0x01, 0xBF, 0xBD, 0xFF, 0xDC, 0xFF, 0xAB, 0xFF,
  0x01, 0xBF, 0x1B, 0xBF, 0x9D, 0xFF, 0xED, 0xFF, 0xD3, 0xFF, 0x03, 0xB7, 0x00, 0x03, 0x00, 0x00,
  // frame 2
  0x00, 0x00, 0x00, 0x80, 0x80, 0xC0, 0x80, 0xC0, 0x80, 0xFC, 0xBC, 0xFF, 0x27, 0xFF, 0xA7, 0xFF,
  0xCF, 0xFF, 0xD9, 0xFF, 0xD9, 0xFF, 0x9F, 0xFF, 0xCB, 0xFF, 0x8C, 0xFF, 0x00, 0x8C, 0x00, 0x00,
  0x00, 0x03, 0x03, 0x07, 0x01, 0x03, 0x03, 0x07, 0x01, 0x1F, 0x1C, 0xBF, 0xBC, 0xFF, 0xC1, 0xFF,
  0x1C, 0xFF, 0x1D, 0xFF, 0xEC, 0xFF, 0xE0, 0xFF, 0x01, 0xE3, 0x01, 0x03, 0x00, 0x01, 0x00, 0x00,
  // frame 3
  0x00, 0x80, 0x80, 0xC0, 0xC0, 0xE0, 0xC0, 0xE0, 0xC0, 0xFC, 0x5C, 0xFF, 0x33, 0xFF, 0xB3, 0xFF,
  0xD7, 0xFF, 0xDC, 0xFF, 0xDC, 0xFF, 0x97, 0xFF, 0xDB, 0xFF, 0x9A, 0xFF, 0x00, 0x9A, 0x00, 0x00,
  0x00, 0x01, 0x01, 0x03, 0x00, 0x01, 0x01, 0x03, 0x00, 0x01, 0x00, 0x1D, 0x1C, 0xBF, 0xA1, 0xFF,
  0xDC, 0xFF, 0x1D, 0xFF, 0xEC, 0xFF, 0xE0, 0xFF, 0x01, 0xE3, 0x01, 0x03, 0x00, 0x01, 0x00, 0x00,
  // frame 4
  0x00, 0xC0, 0xC0, 0xE0, 0x60, 0xF0, 0xE0, 0xF0, 0x40, 0xFC, 0x5C, 0xFF, 0x39, 0xFF, 0xB1, 0xFF,
  0xD3, 0xFF, 0xDF, 0xFF, 0xDC, 0xFF, 0x9C, 0xFF, 0xDB, 0xFF, 0x9A, 0xFF, 0x00, 0x9A, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0D, 0x0C, 0x5F, 0x5D, 0xFF, 0x6C, 0xFF, 0x35, 0x7F,
  0x00, 0x3F, 0x1D, 0x3F, 0x1C, 0xFF, 0xEC, 0xFF, 0xE1, 0xFF, 0x01, 0xE3, 0x00, 0x01, 0x00, 0x00,
  // frame 5
  0x00, 0x80, 0x80, 0xC0, 0xC0, 0xE0, 0xC0, 0xE0, 0x80, 0xFC, 0xBC, 0xFE, 0x66, 0xFF, 0x67, 0xFF,
  0xAF, 0xFF, 0xB9, 0xFF, 0xB9, 0xFF, 0xBF, 0xFF, 0x57, 0xFF, 0x98, 0xFF, 0x00, 0x98, 0x00, 0x00,
  0x00, 0x01, 0x01, 0x03, 0x00, 0x19, 0x19, 0xBF, 0xBC, 0xFF, 0xDC, 0xFF, 0xB4, 0xFF, 0x03, 0xBF,
  0x01, 0x1F, 0x1B, 0xBF, 0xBD, 0xFF, 0xDD, 0xFF, 0xE3, 0xFF, 0x03, 0xE7, 0x00, 0x03, 0x00, 0x00,
  // frame 6
  0x00, 0x00, 0x00, 0x80, 0x80, 0xC0, 0x80, 0xC0, 0x00, 0xF0, 0x70, 0xFE, 0x9E, 0xFF, 0x9E, 0xFF,
  0x32, 0xFF, 0x72, 0xFF, 0x7E, 0xFF, 0x6E, 0xFF, 0xB6, 0xFF, 0x10, 0xBF, 0x00, 0x10, 0x00, 0x00,
  0x00, 0x03, 0x03, 0x17, 0x11, 0x3B, 0x3B, 0xFF, 0xB9, 0xFF, 0xDD, 0xFF, 0xA8, 0xFF, 0x06, 0xBF,
  0x13, 0x3F, 0x37, 0xFF, 0xBB, 0xFF, 0xDB, 0xFF, 0xE2, 0xFF, 0x03, 0xE7, 0x00, 0x03, 0x00, 0x00,
  // frame 7
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0xF0, 0x70, 0xFE, 0x9E, 0xFF, 0x9E, 0xFF,
  0x32, 0xFF, 0x72, 0xFF, 0x7E, 0xFF, 0x6E, 0xFF, 0xB6, 0xFF, 0x10, 0xBF, 0x00, 0x10, 0x00, 0x00,
  0x00, 0x06, 0x06, 0x0F, 0x03, 0x17, 0x17, 0xBF, 0xB9, 0xFF, 0xDD, 0xFF, 0xA8, 0xFF, 0x06, 0xBF,
  0x03, 0x3F, 0x37, 0xFF, 0xBB, 0xFF, 0xDB, 0xFF, 0xE2, 0xFF, 0x03, 0xE7, 0x00, 0x03, 0x00, 0x00,
  // frame 8
  0x00, 0x8C, 0x8C, 0xDF, 0x4B, 0xFF, 0x9F, 0xFF, 0xB9, 0xFF, 0xB9, 0xFF, 0xAF, 0xFF, 0x67, 0xFF,
  0x67, 0xFF, 0x3C, 0xFF, 0x80, 0xFC, 0x80, 0xC0, 0x80, 0xC0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x03, 0x03, 0xE7, 0xE3, 0xFF, 0xDD, 0xFF, 0xBD, 0xFF, 0x1B, 0xBF, 0x09, 0x1F, 0x0B, 0xBF,
  0xBC, 0xFF, 0xDD, 0xFF, 0xB9, 0xFF, 0x03, 0xBF, 0x01, 0x03, 0x03, 0x07, 0x00, 0x03, 0x00, 0x00,
  // frame 9
  0x00, 0x8C, 0x8C, 0xDF, 0x4B, 0xFF, 0x9F, 0xFF, 0xB9, 0xFF, 0xB9, 0xFF, 0xAF, 0xFF, 0x67, 0xFF,
  0x67, 0xFF, 0x3C, 0xFF, 0x80, 0xFC, 0x80, 0xC0, 0x80, 0xC0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x03, 0x03, 0xB7, 0xD3, 0xFF, 0xED, 0xFF, 0x9D, 0xFF, 0x1B, 0xBF, 0x01, 0xBF, 0xAB, 0xFF,
  0xDC, 0xFF, 0xBD, 0xFF, 0x01, 0xBF, 0x03, 0x07, 0x01, 0x03, 0x03, 0x07, 0x00, 0x03, 0x00, 0x00,
  // frame 10
  0x00, 0x8C, 0x8C, 0xFF, 0xCB, 0xFF, 0x9F, 0xFF, 0xD9, 0xFF, 0xD9, 0xFF, 0xCF, 0xFF, 0xA7, 0xFF,
  0x27, 0xFF, 0xBC, 0xFF, 0x80, 0xFC, 0x80, 0xC0, 0x80, 0xC0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x01, 0x01, 0x03, 0x01, 0xE3, 0xE0, 0xFF, 0xEC, 0xFF, 0x1D, 0xFF, 0x1C, 0xFF, 0xC1, 0xFF,
  0xBC, 0xFF, 0x1C, 0xBF, 0x01, 0x1F, 0x03, 0x07, 0x01, 0x03, 0x03, 0x07, 0x00, 0x03, 0x00, 0x00,
  // frame 11
  0x00, 0x9A, 0x9A, 0xFF, 0xDB, 0xFF, 0x97, 0xFF, 0xDC, 0xFF, 0xDC, 0xFF, 0xD7, 0xFF, 0xB3, 0xFF,
  0x33, 0xFF, 0x5C, 0xFF, 0xC0, 0xFC, 0xC0, 0xE0, 0xC0, 0xE0, 0x80, 0xC0, 0x00, 0x80, 0x00, 0x00,
  0x00, 0x01, 0x01, 0x03, 0x01, 0xE3, 0xE0, 0xFF, 0xEC, 0xFF, 0x1D, 0xFF, 0xDC, 0xFF, 0xA1, 0xFF,
  0x1C, 0xBF, 0x00, 0x1D, 0x00, 0x01, 0x01, 0x03, 0x00, 0x01, 0x01, 0x03, 0x00, 0x01, 0x00, 0x00,
  // frame 12
  0x00, 0x9A, 0x9A, 0xFF, 0xDB, 0xFF, 0x9C, 0xFF, 0xDC, 0xFF, 0xDF, 0xFF, 0xD3, 0xFF, 0xB1, 0xFF,
  0x39, 0xFF, 0x5C, 0xFF, 0x40, 0xFC, 0xE0, 0xF0, 0x60, 0xF0, 0xC0, 0xE0, 0x00, 0xC0, 0x00, 0x00,
  0x00, 0x01, 0x01, 0xE3, 0xE1, 0xFF, 0xEC, 0xFF, 0x1C, 0xFF, 0x1D, 0x3F, 0x00, 0x3F, 0x35, 0x7F,
  0x6C, 0xFF, 0x5D, 0xFF, 0x0C, 0x5F, 0x00, 0x0D, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
  // frame 13
  0x00, 0x98, 0x98, 0xFF, 0x57, 0xFF, 0xBF, 0xFF, 0xB9, 0xFF, 0xB9, 0xFF, 0xAF, 0xFF, 0x67, 0xFF,
  0x66, 0xFF, 0xBC, 0xFE, 0x80, 0xFC, 0xC0, 0xE0, 0xC0, 0xE0, 0x80, 0xC0, 0x00, 0x80, 0x00, 0x00,
  0x00, 0x03, 0x03, 0xE7, 0xE3, 0xFF, 0xDD, 0xFF, 0xBD, 0xFF, 0x1B, 0xBF, 0x01, 0x1F, 0x03, 0xBF,
  0xB4, 0xFF, 0xDC, 0xFF, 0xBC, 0xFF, 0x19, 0xBF, 0x00, 0x19, 0x01, 0x03, 0x00, 0x01, 0x00, 0x00,
  // frame 14
  0x00, 0x10, 0x10, 0xBF, 0xB6, 0xFF, 0x6E, 0xFF, 0x7E, 0xFF, 0x72, 0xFF, 0x32, 0xFF, 0x9E, 0xFF,
  0x9E, 0xFF, 0x70, 0xFE, 0x00, 0xF0, 0x80, 0xC0, 0x80, 0xC0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x03, 0x03, 0xE7, 0xE2, 0xFF, 0xDB, 0xFF, 0xBB, 0xFF, 0x37, 0xFF, 0x13, 0x3F, 0x06, 0xBF,
  0xA8, 0xFF, 0xDD, 0xFF, 0xB9, 0xFF, 0x3B, 0xFF, 0x11, 0x3B, 0x03, 0x17, 0x00, 0x03, 0x00, 0x00,
  // frame 15
  0x00, 0x10, 0x10, 0xBF, 0xB6, 0xFF, 0x6E, 0xFF, 0x7E, 0xFF, 0x72, 0xFF, 0x32, 0xFF, 0x9E, 0xFF,
  0x9E, 0xFF, 0x70, 0xFE, 0x00, 0xF0, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x03, 0x03, 0xE7, 0xE2, 0xFF, 0xDB, 0xFF, 0xBB, 0xFF, 0x37, 0xFF, 0x03, 0x3F, 0x06, 0xBF,
  0xA8, 0xFF, 0xDD, 0xFF, 0xB9, 0xFF, 0x17, 0xBF, 0x03, 0x17, 0x06, 0x0F, 0x00, 0x06, 0x00, 0x00,
};


PROGMEM const unsigned char survivor_plus_mask[] = {
  // width, height
  16, 16,
  // frame 0
  0x04, 0xCE, 0xC6, 0xEF, 0x2E, 0xFF, 0x1F, 0xFF, 0xEF, 0xFF, 0xDE, 0xFF, 0x4F, 0xFF, 0xD7, 0xFF,
  0xDE, 0xFF, 0x6F, 0xFF, 0xE7, 0xFF, 0xDE, 0xFF, 0x3C, 0xFE, 0x10, 0xFC, 0xE0, 0xF0, 0x00, 0xE0,
  0x00, 0x00, 0x00, 0x1F, 0x0D, 0x1F, 0x0C, 0x7F, 0x61, 0xFF, 0x5B, 0xFF, 0x52, 0xFF, 0xA3, 0xFF,
  0xA3, 0xFF, 0x52, 0xFF, 0x5B, 0xFF, 0x61, 0xFF, 0x0C, 0x7F, 0x0D, 0x1F, 0x00, 0x1D, 0x00, 0x01,
  // frame 1
  0x08, 0x9C, 0x8C, 0xDE, 0x5C, 0xFE, 0x3E, 0xFE, 0xDE, 0xFE, 0xBC, 0xFE, 0x9E, 0xFE, 0xAE, 0xFE,
  0xBC, 0xFE, 0xDE, 0xFE, 0xCE, 0xFE, 0xBC, 0xFE, 0x78, 0xFC, 0x20, 0xF8, 0xC0, 0xE0, 0x00, 0xC0,
  0x00, 0x01, 0x01, 0x1F, 0x0C, 0x1F, 0x0C, 0x7F, 0x63, 0xFF, 0x57, 0xFF, 0x54, 0xFF, 0xA7, 0xFF,
  0xA7, 0xFF, 0x54, 0xFF, 0x57, 0xFF, 0x63, 0xFF, 0x0C, 0x7F, 0x0C, 0x1F, 0x01, 0x1F, 0x00, 0x03,
  // frame 2
  0x08, 0x9C, 0x8C, 0xDE, 0x5C, 0xFE, 0x3E, 0xFE, 0xDE, 0xFE, 0xBC, 0xFE, 0x9E, 0xFE, 0xAE, 0xFE,
  0xBC, 0xFE, 0xDE, 0xFE, 0xCE, 0xFE, 0xBC, 0xFE, 0x78, 0xFC, 0x20, 0xF8, 0xC0, 0xE0, 0x00, 0xC0,
  0x00, 0x01, 0x01, 0x3F, 0x18, 0x3F, 0x18, 0x7F, 0x43, 0xFF, 0x57, 0xFF, 0x55, 0xFF, 0xA7, 0xFF,
  0xA7, 0xFF, 0x55, 0xFF, 0x57, 0xFF, 0x43, 0xFF, 0x18, 0x7F, 0x18, 0x3F, 0x01, 0x3F, 0x00, 0x03,
  // frame 3
  0x04, 0xCE, 0xC6, 0xEF, 0x2E, 0xFF, 0x1F, 0xFF, 0xEF, 0xFF, 0xDE, 0xFF, 0xCF, 0xFF, 0xD7, 0xFF,
  0xDE, 0xFF, 0xEF, 0xFF, 0xE7, 0xFF, 0xDE, 0xFF, 0x3C, 0xFE, 0x10, 0xFC, 0xE0, 0xF0, 0x00, 0xE0,
  0x00, 0x00, 0x00, 0x3F, 0x19, 0x3F, 0x18, 0x7F, 0x41, 0xFF, 0x5B, 0xFF, 0x53, 0xFF, 0xA3, 0xFF,
  0xA3, 0xFF, 0x53, 0xFF, 0x5B, 0xFF, 0x41, 0xFF, 0x18, 0x7F, 0x19, 0x3F, 0x00, 0x3D, 0x00, 0x01,
};


PROGMEM const unsigned char numbersSmall_plus_mask[] = {
  // width, height
  8, 8,
  // number 0
  0x00, 0x7C, 0x7C, 0xFE, 0xFE, 0xFF, 0xC7, 0xFF,
  0xE3, 0xFF, 0x7F, 0xFF, 0x3E, 0x7F, 0x00, 0x3E,
  // number 1
  0x00, 0x00, 0x00, 0x06, 0x06, 0xCF, 0xC6, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0xFF, 0x00, 0x07,
  // number 2
  0x00, 0xC0, 0xC0, 0xE6, 0xE6, 0xFF, 0xF7, 0xFF,
  0xFB, 0xFF, 0xDF, 0xFF, 0x0E, 0xDF, 0x00, 0x0E,
  // number 3
  0x00, 0x00, 0x00, 0x42, 0x42, 0xE7, 0xE7, 0xFF,
  0xDB, 0xFF, 0xFF, 0xFF, 0x7E, 0xFF, 0x00, 0x7E,
  // number 4
  0x00, 0x60, 0x60, 0xF8, 0x78, 0xFE, 0x7E, 0xFF,
  0xE7, 0xFF, 0xFF, 0xFF, 0x67, 0xFF, 0x00, 0x67,
  // number 5
  0x00, 0x00, 0x00, 0x50, 0x50, 0xFF, 0xDF, 0xFF,
  0xDF, 0xFF, 0xFB, 0xFF, 0x73, 0xFF, 0x00, 0x73,
  // number 6
  0x00, 0x70, 0x70, 0xF8, 0xF8, 0xFE, 0xCE, 0xFF,
  0xCF, 0xFF, 0x7F, 0xFF, 0x79, 0xFF, 0x00, 0x79,
  // number 7
  0x00, 0x80, 0x80, 0xC3, 0xC3, 0xF7, 0xF3, 0xFF,
  0x7F, 0xFF, 0x1F, 0x7F, 0x07, 0x1F, 0x00, 0x07,
  // number 8
  0x00, 0x70, 0x70, 0xFF, 0xFE, 0xFF, 0xDF, 0xFF,
  0xCB, 0xFF, 0xFF, 0xFF, 0x7E, 0xFF, 0x00, 0x7E,
  // number 9
  0x00, 0x00, 0x00, 0x9E, 0x9E, 0xFF, 0xDF, 0xFF,
  0xF3, 0xFF, 0x3F, 0xFF, 0x1E, 0x3F, 0x00, 0x1E,
};


PROGMEM const unsigned char numbersBig[] = {
  // width, height
  8, 16,
  // number 0
  0xE0, 0xFC, 0x3E, 0x0F, 0x07, 0x0F, 0xFF, 0xFE,
  0x3F, 0x7F, 0xF8, 0xF0, 0xF0, 0xF8, 0x7F, 0x1F,
  // number 1
  0x00, 0x00, 0x1C, 0xFE, 0xFF, 0xFF, 0x00, 0x00,
  0x00, 0x00, 0xE0, 0xFF, 0xFF, 0x7F, 0x60, 0x00,
  // number 2
  0x00, 0x1C, 0x1E, 0x07, 0x83, 0xC7, 0xFF, 0x7E,
  0xF0, 0xFC, 0xEE, 0xE7, 0xE3, 0x61, 0x70, 0x70,
  // number 3
  0x00, 0x0E, 0x0F, 0x87, 0xC3, 0xE7, 0xBF, 0x1E,
  0x70, 0xF8, 0xF8, 0xF0, 0xE0, 0xF1, 0x7F, 0x3F,
  // number 4
  0xC0, 0xF0, 0xFC, 0x8F, 0x83, 0xFF, 0xFE, 0xC0,
  0x03, 0x03, 0x03, 0x03, 0xFF, 0xFF, 0x7F, 0x00,
  // number 5
  0x00, 0xFE, 0xFE, 0xC7, 0xC7, 0xC7, 0xC7, 0x83,
  0x78, 0xF8, 0xF0, 0xE0, 0xE0, 0xF1, 0x7F, 0x3F,
  // number 6
  0xE0, 0xF8, 0xBC, 0xCE, 0xC7, 0xC3, 0x80, 0x00,
  0x3F, 0x7F, 0xF1, 0xE0, 0xE0, 0xF1, 0x7F, 0x3F,
  // number 7
  0x0E, 0x0F, 0x0F, 0x07, 0xC7, 0xF3, 0x7F, 0x0F,
  0x00, 0x00, 0xF0, 0xFE, 0x1F, 0x03, 0x00, 0x00,
  // number 8
  0x00, 0x7C, 0xFE, 0xE7, 0xC3, 0xE7, 0x7F, 0x3E,
  0x3E, 0x7F, 0xF3, 0xE1, 0xE1, 0xF3, 0x7F, 0x3E,
  // number 9
  0xFC, 0xFE, 0x8F, 0x07, 0x07, 0x8F, 0xFE, 0xFC,
  0x00, 0x01, 0xC3, 0xE3, 0x73, 0x3D, 0x1F, 0x07,
};


PROGMEM const unsigned char HUD_plus_mask[] = {
// width, height
9, 8,
// HEART
0x00, 0x0E, 0x0E, 0x1F, 0x1F, 0x3F, 0x3F, 0x7F, 0x7E, 
0xFF, 0x3F, 0x7F, 0x1F, 0x3F, 0x0E, 0x1F, 0x00, 0x0E, 
// SURVIVORS
0x00, 0x12, 0x12, 0x7F, 0x4F, 0xFF, 0x53, 0xFF, 0x1F, 
0x7F, 0x53, 0xFF, 0x4E, 0xFF, 0x10, 0x7E, 0x00, 0x10, 
// EX
0x00, 0x3E, 0x3E, 0x7F, 0x41, 0xFF, 0x55, 0xFF, 0x5D, 
0xFF, 0x7F, 0xFF, 0x49, 0xFF, 0x77, 0xFF, 0x49, 0xFF, 
// IT
0x7F, 0xFF, 0x41, 0xFF, 0x7F, 0xFF, 0x7D, 0xFF, 0x41, 
0xFF, 0x7D, 0xFF, 0x3E, 0x7F, 0x00, 0x3E, 0x00, 0x00, 
};


PROGMEM const unsigned char help_plus_mask[] = {
  // width, height
  28, 16,
  0x00, 0x00, 0x00, 0xF8, 0xF8, 0xFC, 0x04, 0xFE, 0x02, 0xFF, 0xFA, 0xFF, 0x22, 0xFF, 0x22, 0xFF, 0xFA, 0xFF, 0x02, 0xFF, 0xFA, 0xFF, 0xAA, 0xFF, 0xAA, 0xFF, 0x8A, 0xFF,
  0x02, 0xFF, 0xFA, 0xFF, 0x82, 0xFF, 0x82, 0xFF, 0x82, 0xFF, 0x02, 0xFF, 0xFA, 0xFF, 0x2A, 0xFF, 0x2A, 0xFF, 0x3A, 0xFF, 0x02, 0xFF, 0x04, 0xFE, 0xF8, 0xFC, 0x00, 0xF8,
  0x00, 0x06, 0x06, 0x0F, 0x09, 0x1F, 0x04, 0x0F, 0x02, 0x07, 0x02, 0x07, 0x02, 0x07, 0x02, 0x07, 0x02, 0x07, 0x02, 0x07, 0x02, 0x07, 0x02, 0x07, 0x02, 0x07, 0x02, 0x07,
  0x02, 0x07, 0x02, 0x07, 0x02, 0x07, 0x02, 0x07, 0x02, 0x07, 0x02, 0x07, 0x02, 0x07, 0x02, 0x07, 0x02, 0x07, 0x02, 0x07, 0x02, 0x07, 0x01, 0x03, 0x00, 0x01, 0x00, 0x00,
};


PROGMEM const unsigned char gameOver[] = {
  // width, height 84, 16,
  0xE0, 0xFC, 0x3E, 0x0F, 0x07, 0x3F, 0x3F, 0x1E, 0x00, 0x00, 0x00, 0xF0, 0xFE, 0x1F, 0x03, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0xFF, 0xFF, 0xF0, 0xC0, 0xC0, 0xF8, 0xFF, 0xFF, 0x00, 0x00, 0x86, 0xFF, 0xFF, 0x87, 0x87, 0x87, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xFC, 0x3E, 0x0F, 0x07, 0x0F, 0xFF, 0xFE, 0x00, 0x00, 0x1F, 0xFF, 0xFF, 0x00, 0x80, 0xFE, 0xFF, 0x1F, 0x00, 0x00, 0x86, 0xFF, 0xFF, 0x87, 0x87, 0x87, 0x07, 0x03, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0x87, 0x83, 0xC3, 0xFE, 0xFC,
  0x3F, 0x7F, 0xF0, 0xE0, 0xE6, 0xE7, 0x7F, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x07, 0x07, 0x03, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x01, 0x0F, 0x0F, 0x01, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xE1, 0xE1, 0xE0, 0xE0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x7F, 0xF8, 0xF0, 0xF0, 0xF8, 0x7F, 0x1F, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xFC, 0x7F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xE1, 0xE1, 0xE0, 0xE0, 0x60, 0x00, 0x00, 0xFF, 0xFF, 0x7F, 0x03, 0x1F, 0xFF, 0xF9, 0xE0
};


PROGMEM const unsigned char nextLevel[] = {
  // width, height 48, 16,
  0x00, 0xFF, 0xFF, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86, 0xFF, 0xFF, 0x87, 0x87, 0x87, 0x07, 0x03, 0x00, 0x00, 0x1F, 0xFF, 0xFF, 0x00, 0x80, 0xFE, 0xFF, 0x1F, 0x00, 0x00, 0x86, 0xFF, 0xFF, 0x87, 0x87, 0x87, 0x07, 0x03, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x3E, 0x00, 0x00, 0x00, 0x00,
  0xFE, 0xFF, 0xFF, 0xE0, 0xE0, 0xE0, 0xE0, 0x60, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xE1, 0xE1, 0xE0, 0xE0, 0x60, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xFC, 0x7F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xE1, 0xE1, 0xE0, 0xE0, 0x60, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0xE0, 0xE0, 0xE0, 0xE0, 0x60
};


PROGMEM const unsigned char coin_plus_mask[] = {
// width, height
8, 8,
// frame 0
0x3C, 0x7E, 0x66, 0xFF, 0xDB, 0xFF, 0xBD, 0xFF, 
0xBD, 0xFF, 0xDB, 0xFF, 0x66, 0xFF, 0x3C, 0x7E, 
// frame 1
0x00, 0x3C, 0x3C, 0x7E, 0x42, 0xFF, 0xBD, 0xFF, 
0xC3, 0xFF, 0x7E, 0xFF, 0x3C, 0x7E, 0x00, 0x3C, 
// frame 2
0x00, 0x00, 0x00, 0x7E, 0x7E, 0xFF, 0xDB, 0xFF, 
0xFF, 0xFF, 0x7E, 0xFF, 0x00, 0x7E, 0x00, 0x00, 
// frame 3
0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 
// frame 4
0x00, 0x00, 0x00, 0x7E, 0x7E, 0xFF, 0xFF, 0xFF, 
0xDB, 0xFF, 0x7E, 0xFF, 0x00, 0x7E, 0x00, 0x00, 
// frame 5
0x00, 0x3C, 0x3C, 0x7E, 0x7E, 0xFF, 0xC3, 0xFF, 
0xBD, 0xFF, 0x42, 0xFF, 0x3C, 0x7E, 0x00, 0x3C, 
};

PROGMEM const unsigned char heart_plus_mask[] = {
// width, height
8, 8,
// frame 0
0x1E, 0x3F, 0x31, 0x7F, 0x61, 0xFF, 0xC2, 0xFF, 
0xC2, 0xFF, 0x61, 0xFF, 0x31, 0x7F, 0x1E, 0x3F, 
// frame 1
0x00, 0x1E, 0x1E, 0x3F, 0x21, 0xFF, 0xC2, 0xFF, 
0xE1, 0xFF, 0x3F, 0xFF, 0x1E, 0x3F, 0x00, 0x1E, 
// frame 2
0x00, 0x00, 0x00, 0x3E, 0x3E, 0xFF, 0xC3, 0xFF, 
0xFF, 0xFF, 0x3E, 0xFF, 0x00, 0x3E, 0x00, 0x00, 
// frame 3
0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 
// frame 4
0x00, 0x00, 0x00, 0x3E, 0x3E, 0xFF, 0xFF, 0xFF, 
0xC3, 0xFF, 0x3E, 0xFF, 0x00, 0x3E, 0x00, 0x00, 
// frame 5
0x00, 0x1E, 0x1E, 0x3F, 0x3F, 0xFF, 0xE1, 0xFF, 
0xC2, 0xFF, 0x21, 0xFF, 0x1E, 0x3F, 0x00, 0x1E, 
};


PROGMEM const unsigned char dotMask[] = {
// width, height 2, 8,
0x03, 0x03
};

#endif
