
#include "_conio.h"

void cclear(unsigned char length)
{
    for (; length; length--) {
        cputc(' ');
    }
}

