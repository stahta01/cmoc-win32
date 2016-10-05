
#include "_conio.h"

void chlinexy(int x, int y, int length)
{
    gotoxy(x, y);
    chline(length);
}

