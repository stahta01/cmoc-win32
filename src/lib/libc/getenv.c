
#include <stdlib.h>

char* getenv(char* name)
{
    return getenvstr(name, _syscmdline);
}

