
#include <string.h>
#include <stdio.h>
#include <float.h>

int main(void)
{
    char s[50];
    float_t a, b, r;

    puts("FLOATING POINT TESTS");

    puts(_ftoa(s, _fmul(&r, _atof(&a,  "5.2"), _itof(&b, 5))));
    puts(_ftoa(s, _fmul(&r, _atof(&a, "10.5"), _itof(&b, 2))));
    puts(_ftoa(s, _fdiv(&r, _atof(&a, "1234"), _itof(&b, 3))));
    puts(_ftoa(s, _fadd(&r, _atof(&a, "10.2"), _itof(&b, 5))));
    puts(_ftoa(s, _fsub(&r, _atof(&a, "60.5"), _itof(&b, 5))));

    return 0;
}

