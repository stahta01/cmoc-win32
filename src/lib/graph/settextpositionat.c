
#include "_graph.h"

void _settextpositionat(int at)
{
    if (fontinfo.type) {
        fontinfo.base = (fontinfo.base & 0xfe) | (at & 1);
        at >>= 1;
    }
    _curpos = _beggrp + (at & (word)(_horbyt - 1)) + ((at & (_horbyt == 16 ? 0xfff0 : 0xffe0)) << 3);
}

