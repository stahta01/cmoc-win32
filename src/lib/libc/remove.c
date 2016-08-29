
#include <stdio.h>
#include <stdlib.h>

int remove(char* fn)
{
    return systemf("KILL \"%s\"", fn);
}

