
#include <basic.h>

int CLOADM(char* fn, unsigned offset)
{
    return systemf("CLOADM\"%s\",%u", fn, offset);
}

