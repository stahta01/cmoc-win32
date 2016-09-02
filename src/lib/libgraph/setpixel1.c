
#include "_graph.h"

void _setpixel1(short x, short y, byte c)
{
    if (_pmode < 4)  {
        x >>= 1;
        if (_pmode < 2) {
            y >>= 1;
        }
    }
    switch (_horbyt) {
    case 16:
        if (c) {
            *((byte*)_beggrp + (y << 4) + (x >> 3)) |= _pset1_set[x & 7];
        } else {
            *((byte*)_beggrp + (y << 4) + (x >> 3)) &= _pset1_clr[x & 7];
        }
        break;
    case 32:
        if (c) {
            *((byte*)_beggrp + (y << 5) + (x >> 3)) |= _pset1_set[x & 7];
        } else {
            *((byte*)_beggrp + (y << 5) + (x >> 3)) &= _pset1_clr[x & 7];
        }
        break;
    default:
        if (c) {
            *((byte*)_beggrp + (y * _horbyt) + (x >> 3)) |= _pset1_set[x & 7];
        } else {
            *((byte*)_beggrp + (y * _horbyt) + (x >> 3)) &= _pset1_clr[x & 7];
        }
        break;
    }
}

