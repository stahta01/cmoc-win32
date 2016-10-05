
#include "_conio.h"

void chline(int length)
{
    for (; length > 0; length--) {
        cputc('-');
    }
}

