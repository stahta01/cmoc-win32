
#include "_becky.h"

bool becky_recvword(word* dst)
{
    return becky_recvbyte(&((byte*)dst)[0]) && becky_recvbyte(&((byte*)dst)[1]);
}

