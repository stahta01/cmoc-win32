
#include "_graph.h"

void _textscreensize(int* rows, int* cols)
{
    *cols = fontinfo.type ? _horbyt << 1 : _horbyt;
    *rows = (_endgrp - _beggrp) / ((word)_horbyt << 3);
}

