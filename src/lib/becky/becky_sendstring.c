
#include "_becky.h"

bool becky_sendstring(char* str)
{
    return becky_senddata(10, (byte*)str, strlen(str));
}

