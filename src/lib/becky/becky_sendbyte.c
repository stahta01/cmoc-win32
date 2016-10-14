
#include "_becky.h"

bool becky_sendbyte(word val)
{
    BECKY_BYTE = (byte)val;
    return becky_good() && (BECKY_BYTE == val);
}

