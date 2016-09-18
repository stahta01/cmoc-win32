
#include <stdio.h>
#include <float.h>

int main(void)
{
    float_t a, b, r;

    puts("FLOATING POINT TESTS\n");

    printf(" 5.2 X 5 =%f\n", _fmul(&r, _atof(&a,  "5.2"), _itof(&b, 5)));
    printf("10.5 X 2 =%f\n", _fmul(&r, _atof(&a, "10.5"), _itof(&b, 2)));
    printf("1234 / 3 =%f\n", _fdiv(&r, _atof(&a, "1234"), _itof(&b, 3)));
    printf("10.2 + 5 =%f\n", _fadd(&r, _atof(&a, "10.2"), _itof(&b, 5)));
    printf("60.5 - 5 =%f\n", _fsub(&r, _atof(&a, "60.5"), _itof(&b, 5)));

    return 0;
}
