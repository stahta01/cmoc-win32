
#include <conio.h>
#include <equates.h>

void putrt(void)
{
    _curpos++;
    if (_curpos >= (_VIDRAM + 32 * 16)) {
        scrup();
        _curpos -= 32;
    }
}

