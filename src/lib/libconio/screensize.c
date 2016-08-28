
#include "_conio.h"

void screensize(unsigned char* x, unsigned char* y)
{
    if (isvidram()) {
        *x = 32;
        *y = 16;
    } else {
        *x = _conio.fontpack ? _horbyt << 1 : _horbyt;
        *y = (unsigned char)((_endgrp - _beggrp) / ((unsigned)_horbyt << 3));
    }
}

