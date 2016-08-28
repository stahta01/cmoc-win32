
#include <basic.h>

int DRIVE(byte d)
{
    return systemf("DRIVE %d", d);
}

