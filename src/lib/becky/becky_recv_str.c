
#include "_becky.h"

bool becky_recv_str(word type, char* dst, size_t size)
{
    bool result = becky_recv_data(type, (byte*)dst, size);
    if (result) {
        dst[becky_result.lo] = 0;
    }
    return result;
}

