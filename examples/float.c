
#include <string.h>
#include <stdio.h>
#include <equates.h>
#include <float.h>

/*
#define M_2PI (*(float_t*)_LBFBD)
*/



// LBAC5 = ONE?

int main(void)
{
    float_t a, b, c;
    char s[100];
    _atof(&a, "5");
    _atof(&c, "3");

    _fmul(&b, &a, &c);

    //_fmul(&b, &a, &a);
    //_fdiv(&b, &b, &c);
    _ftoa(s, &b);
    puts(s);

    return 0;
}

