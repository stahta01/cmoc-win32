
#include "_conio.h"

void _cputup(void)
{
    if (isvidram()) {
        _curpos -= 32;
        if (!isvidram()) {
            _curpos += 32;
        }
    } else {
        if (_conio.movetextposition) {
            _conio.movetextposition(_GMOVEUP);
        }
    }
}

