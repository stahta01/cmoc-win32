
#include <basic.h>

int KILL(char* fn)
{
    return systemf("KILL %s", fn);
}

