
#include "_becky.h"

bool becky_sendrequest(char* src)
{
    return becky_sendword(BECKY_REQUEST) && becky_sendstring(src);
}

