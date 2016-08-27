
#include <conio.h>

void cclear(unsigned char length)
{
    for (; length; length--) {
        cputc(' ');
    }
}

