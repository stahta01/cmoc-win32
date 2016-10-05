
#include "_graph.h"

void _settextpositionx(int x)
{
    if (fontinfo.type) {
        _curpos = _curpos & ((word)(_horbyt - 1) ^ -1) | (x >> 1);
        fontinfo.base = (fontinfo.base & 0xfe) | (x & 1);
    } else {
        _curpos = _curpos & ((word)(_horbyt - 1) ^ -1) | x;
    }
}

void _settextpositiony(int y)
{
    _curpos = _beggrp + (((word)y * ((word)_horbyt << 3)) | (_curpos & (_horbyt - 1)));
}

void _settextposition(int row, int col)
{
    _settextpositionx(col);
    _settextpositiony(row);
}

