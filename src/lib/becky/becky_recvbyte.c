
#include "_becky.h"

bool becky_recvbyte(byte* dst)
{
    bool result = becky_data_ready();
    if (result) {
        BECKY_BYTE = *dst = BECKY_BYTE;
    }
    return result;
}

