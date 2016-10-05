
#include "_graph.h"

void _settextpositionat(int at)
{
    int x = at & (word)(_horbyt - 1);
    int y = (at & (_horbyt == 16 ? 0xfff0 : 0xffe0)) << 3;
    if (fontinfo.type) {
        x >>= 1;
        fontinfo.base = (fontinfo.base & 0xfe) | (x & 1);
    }
    _curpos = _beggrp + x + y;
}

