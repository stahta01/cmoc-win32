
#include "_becky.h"

bool becky_sendstring(char* str)
{
    return becky_senddata((byte*)str, strlen(str));
}

