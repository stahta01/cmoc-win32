
#include "_becky.h"

bool becky_sendstring(char* str)
{
    return becky_senddata(BECKY_STRING, (byte*)str, strlen(str));
}

