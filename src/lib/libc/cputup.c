
#include <conio.h>
#include <equates.h>

void cputup(void)
{
    _curpos -= 32;
    if (_curpos < _VIDRAM) {
        _curpos += 32;
    }
}

