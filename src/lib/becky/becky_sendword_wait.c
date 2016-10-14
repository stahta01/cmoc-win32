
#include "_becky.h"

bool becky_sendword_wait(word val, word wait)
{
    return becky_sendbyte_wait(val >> 8, wait) && becky_sendbyte_wait((byte)val, wait);
}

