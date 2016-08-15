
#include <basic.h>
#include <conio.h>

void CLS(byte c)
{
    c = bgcolor(c);
    clrscr();
    bgcolor(c);
}

