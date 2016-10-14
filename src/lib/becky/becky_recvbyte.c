
#include "_becky.h"

bool becky_recvbyte(byte* val)
{
    bool result = becky_good();
    if (result) {
        BECKY_BYTE = *val = BECKY_BYTE;
    }
    return result;
}

