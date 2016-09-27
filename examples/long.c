
#include <stdio.h>
#include <long.h>

int main(void)
{
    long_t a, b, r;

    a.hi = 0;
    a.lo = 12;
    b.hi = 0;
    b.lo = 10;

    printf("%u\n", _lsub(&r, &a, &b)->lo);


    return 0;
}

