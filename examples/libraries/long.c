
#include <conio.h>
#include <string.h>
#include <long.h>

int main(void)
{
    long a, b, r;

    cputs("CMOC 32BIT LONG FUNCTIONS\n\n");

    cprintf("1234 X 1234    = %li\n", _lmul(&r, _atol("1234", &a), _atol("1234", &b)));
    cprintf("1000000 / 1234 = %li\n", _ldiv(&r, _atol("1000000", &a), _atol("1234", &b)));
    cprintf("1000000 + 1234 = %li\n", _ladd(&r, _atol("1000000", &a), _atol("1234", &b)));
    cprintf("1234 - 1000000 = %li\n", _lsub(&r, _atol("1234", &a), _atol("1000000", &b)));

    return 0;
}

