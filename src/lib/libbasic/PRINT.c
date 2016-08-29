
#include "_basic.h"

int PRINT(int fd, char* fmt, ...)
{
    char buf[BUFSIZ];
    vsprintf(buf, fmt, (va_list)&fmt);
    return write(_filedesc[fd], buf, strlen(buf));
}

