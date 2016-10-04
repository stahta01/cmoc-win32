
#include "_conio.h"

void _cputdn(void)
{
    if (isvidram()) {
        _curpos += 32;
        if (!isvidram()) {
            _curpos -= 32;
            scrup();
        }
    } else {
        if (_conio.movetextposition) {
            _conio.movetextposition(_GMOVEDOWN);
        }
    }
}

