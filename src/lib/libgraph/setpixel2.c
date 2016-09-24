
#include "_graph.h"

void _setpixel2(int x, int y, byte c)
{
    if (_pmode != 4)  {
        x >>= 1;
    }
    if (_pmode < 2) {
        y >>= 1;
    }
    byte* p;
    x >>= 1;
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

