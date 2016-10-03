
#include "_exception.h"

void exception_throw(errno_t errno, word line)
{
    system_error(errno, line);
}

