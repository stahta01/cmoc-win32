
#include "_becky.h"

bool becky_send_word(word type, word src)
{
    return becky_send_data(type, (byte*)&src, sizeof(src));
}

