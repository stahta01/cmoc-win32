
#include <conio.h>
#include <equates.h>

char putch(char c)
{
    *(unsigned char*)_curpos = c & 63;
    cputrt();
    return c;
}

