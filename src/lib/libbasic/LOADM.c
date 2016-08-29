
#include <basic.h>

int LOADM(char* fn, void* offset)
{
    return systemf("LOADM \"%s\",%u", fn, offset);
}

