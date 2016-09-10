
#include <unistd.h>
#include <time.h>

void delay(clock_t ticks)
{
    if (ticks) {
        clock_t start = clock();
        while ((clock() - start) < ticks) {}
    }
}

