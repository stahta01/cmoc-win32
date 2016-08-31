
#include <basic.h>

int SAVEM(char* fn, void* start, void* finish, void* exec)
{
    return systemf("SAVEM\"%s\",%u,%u,%u", fn, start, finish, exec);
}

