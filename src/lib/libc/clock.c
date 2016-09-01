
#include <time.h>
#include <equates.h>

clock_t clock(void)
{
    return *(clock_t*)_TIMVAL;
}

