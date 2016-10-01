
#include "_stdlib.h"

div_t* div(div_t* result, int numer, int denom)
{
    result->quot = numer / denom;
    result->rem  = numer - (result->quot * denom);
    return result;
}

