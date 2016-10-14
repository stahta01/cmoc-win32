
#include "_becky.h"

bool becky_sendword(word val)
{
    return becky_sendbyte(val >> 8) && becky_sendbyte((byte)val);
}

