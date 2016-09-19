
#include "_conio.h"

void cputcxy(int x, int y, int c)
{
    gotoxy(x, y);
    cputc(c);
}

