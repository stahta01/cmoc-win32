
#include "_conio.h"

int getche(void)
{
    int chr = getch();
    cputc(chr);
    return chr;
}

