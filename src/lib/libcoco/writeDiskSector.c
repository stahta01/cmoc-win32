
#include <coco.h>

byte writeDiskSector(byte* src, byte drive, byte track, byte sector)
{
    return dskcon(DSKCON_WRITE, src, drive, track, sector);
}


