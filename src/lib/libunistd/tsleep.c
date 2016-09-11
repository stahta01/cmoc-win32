
#include "_unistd.h"

void tsleep(clock_t ticks)
{
    if (ticks) {
        clock_t start = clock();
        while ((clock() - start) < ticks) {}
    }
}

