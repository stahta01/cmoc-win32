
#include "_dir.h"

void setdisk(int drive)
{
    if (hasdisk()) {
        _defdrv = (char)drive;
    }
}

