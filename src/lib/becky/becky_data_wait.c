
#include "_becky.h"

bool becky_data_wait(word wait)
{
    for (word start = BECKY_TICK; (BECKY_STAT & 2) == 0;) {
        if ((BECKY_TICK - start) > wait) {
            return false;
        }
    }
    return true;
}

