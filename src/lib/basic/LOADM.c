
#include <basic.h>

int LOADM(char* fn, word offset)
{
    return systemf("LOADM\"%s\",%u", fn, offset);
}

