
#include "_graph.h"

void _settextpositionat(int pos)
{
    if (fontinfo.packed) {
        fontinfo.base = (fontinfo.base & 0xfe) | (pos & 1);
        pos >>= 1;
    }
    _curpos = _beggrp + (pos & (word)(_horbyt - 1)) + ((pos & (_horbyt == 16 ? 0xfff0 : 0xffe0)) << 3);
}

