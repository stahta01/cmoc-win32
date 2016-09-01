
#include <conio.h>

char inkey();

unsigned char kbhit()
{
    return ungetch_buf || ungetch(inkey()) ? 1 : 0;
}

