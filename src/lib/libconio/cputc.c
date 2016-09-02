
#include "_conio.h"

void cputc(int c)
{
    switch (c) {
    case 8:
        putlt();
        break;
    case 9:
        putrt();
        break;
    case 10:
    case 13:
        putlf();
        break;
    default:
        putch(c);
        break;
    }
}
