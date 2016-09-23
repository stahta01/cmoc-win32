
#include "_system.h"

int system(char* cmd)
{
    return system_execute(system_crunch(cmd));
}

int systemf(char* fmt, ...)
{
    char cmd[BUFSIZ];
    va_list args;
    va_start(args, fmt);
    vsprintf(cmd, fmt, args);
    va_end();
    return system(cmd);
}

