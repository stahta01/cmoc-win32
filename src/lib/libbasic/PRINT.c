
#include <basic.h>
#include <unistd.h>

int PRINT(int fd, char* fmt, ...)
{
    char s[BUFSIZ];
    vsprintf(s, fmt, (va_list)&fmt);
    return write(fd, s, strlen(s));
}

