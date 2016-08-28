
#include <basic.h>

int LOADM(char* fn, word addr)
{
    return systemf("LOAD \"%s\",%u", fn, addr);
}

