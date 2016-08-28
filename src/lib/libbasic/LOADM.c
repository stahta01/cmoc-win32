
#include <basic.h>

int LOADM(char* fn, void* addr)
{
    return systemf("LOADM \"%s\",%u", fn, addr);
}

