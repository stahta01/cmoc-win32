
#include <conio.h>
#include <equates.h>

void cputc(char c)
{
    switch (c) {
    case _BS:
        cputlt();
        break;
    case 9:
        cputrt();
        break;
    case _LF:
        cputlf();
        break;
    default:
        putch(c);
        break;
    }
}
