
#include <conio.h>

void cputc(char c)
{
    switch (c) {
    case 8:
        putlt();
        break;
    case 9:
        putrt();
        break;
    case 10:
        putlf();
        break;
    default:
        putch(c);
        break;
    }
}
