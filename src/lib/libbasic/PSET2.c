
#include <basic.h>

byte _pset2_set[4][4] = {
    {0x00,0x00,0x00,0x00},
    {0x40,0x10,0x04,0x01},
    {0x80,0x20,0x08,0x02},
    {0xC0,0x30,0x0C,0x03}
};

byte _pset2_clr[] = {0x3F, 0xCF, 0xF3, 0xFC};

void _PSET2(void)
{
    switch (_horbyt) {
    case 16:
        GR_P = (byte*)_beggrp + (Y << 4) + (X >> 2);
        break;
    case 32:
        GR_P = (byte*)_beggrp + (Y << 5) + (X >> 2);
        break;
    default:
        GR_P = (byte*)_beggrp + (Y * _horbyt) + (X >> 2);
        break;
    }
    _allcol = (byte)X & 3;
    *GR_P = *GR_P & _pset2_clr[_allcol] | _pset2_set[C][_allcol];
}

void PSET2(int x, int y, byte c)
{
    X = x;
    Y = y;
    C = c;
    _PSET2();
}

byte _PPOINT2(void)
{
    switch (_horbyt) {
    case 16:
        GR_P = (byte*)_beggrp + (Y << 4) + (X >> 2);
        break;
    case 32:
        GR_P = (byte*)_beggrp + (Y << 5) + (X >> 2);
        break;
    default:
        GR_P = (byte*)_beggrp + (Y * _horbyt) + (X >> 2);
        break;
    }
    _allcol = (byte)X & 3;
    return (*GR_P & _pset2_set[3][_allcol]) >> (3 - (_allcol));
}

byte PPOINT2(int x, int y)
{
    X = x;
    Y = y;
    return _PPOINT2();
}


