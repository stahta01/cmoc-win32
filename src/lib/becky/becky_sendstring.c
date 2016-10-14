
#include "_becky.h"

bool becky_sendstring(char* src)
{
    return becky_senddata((byte*)src, strlen(src));
}

