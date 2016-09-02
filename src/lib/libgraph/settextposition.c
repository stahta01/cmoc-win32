
#include "_graph.h"

void _settextpositionx(int x)
{
    if (fontinfo.type) {
        _curpos = _curpos & ((unsigned)(_horbyt - 1) ^ -1) | (x >> 1);
        fontinfo.base = x & 1 ? 128 : 0;
    } else {
        _curpos = _curpos & ((unsigned)(_horbyt - 1) ^ -1) | x;
    }
}

void _settextpositiony(int y)
{
    _curpos = _beggrp + (((unsigned)y * ((unsigned)_horbyt << 3)) | (_curpos & (_horbyt - 1)));
}

void _settextposition(int row, int col)
{
    _settextpositionx(col);
    _settextpositiony(row);
}

