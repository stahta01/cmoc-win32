
#include <stdio.h>
#include <string.h>
#include <os9.h>
#include <long.h>

int main(void)
{
    long_t a, b, r;

    a.hi = 0;
    a.lo = 100;
    b.hi = 0;
    b.lo = 10;

    printf("%li\n", _lmul(&r, &a, &b));


    return 0;
}

