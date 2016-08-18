
#include <basic.h>
#include <motorola.h>

byte pset2_set[8] = {128, 64, 32, 16, 8, 4, 2, 1};
byte pset2_clr[8] = {127, 191, 223, 239, 247, 251, 253, 254};

void _PSET2(void)
{
    switch (_horbyt) {
    case 16:
        if (C) {
            *((byte*)_beggrp + (Y << 4) + (X >> 3)) |= pset2_set[X & 7];
        } else {
            *((byte*)_beggrp + (Y << 4) + (X >> 3)) &= pset2_clr[X & 7];
        }
        break;
    case 32:
        if (C) {
            *((byte*)_beggrp + (Y << 5) + (X >> 3)) |= pset2_set[X & 7];
        } else {
            *((byte*)_beggrp + (Y << 5) + (X >> 3)) &= pset2_clr[X & 7];
        }
        break;
    default:
        if (C) {
            *((byte*)_beggrp + (Y * _horbyt) + (X >> 3)) |= pset2_set[X & 7];
        } else {
            *((byte*)_beggrp + (Y * _horbyt) + (X >> 3)) &= pset2_clr[X & 7];
        }
        break;
    }
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
    return *((byte*)_beggrp + (Y * _horbyt) + (X >> 3)) & pset2_set[X & 7];
}

byte PPOINT2(int x, int y)
{
    X = x;
    Y = y;
    return _PPOINT2();
}













