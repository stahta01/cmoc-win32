
#include "_becky.h"

bool becky_recvstring(char* dst, size_t size)
{
    if (size) {
        size -= 1;
        if (becky_recvdata((byte*)dst, &size)) {
            dst[size] = 0;
            return true;
        }
    }
    return false;
}

