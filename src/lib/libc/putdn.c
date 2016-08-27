
#include <conio.h>
#include <equates.h>

void putdn(void)
{
    _curpos += 32;
    if (_curpos >= 1536) {
        scrup();
        _curpos -= 32;
    }
}

