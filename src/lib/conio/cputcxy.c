
#include "_conio.h"

void cputcxy(int x, int y, int c)
{
    gotoxy(x, y);
    // TODO: We should call cputs here
    cputc(c);
}

