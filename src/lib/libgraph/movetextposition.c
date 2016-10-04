
#include "_graph.h"

void _movetextposition(int direction)
{
    switch (direction) {
    case _MOVE_TEXT_POSITION_UP:
        break;
    case _MOVE_TEXT_POSITION_DOWN:
        break;
    case _MOVE_TEXT_POSITION_LEFT:
        if (fontinfo.type) {
            fontinfo.base ^= 1;
        }
        if (!fontinfo.type || fontinfo.base & 1) {
            if (_curpos & (_horbyt - 1)) {
                _curpos--;
            } else {
                _curpos -= 1 + ((word)_horbyt << 3) - _horbyt;
            }
            if (_curpos < _beggrp) {
                _curpos = _beggrp;
            }
        }
        break;
    case _MOVE_TEXT_POSITION_RIGHT:
        break;
    }
}

