
#include "_conio.h"

void _cputlt(void)
{
    if (isvidram()) {
        _curpos--;
        if (!isvidram()) {
            _curpos = _VIDRAM;
        }
    }  else if (_conio.movetextposition) {
        _conio.movetextposition(_GMOVELEFT);
    }
}

