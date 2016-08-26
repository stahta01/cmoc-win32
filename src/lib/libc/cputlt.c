
#include <conio.h>
#include <equates.h>

void cputlt(void)
{
    _curpos--;
    if (_curpos < _VIDRAM) {
        _curpos++;
    }
}

