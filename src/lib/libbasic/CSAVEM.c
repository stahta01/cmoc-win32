
#include <basic.h>

int CSAVEM(char* fn, void* start, void* finish, void* exec)
{
    return systemf("CSAVEM \"%s\",%u,%u,%u", fn, start, finish, exec);
}

