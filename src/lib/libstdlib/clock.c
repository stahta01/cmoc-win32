
#include "_stdlib.h"

clock_t clock(void)
{
    return *(clock_t*)_TIMVAL;
}

