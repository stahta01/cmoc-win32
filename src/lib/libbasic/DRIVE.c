
#include <basic.h>

int DRIVE(byte drive)
{
    return systemf("DRIVE %d", drive);
}

