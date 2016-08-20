
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
        GR_P = (byte*)_beggrp + (zY << 4) + (zX >> 2);
        break;
    case 32:
        GR_P = (byte*)_beggrp + (zY << 5) + (zX >> 2);
        break;
    default:
        GR_P = (byte*)_beggrp + (zY * _horbyt) + (zX >> 2);
        break;
    }
    zWC = (byte)zX & 3;
    *GR_P = *GR_P & _pset2_clr[zWC] | _pset2_set[zFC][zWC];
}

void PSET2(int x, int y, byte c)
{
    zX = x;
    zY = y;
    zFC = c;
    _PSET2();
}

byte _PPOINT2(void)
{
    switch (_horbyt) {
    case 16:
        GR_P = (byte*)_beggrp + (zY << 4) + (zX >> 2);
        break;
    case 32:
        GR_P = (byte*)_beggrp + (zY << 5) + (zX >> 2);
        break;
    default:
        GR_P = (byte*)_beggrp + (zY * _horbyt) + (zX >> 2);
        break;
    }
    zWC = (byte)zX & 3;
    return (*GR_P & _pset2_set[3][zWC]) >> (3 - (zWC));
}

byte PPOINT2(int x, int y)
{
    zX = x;
    zY = y;
    return _PPOINT2();
}


