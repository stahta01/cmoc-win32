
#include "_becky.h"

bool becky_sendbyte(word val)
{
    BECKY_BYTE = (byte)val;
    return becky_data_ready() && (BECKY_BYTE == val);
}

