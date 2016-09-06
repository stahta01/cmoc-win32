
#include "_libc.h"

int putenvstr(char* name, char* value)
{
    return systemf("%s$=\"%s\"", name, value);
}

