
#include "_graph.h"

void _textscreensize(int* x, int* y)
{
    *x = fontinfo.packed ? _horbyt << 1 : _horbyt;
    *y = _endgrp - _beggrp;
    if (_horbyt == 16) {
        *y >>= 7;
    } else {
        *y >>= 8;
    }
}

