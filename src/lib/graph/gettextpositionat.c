
#include "_graph.h"

int _gettextpositionat(void)
{
    int y = _curpos - _beggrp;
    int x = y & ((word)_horbyt - 1);
    y = (y & (_horbyt == 16 ? 0xff80 : 0xff00)) >> 3;
    if (fontinfo.type) {
        x = (x << 1) | (fontinfo.base & 1);
    }
    return x + y;
}

