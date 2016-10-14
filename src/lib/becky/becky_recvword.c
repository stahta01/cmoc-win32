
#include "_becky.h"

bool becky_recvword(word* val)
{
    return becky_recvbyte(&((byte*)val)[0]) && becky_recvbyte(&((byte*)val)[1]);
}

