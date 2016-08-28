
#include <conio.h>

void cputsxy(unsigned char x, unsigned char y, char* s)
{
    gotoxy(x, y);
    cputs(s);
}

