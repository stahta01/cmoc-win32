
#include <stdio.h>
#include <long.h>

int main(void)
{
    long_t a, b, r;

    a.hi = 0;
    a.lo = 20;
    b.hi = 0;
    b.lo = 10;

    printf("%u\n", _lshl(&a, &a, 2)->lo);


    return 0;
}

