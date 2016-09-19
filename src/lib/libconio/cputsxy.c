
#include "_conio.h"

void cputsxy(int x, int y, char* s)
{
    gotoxy(x, y);
    cputs(s);
}

