
#include <basic.h>

int CLOADM(char* fn, void* offset)
{
    return systemf("CLOADM\"%s\",%u", fn, offset);
}

