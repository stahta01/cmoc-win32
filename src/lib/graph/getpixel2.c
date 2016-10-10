
#include "_graph.h"

byte _getpixel2(int x, int y)
{
    if (_pmode != 4)  {
        x >>= 1;
    }
    if (_pmode < 2) {
        y >>= 1;
    }
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
    return (*p & pixel2_set[3][i]) >> ((3 - i) << 1);
}

