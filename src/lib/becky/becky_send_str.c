
#include "_becky.h"

bool becky_send_str(word type, char* src)
{
    return becky_send_data(type, (byte*)src, strlen(src));
}

