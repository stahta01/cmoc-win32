
#include "_stdlib.h"

div_t* div(div_t* dst, int numer, int denom)
{
    dst->quot = numer / denom;
    dst->rem  = numer - (dst->quot * denom);
    return dst;
}

