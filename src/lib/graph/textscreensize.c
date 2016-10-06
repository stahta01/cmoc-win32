
#include "_graph.h"

void _textscreensize(int* x, int* y)
{
    *x = fontinfo.type ? _horbyt << 1 : _horbyt;
    *y = (_endgrp - _beggrp) / ((word)_horbyt << 3);
}

