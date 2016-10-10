
#include "_basic.h"

int PRINT(int fd, char* fmt, ...)
{
    char buf[MAX_INPUT];
    va_list args;
    va_start(args, fmt);
    vsprintf(buf, fmt, args);
    va_end();
    return write(_filedesc[fd], buf, strlen(buf));
}

