
#include "_becky.h"

bool becky_recv_word(word* dst)
{
    return becky_recv_byte(&((byte*)dst)[0]) && becky_recv_byte(&((byte*)dst)[1]);
}

