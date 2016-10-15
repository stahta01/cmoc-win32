
#include "_becky.h"

bool becky_error()
{
    return (becky_result.hi == 0xffff) && (becky_result.lo == 0xffff);
}

