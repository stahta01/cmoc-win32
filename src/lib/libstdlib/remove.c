
#include "_stdlib.h"

int remove(char* fn)
{
    return systemf("KILL\"%s\"", fn);
}

