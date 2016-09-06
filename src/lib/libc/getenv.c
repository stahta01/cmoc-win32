
#include "_libc.h"

char* getenv(char* name)
{
    return getenvstr(name, _syscmdline);
}

