
#include <conio.h>

void chline(unsigned char length)
{
    for (; length; length--) {
        cputc('-');
    }
}

