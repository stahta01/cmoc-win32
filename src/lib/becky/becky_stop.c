#include "_becky.h"

bool becky_stop(void)
{
    bool result = becky_good();
    if (result) {
        BECKY_BYTE = BECKY_BYTE + 1;
    }
    return result;
}

