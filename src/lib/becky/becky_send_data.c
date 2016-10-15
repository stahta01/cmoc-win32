
#include "_becky.h"

bool becky_send_data(word type, byte* src, size_t size)
{
    BECKY_BYTE = (byte)(type >> 8);
    BECKY_BYTE = (byte)type;
    BECKY_BYTE = (byte)(size >> 8);
    BECKY_BYTE = (byte)size;
    while (size--) {
        BECKY_BYTE = *src++;
    }
    becky_data_wait(1000);
    return becky_recv_word((word*)&becky_result.hi) && becky_recv_word((word*)&becky_result.lo) &&
           !becky_error();
}

