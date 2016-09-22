
#include "_os9.h"

void _tsleep(clock_t ticks)
{
    if (ticks) {
        clock_t start = clock();
        while ((clock() - start) < ticks) {}
    }
}

