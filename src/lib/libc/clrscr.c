
#include <conio.h>
#include <string.h>
#include <equates.h>

void clrscr(void)
{
    memset(_VIDRAM, 32, 32 * 16);
    _curpos = _VIDRAM;
}

