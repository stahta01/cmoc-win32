
#include <basic.h>

byte pset_set[8] = {128, 64, 32, 16, 8, 4, 2, 1};
byte pset_clr[8] = {127, 191, 223, 239, 247, 251, 253, 254};

void _PSET(void)
{
    switch (_horbyt) {
    case 16:
        if (_wcolor) {
            *((byte*)_beggrp + (Y << 4) + (X >> 3)) |= pset_set[X & 7];
        } else {
            *((byte*)_beggrp + (Y << 4) + (X >> 3)) &= pset_clr[X & 7];
        }
        break;
    case 32:
        if (_wcolor) {
            *((byte*)_beggrp + (Y << 5) + (X >> 3)) |= pset_set[X & 7];
        } else {
            *((byte*)_beggrp + (Y << 5) + (X >> 3)) &= pset_clr[X & 7];
        }
        break;
    default:
        if (_wcolor) {
            *((byte*)_beggrp + (Y * _horbyt) + (X >> 3)) |= pset_set[X & 7];
        } else {
            *((byte*)_beggrp + (Y * _horbyt) + (X >> 3)) &= pset_clr[X & 7];
        }
        break;
    }
}

void PSET(int x, int y, byte c)
{
    X = x;
    Y = y;
    _wcolor = c;
    _PSET();
}

int _PPOINT(void)
{
    return *((byte*)_beggrp + (Y * _horbyt) + (X >> 3)) & pset_set[X & 7];
}

int PPOINT(int x, int y)
{
    X = x;
    Y = y;
    return _PPOINT();
}







