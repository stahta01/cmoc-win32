
#include <conio.h>
#include <equates.h>

void cputdn(void)
{
    _curpos += 32;
    if (_curpos >= 1536) {
        cscrollup();
        _curpos -= 32;
    }
}

