
#include "_stdlib.h"

int systemf(char* fmt, ...)
{
    char cmd[BUFSIZ];
    va_list args;
    va_start(args, fmt);
    vswritef(cmd, fmt, args);
    va_end();
    return system(cmd);
}

