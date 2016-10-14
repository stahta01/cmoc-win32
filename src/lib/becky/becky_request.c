
#include "_becky.h"

bool becky_request(int val, word wait)
{
    BECKY_BYTE = (byte)val;
    return becky_wait(wait) ? BECKY_BYTE == val : false;
}

