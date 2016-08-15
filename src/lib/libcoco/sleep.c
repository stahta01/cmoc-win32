
#include <unistd.h>
#include <equates.h>

// seconds: 0..1092

unsigned sleep(unsigned seconds)
{
    if (seconds) {
        unsigned limit = seconds * 60;
        *(unsigned*)_TIMVAL = 0;
        while (*(unsigned*)_TIMVAL < limit) {}
    }
    return 0;
}





