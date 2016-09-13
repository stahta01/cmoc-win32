
#include <basic.h>

int LOADM(char* fn, unsigned offset)
{
    return systemf("LOADM\"%s\",%u", fn, offset);
}

