
#include "_libc.h"

int remove(char* fn)
{
    return systemf("KILL\"%s\"", fn);
}

