
#include <basic.h>

int LOADM(char* fn, void* addr)
{
    return systemf("LOAD \"%s\",%u", fn, addr);
}

