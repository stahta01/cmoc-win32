
#include "_conio.h"

void screensize(int* x, int* y)
{
    if (isvidram()) {
        *x = 32;
        *y = 16;
    } else {
        *x = _getfontinfo()->type ? _horbyt << 1 : _horbyt;
        *y = (_endgrp - _beggrp) / ((unsigned)_horbyt << 3);
    }
}

