
#include "_becky.h"

bool becky_recvdata(byte* dst, size_t* size)
{
    byte* end = dst + *size;
    bool result = becky_recvword(size);
    for (size_t n = *size; result && n--;) {
        result = dst < end && becky_recvbyte(dst++);
    }
    return result;
}

