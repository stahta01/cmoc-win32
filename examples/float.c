
#include <string.h>
#include <stdio.h>
#include <float.h>

int main(void)
{
    float_t a, b, c;
    char s[100];
    _atof(&a, "5");
    _atof(&c, "3");

    _fmul(&b, &a, &c);

    //_fmul(&b, &a, &a);
    //_fdiv(&b, &b, &c);
    _ftoa(s, M_1_4);
    puts(s);

    return 0;
}

