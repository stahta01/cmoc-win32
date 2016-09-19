
#include <conio.h>
#include <float.h>
#include <stdarg.h>
#include <equates.h>

int main(void)
{
    float_t a, b, r, pi;

    cputs("FLOATING POINT TESTS\n");

    _atof(&pi, "3.14159");

    cprintf("2 X PI + 2 =%f\n", _frpn(&r, 'd', 2, 'f', &pi, '*', 's', "2", '+', 0));
    cprintf(" 5.2 X 5   =%f\n", _fmul(&r, _atof(&a,  "5.2"), _itof(&b, 5)));
    cprintf("10.5 X 2   =%f\n", _fmul(&r, _atof(&a, "10.5"), _itof(&b, 2)));
    cprintf("1234 / 3   =%f\n", _fdiv(&r, _atof(&a, "1234"), _itof(&b, 3)));
    cprintf("10.2 + 5   =%f\n", _fadd(&r, _atof(&a, "10.2"), _itof(&b, 5)));
    cprintf("60.5 - 5   =%f\n", _fsub(&r, _atof(&a, "60.5"), _itof(&b, 5)));

    return 0;
}

