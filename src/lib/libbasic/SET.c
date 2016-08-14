
#include <basic.h>

byte _chr_set[2][2] = {{128|8, 128|2}, {128|4, 128|1}};
byte _chr_clr[2][2] = {{240|7, 240|13}, {240|11, 240|14}};

void SET(byte x, byte y, byte c)
{
    byte* p = (byte*)(0x400 + ((unsigned)(y & 30) << 4) + (unsigned)((x & 63) >> 1));
    if (c) {
        if (*p < 0x80) {
            *p = _chr_set[x & 1][y & 1] | ((c - 1) << 4);
        } else {
            *p = _chr_set[x & 1][y & 1] | ((c - 1) << 4) | (*p & 15);
        }
    } else {
        if (*p < 0x80) {
            *p = _chr_clr[x & 1][y & 1] & 0x8F;
        } else {
            *p = _chr_clr[x & 1][y & 1] & *p;
        }
    }
}


