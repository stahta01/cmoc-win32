
#include "_exception.h"

void exception_raise(errno_t errno, char* message)
{
    system_error(errno, message);
}

