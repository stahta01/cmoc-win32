
#include <stdio.h>
#include <long.h>

int main(void)
{
    long_t a, b, r;

    a.hi = 0;
    a.lo = 234;
    b.hi = 0;
    b.lo = 10;

    printf("%d\n", _lmul(&r, &a, &b)->lo);


    return 0;
}

