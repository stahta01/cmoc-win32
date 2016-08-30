
#include <stdlib.h>
#include <equates.h>

char* getenv(char* name)
{
    return getenvstr(name, _linbuf);
}

