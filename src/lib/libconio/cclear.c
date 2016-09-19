
#include "_conio.h"

void cclear(int length)
{
    for (; length > 0; length--) {
        cputc(' ');
    }
}

