
#include <basic.h>

byte _pset2_set[4][4] = {
    {0x00,0x00,0x00,0x00},
    {0x40,0x10,0x04,0x01},
    {0x80,0x20,0x08,0x02},
    {0xC0,0x30,0x0C,0x03}
};

byte _pset2_clr[] = {0x3F, 0xCF, 0xF3, 0xFC};

void PSET2(int x, int y, byte c)
{
    byte* p;
    switch (_horbyt) {
    case 16:
        p = (byte*)_beggrp + (y << 4) + (x >> 2);
        break;
    case 32:
        p = (byte*)_beggrp + (y << 5) + (x >> 2);
        break;
    default:
        p = (byte*)_beggrp + (y * _horbyt) + (x >> 2);
        break;
    }
    byte i = (byte)x & 3;
    *p = *p & _pset2_clr[i] | _pset2_set[c][i];
}

byte PPOINT2(int x, int y)
{
    byte* p;
    switch (_horbyt) {
    case 16:
        p = (byte*)_beggrp + (y << 4) + (x >> 2);
        break;
    case 32:
        p = (byte*)_beggrp + (y << 5) + (x >> 2);
        break;
    default:
        p = (byte*)_beggrp + (y * _horbyt) + (x >> 2);
        break;
    }
    byte i = (byte)x & 3;
    return (*p & _pset2_set[3][i]) >> (3 - (i));
}


