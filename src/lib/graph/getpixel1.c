
#include "_graph.h"

byte _getpixel1(int x, int y)
{
    if (_pmode != 4)  {
        x >>= 1;
    }
    if (_pmode < 2) {
        y >>= 1;
    }
    return *((byte*)_beggrp + (y * _horbyt) + (x >> 3)) & pixel1_set[x & 7];
}

