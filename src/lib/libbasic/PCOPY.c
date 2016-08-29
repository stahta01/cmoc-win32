
#include <basic.h>

int PCOPY(byte p1, byte p2)
{
    return systemf("PCOPY %u TO %u", p1, p2);
}

