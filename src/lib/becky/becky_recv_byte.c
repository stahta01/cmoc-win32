
#include "_becky.h"

bool becky_recv_byte(byte* dst)
{
    bool result = becky_data_ready();
    if (result) {
        *dst = BECKY_BYTE;
    }
    return result;
}

