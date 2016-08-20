
#include <basic.h>
#include <motorola.h>

byte pset1_set[8] = {128, 64, 32, 16, 8, 4, 2, 1};
byte pset1_clr[8] = {127, 191, 223, 239, 247, 251, 253, 254};

void _PSET1(void)
{
    switch (_horbyt) {
    case 16:
        if (C) {
            *((byte*)_beggrp + (zY << 4) + (zX >> 3)) |= pset1_set[zX & 7];
        } else {
            *((byte*)_beggrp + (zY << 4) + (zX >> 3)) &= pset1_clr[zX & 7];
        }
        break;
    case 32:
        if (C) {
            *((byte*)_beggrp + (zY << 5) + (zX >> 3)) |= pset1_set[zX & 7];
        } else {
            *((byte*)_beggrp + (zY << 5) + (zX >> 3)) &= pset1_clr[zX & 7];
        }
        break;
    default:
        if (C) {
            *((byte*)_beggrp + (zY * _horbyt) + (zX >> 3)) |= pset1_set[zX & 7];
        } else {
            *((byte*)_beggrp + (zY * _horbyt) + (zX >> 3)) &= pset1_clr[zX & 7];
        }
        break;
    }
}

void PSET1(int x, int y, byte c)
{
    zX = x;
    zY = y;
    C = c;
    _PSET1();
}

byte _PPOINT1(void)
{
    return *((byte*)_beggrp + (zY * _horbyt) + (zX >> 3)) & pset1_set[zX & 7];
}

byte PPOINT1(int x, int y)
{
    zX = x;
    zY = y;
    return _PPOINT1();
}













