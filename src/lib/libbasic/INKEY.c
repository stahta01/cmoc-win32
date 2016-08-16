
#include <basic.h>
#include <conio.h>

char INKEY(void)
{
    return kbhit() ? getch() : 0;
}

