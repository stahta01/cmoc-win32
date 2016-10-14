
#include "_becky.h"

bool becky_recv_data(word type, byte* dst, size_t size)
{
    bool result = becky_send_word(type, size);
    if (result) {
        size = becky_result.lo;
        while (size-- && (result = becky_recv_byte(dst++)));
    }
    return result;
}

