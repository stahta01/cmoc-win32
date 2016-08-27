
#include <conio.h>
#include <equates.h>

void putlt(void)
{
    _curpos--;
    if (_curpos < _VIDRAM) {
        _curpos++;
    }
}

