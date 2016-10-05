
#include <basic.h>
#include <conio.h>

int INKEY(void)
{
    return kbhit() ? getch() : 0;
}

