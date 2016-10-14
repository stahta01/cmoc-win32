
#include "_becky.h"

bool becky_sendrequest(char* str)
{
    return becky_sendword(BECKY_REQUEST) && becky_sendstring(str);
}

