
#include "_becky.h"

bool becky_send_byte(word type, byte src)
{
    return becky_send_data(type, (byte*)&src, sizeof(src));
}

