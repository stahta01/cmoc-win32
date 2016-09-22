
#include "_dir.h"

int getdisk(void)
{
    return hasdisk() ? _defdrv : -1;
}

