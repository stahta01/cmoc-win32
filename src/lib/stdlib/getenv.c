
#include "_stdlib.h"

char* getenv(char* name)
{
    return getenvstr(name, SYSTEM_CMDLINE);
}

