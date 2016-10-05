
#include "_graph.h"

void _gettextposition(point_t* point)
{
    word x = _curpos & (_horbyt - 1);
    if (fontinfo.type) {
        x <<= 1;
        x |= fontinfo.base & 1;
    }
    word y = _curpos - _beggrp;
    if (_horbyt == 16) {
        y >>= 7;
    } else {
        y >>= 8;
    }
    point->x = x;
    point->y = y;
}

