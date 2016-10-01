
#include "_stdlib.h"

asm clock_t clock(void)
{
    asm {
        ldd  _TIMVAL
    }
}

