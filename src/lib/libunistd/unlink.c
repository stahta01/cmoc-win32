
#include "_unistd.h"

int unlink(char* fn)
{
    return remove(fn);
}

