
#include <basic.h>

int DSKINI(byte drive)
{
    return systemf("DSKINI %d", drive);
}

