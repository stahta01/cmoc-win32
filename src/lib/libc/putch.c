
#include <conio.h>
#include <equates.h>

char putch(char c)
{
    *(unsigned char*)_curpos = _conio.revers ? c & 63 : c & 63 | 64;
    putrt();
    return c;
}

