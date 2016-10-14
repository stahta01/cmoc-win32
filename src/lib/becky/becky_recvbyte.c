
#include "_becky.h"

bool becky_recvbyte(byte* val)
{
    bool result = becky_data_ready();
    if (result) {
        BECKY_BYTE = *val = BECKY_BYTE;
    }
    return result;
}

