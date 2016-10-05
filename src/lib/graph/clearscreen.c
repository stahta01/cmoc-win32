
#include "_graph.h"

void _clearscreen(int area)
{

    switch (area) {
    case _GCLEARSCREEN:
        memset((void*)_beggrp, _pset2_all[_bakcol], _endgrp - _beggrp);
        break;
    case _GVIEWPORT:
        // TODO
        break;
    case _GWINDOW:
        // TODO
        break;
    }
}

