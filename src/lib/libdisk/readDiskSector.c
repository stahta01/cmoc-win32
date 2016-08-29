
#include "_disk.h"

byte readDiskSector(byte* dest, byte drive, byte track, byte sector)
{
    return dskcon(DSKCON_READ, dest, drive, track, sector);
}


