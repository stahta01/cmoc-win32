
#include "_conio.h"

void _cputrt(void)
{
    if (isvidram()) {
        _curpos++;
        if (!isvidram()) {
            _curpos -= 32;
            scrup();
        }
    } else {
        if (_conio.movetextposition) {
            _conio.movetextposition(_GMOVERIGHT);
        }
    }
}

