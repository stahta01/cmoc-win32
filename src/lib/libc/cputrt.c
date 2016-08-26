
#include <conio.h>
#include <equates.h>

void cputrt(void)
{
    _curpos++;
    if (_curpos >= (_VIDRAM + 32 * 16)) {
        cscrollup();
        _curpos -= 32;
    }
}

