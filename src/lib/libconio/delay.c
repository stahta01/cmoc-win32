
#include "_conio.h"

void delay(clock_t ticks)
{
    if (ticks) {
        clock_t start = clock();
        while ((clock() - start) < ticks) {}
    }
}

