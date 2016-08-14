
#include <conio.h>

void cputcxy(unsigned char x, unsigned char y, char c)
{
    gotoxy(x, y);
    cputc(c);
}

