
#include "_conio.h"

void cputcxy(unsigned char x, unsigned char y, int c)
{
    gotoxy(x, y);
    cputc(c);
}

