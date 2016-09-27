
#include <conio.h>
#include <float.h>
#include <stdarg.h>
#include <equates.h>

int main(void)
{
    float_t a, b, r, pi;

    cputs("FLOATING POINT TESTS\n");

    _atof("3.14159", &pi);

    cprintf("2 X PI + 2 =%f\n", _frpn(&r, 'd', 2, 'f', &pi, '*', 's', "2", '+', 0));
    cprintf(" 5.2 X 5   =%f\n", _fmul(&r, _atof( "5.2", &a), _itof(5, &b)));
    cprintf("10.5 X 2   =%f\n", _fmul(&r, _atof("10.5", &a), _itof(2, &b)));
    cprintf("1234 / 3   =%f\n", _fdiv(&r, _atof("1234", &a), _itof(3, &b)));
    cprintf("10.2 + 5   =%f\n", _fadd(&r, _atof("10.2", &a), _itof(5, &b)));
    cprintf("60.5 - 5   =%f\n", _fsub(&r, _atof("60.5", &a), _itof(5, &b)));

    return 0;
}

