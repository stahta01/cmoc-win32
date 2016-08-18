
#include <basic.h>
#include <motorola.h>

#define p _PTRTYPE(_TEMPTR, byte)

word pset2_masks[4][4] = {
    {0xFF00,0xFF00,0xFF00,0xFF00},
    {0xBF40,0xEF10,0xFB04,0xFE01},
    {0x7F80,0xDF20,0xF708,0xFD02},
    {0x3FC0,0xCF30,0xF30C,0xFC03}
};

void _PSET2(void)
{
    word mask = pset2_masks[C][X & 3];
    switch (_horbyt) {
    case 16:
        p = (byte*)_beggrp + (Y << 4) + (X >> 2);
        break;
    case 32:
        p = (byte*)_beggrp + (Y << 5) + (X >> 2);
        break;
    default:
        p = (byte*)_beggrp + (Y * _horbyt) + (X >> 2);
        break;
    }
    *p = *p & _HIBYTE(mask) | _LOBYTE(mask);
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
    word mask = pset2_masks[C][X & 3];
    switch (_horbyt) {
    case 16:
        p = (byte*)_beggrp + (Y << 4) + (X >> 2);
        break;
    case 32:
        p = (byte*)_beggrp + (Y << 5) + (X >> 2);
        break;
    default:
        p = (byte*)_beggrp + (Y * _horbyt) + (X >> 2);
        break;
    }
    return (*p & _HIBYTE(mask)) >> (3 - (X & 3));
}

byte PPOINT2(int x, int y)
{
    X = x;
    Y = y;
    return _PPOINT2();
}

