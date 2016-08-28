
#include <conio.h>
#include <equates.h>

void putup(void)
{
    _curpos -= 32;
    if (_curpos < _VIDRAM) {
        _curpos += 32;
    }
}

