
#include "_becky.h"

bool becky_sendbyte_wait(word val, word wait)
{
    BECKY_BYTE = (byte)val;
    return becky_data_wait(wait) && BECKY_BYTE == val;
}

