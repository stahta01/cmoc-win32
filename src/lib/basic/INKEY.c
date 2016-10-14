
#include "_basic.h"

int INKEY(void)
{
    return kbhit() ? getch() : 0;
}

