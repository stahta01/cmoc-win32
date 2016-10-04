
#include "_conio.h"

void _cputlt(void)
{
    if (isvidram()) {
        _curpos--;
        if (!isvidram()) {
            _curpos = _VIDRAM;
        }
    }  else if (isgrpram() && _conio.movetextposition) {
        _conio.movetextposition(_MOVE_TEXT_POSITION_LEFT);
    }
}

