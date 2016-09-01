
#include <charset.h>

unsigned char charset_6x8[CHARSET_SIZE] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x18,0x18,0x00,0x00,0x18,0x00,
    0x36,0x36,0x36,0x00,0x00,0x00,0x00,0x00,0x12,0x12,0x3F,0x12,0x3F,0x12,0x12,0x00,
    0x0C,0x1F,0x30,0x1E,0x03,0x3E,0x0C,0x00,0x31,0x33,0x06,0x0C,0x18,0x33,0x23,0x00,
    0x1E,0x33,0x1E,0x1C,0x33,0x33,0x1E,0x00,0x0C,0x18,0x30,0x00,0x00,0x00,0x00,0x00,
    0x0C,0x18,0x30,0x30,0x30,0x18,0x0C,0x00,0x30,0x18,0x0C,0x0C,0x0C,0x18,0x30,0x00,
    0x00,0x33,0x1E,0x3F,0x1E,0x33,0x00,0x00,0x00,0x0C,0x0C,0x3F,0x0C,0x0C,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x30,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x01,0x03,0x06,0x0C,0x18,0x30,0x00,
    0x1E,0x33,0x37,0x3B,0x33,0x33,0x1E,0x00,0x0C,0x0C,0x1C,0x0C,0x0C,0x0C,0x3F,0x00,
    0x1E,0x33,0x03,0x06,0x18,0x30,0x3F,0x00,0x1E,0x33,0x03,0x0E,0x03,0x33,0x1E,0x00,
    0x03,0x07,0x0F,0x33,0x3F,0x03,0x03,0x00,0x3F,0x30,0x3E,0x03,0x03,0x33,0x1E,0x00,
    0x1E,0x33,0x30,0x3E,0x33,0x33,0x1E,0x00,0x3F,0x33,0x06,0x0C,0x0C,0x0C,0x0C,0x00,
    0x1E,0x33,0x33,0x1E,0x33,0x33,0x1E,0x00,0x1E,0x33,0x33,0x1F,0x03,0x33,0x1E,0x00,
    0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x18,0x18,0x30,
    0x07,0x0C,0x18,0x30,0x18,0x0C,0x07,0x00,0x00,0x00,0x3F,0x00,0x3F,0x00,0x00,0x00,
    0x38,0x0C,0x06,0x03,0x06,0x0C,0x38,0x00,0x1E,0x33,0x03,0x06,0x0C,0x00,0x0C,0x00,
    0x1E,0x33,0x37,0x37,0x30,0x31,0x1E,0x00,0x0C,0x1E,0x33,0x3F,0x33,0x33,0x33,0x00,
    0x3E,0x33,0x33,0x3E,0x33,0x33,0x3E,0x00,0x1E,0x33,0x30,0x30,0x30,0x33,0x1E,0x00,
    0x3C,0x36,0x33,0x33,0x33,0x36,0x3C,0x00,0x3F,0x30,0x30,0x3C,0x30,0x30,0x3F,0x00,
    0x3F,0x30,0x30,0x3C,0x30,0x30,0x30,0x00,0x1E,0x33,0x30,0x37,0x33,0x33,0x1E,0x00,
    0x33,0x33,0x33,0x3F,0x33,0x33,0x33,0x00,0x3C,0x18,0x18,0x18,0x18,0x18,0x3C,0x00,
    0x0F,0x06,0x06,0x06,0x06,0x36,0x1C,0x00,0x33,0x36,0x3C,0x38,0x3C,0x36,0x33,0x00,
    0x30,0x30,0x30,0x30,0x30,0x30,0x3F,0x00,0x31,0x3B,0x3F,0x35,0x31,0x31,0x31,0x00,
    0x33,0x3B,0x3F,0x3F,0x37,0x33,0x33,0x00,0x1E,0x33,0x33,0x33,0x33,0x33,0x1E,0x00,
    0x3E,0x33,0x33,0x3E,0x30,0x30,0x30,0x00,0x1E,0x33,0x33,0x33,0x33,0x1E,0x07,0x00,
    0x3E,0x33,0x33,0x3E,0x3C,0x36,0x33,0x00,0x1E,0x33,0x30,0x1E,0x03,0x33,0x1E,0x00,
    0x3F,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x00,0x33,0x33,0x33,0x33,0x33,0x33,0x1E,0x00,
    0x33,0x33,0x33,0x33,0x33,0x1E,0x0C,0x00,0x31,0x31,0x31,0x35,0x3F,0x3B,0x31,0x00,
    0x33,0x33,0x1E,0x0C,0x1E,0x33,0x33,0x00,0x33,0x33,0x33,0x1E,0x0C,0x0C,0x0C,0x00,
    0x3F,0x03,0x06,0x0C,0x18,0x30,0x3F,0x00,0x3C,0x30,0x30,0x30,0x30,0x30,0x3C,0x00,
    0x00,0x30,0x18,0x0C,0x06,0x03,0x01,0x00,0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x3C,0x00,
    0x04,0x0E,0x1B,0x31,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,
    0x20,0x10,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x03,0x1F,0x33,0x1F,0x00,
    0x00,0x30,0x30,0x3E,0x33,0x33,0x3E,0x00,0x00,0x00,0x1E,0x30,0x30,0x30,0x1E,0x00,
    0x00,0x03,0x03,0x1F,0x33,0x33,0x1F,0x00,0x00,0x00,0x1E,0x33,0x3F,0x30,0x1E,0x00,
    0x00,0x0E,0x18,0x3E,0x18,0x18,0x18,0x00,0x00,0x00,0x1F,0x33,0x33,0x1F,0x03,0x3E,
    0x00,0x30,0x30,0x3E,0x33,0x33,0x33,0x00,0x00,0x18,0x00,0x38,0x18,0x18,0x3C,0x00,
    0x00,0x06,0x00,0x06,0x06,0x06,0x06,0x3C,0x00,0x30,0x30,0x36,0x3C,0x36,0x33,0x00,
    0x00,0x38,0x18,0x18,0x18,0x18,0x3C,0x00,0x00,0x00,0x33,0x3F,0x3F,0x35,0x31,0x00,
    0x00,0x00,0x3E,0x33,0x33,0x33,0x33,0x00,0x00,0x00,0x1E,0x33,0x33,0x33,0x1E,0x00,
    0x00,0x00,0x3E,0x33,0x33,0x3E,0x30,0x30,0x00,0x00,0x1F,0x33,0x33,0x1F,0x03,0x03,
    0x00,0x00,0x3E,0x33,0x30,0x30,0x30,0x00,0x00,0x00,0x1F,0x30,0x1E,0x03,0x3E,0x00,
    0x00,0x0C,0x3F,0x0C,0x0C,0x0C,0x07,0x00,0x00,0x00,0x33,0x33,0x33,0x33,0x1F,0x00,
    0x00,0x00,0x33,0x33,0x33,0x1E,0x0C,0x00,0x00,0x00,0x31,0x35,0x3F,0x1F,0x1B,0x00,
    0x00,0x00,0x33,0x1E,0x0C,0x1E,0x33,0x00,0x00,0x00,0x33,0x33,0x33,0x1F,0x06,0x3C,
    0x00,0x00,0x3F,0x06,0x0C,0x18,0x3F,0x00,0x0C,0x18,0x18,0x30,0x18,0x18,0x0C,0x00,
    0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x18,0x18,0x0C,0x18,0x18,0x30,0x00,
    0x00,0x00,0x00,0x1C,0x27,0x00,0x00,0x00,0x00,0x00,0x38,0x28,0x28,0x28,0x38,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x08,0x08,0x08,
    0x00,0x00,0x00,0x00,0x38,0x08,0x08,0x08,0x00,0x08,0x08,0x08,0x0E,0x00,0x00,0x00,
    0x00,0x08,0x08,0x08,0x38,0x00,0x00,0x00,0x00,0x08,0x08,0x08,0x08,0x08,0x08,0x08,
    0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x38,0x38,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x10,0x30,0x30,0x30,0x30,
    0x00,0x1F,0x10,0x10,0x10,0x10,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x1C,0x1C,0x14,0x1C,0x38,0x00,0x00,0x08,0x18,0x18,0x18,0x18,0x18,0x08,
    0x00,0x08,0x08,0x08,0x3E,0x08,0x08,0x08,0x00,0x00,0x08,0x18,0x38,0x18,0x08,0x00,
    0x00,0x08,0x1C,0x08,0x08,0x08,0x08,0x1C,0x00,0x00,0x18,0x18,0x18,0x00,0x18,0x00,
    0x00,0x38,0x38,0x38,0x38,0x18,0x18,0x18,0x00,0x08,0x08,0x08,0x3E,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x3E,0x08,0x08,0x08,0x00,0x08,0x08,0x08,0x38,0x08,0x08,0x08,
    0x00,0x08,0x1C,0x08,0x08,0x08,0x08,0x08,0x00,0x08,0x08,0x08,0x0E,0x08,0x08,0x08,
    0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

