
#include "_graph.h"

void _settextpositiony(int y)
{
    if (_horbyt == 16) {
        y <<= 7;
    } else {
        y <<= 8;
    }
    _curpos = _beggrp + (y | (_curpos & (_horbyt - 1)));
}

