
#include <unistd.h>
#include <time.h>

// seconds: 0..1092

unsigned sleep(unsigned seconds)
{
    if (seconds) {
        seconds *= CLOCKS_PER_SEC;
        clock_t t = clock();
        while ((clock() - t) < seconds) {}
    }
    return 0;
}

