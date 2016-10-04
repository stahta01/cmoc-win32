
#include "_stdlib.h"

int putenvuint(char* name, unsigned value)
{
    return systemf("%s=%u", name, value);
}

