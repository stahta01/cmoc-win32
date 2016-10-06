
#include "_graph.h"

void _settextposition(int x, int y)
{
    if (fontinfo.type) {
        fontinfo.base = (fontinfo.base & 0xfe) | (x & 1);
        x >>= 1;
    }
    if (_horbyt == 16) {
        y <<= 7;
    } else {
        y <<= 8;
    }
    _curpos = _beggrp + x + y;
}

