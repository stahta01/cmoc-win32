
#include <coco.h>

// seconds: 0..1092

void sleep(int seconds)
{
    if (seconds) {
        unsigned limit = 60 * (unsigned) seconds;
        setTimer(0);
        while (getTimer() < limit) {}
    }
}





