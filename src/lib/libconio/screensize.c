
#include "_conio.h"

void screensize(int* x, int* y)
{
    if (isvidram()) {
        *x = 32;
        *y = 16;
    } else {
        if (_conio.getfontinfo) {
            struct _fontinfo* fi = (struct _fontinfo*)_conio.getfontinfo();
            *x = fi->type ? _horbyt << 1 : _horbyt;
            *y = (_endgrp - _beggrp) / ((unsigned)_horbyt << 3);
        }
    }
}

