#include "_becky.h"

bool becky_data_stop(void)
{
    bool result = becky_data_ready();
    if (result) {
        BECKY_BYTE = BECKY_BYTE + 1;
    }
    return result;
}

