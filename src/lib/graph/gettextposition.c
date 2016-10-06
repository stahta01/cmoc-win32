
#include "_graph.h"

void _gettextposition(int* _x, int* _y)
{
    word x = _curpos & (_horbyt - 1);
    if (fontinfo.packed) {
        x = (x << 1) | (fontinfo.base & 1);
    }
    word y = _curpos - _beggrp;
    if (_horbyt == 16) {
        y >>= 7;
    } else {
        y >>= 8;
    }
    *_x = x;
    *_y = y;
}

