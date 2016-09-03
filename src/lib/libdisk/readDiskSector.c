
#include "_disk.h"

byte _readDiskSector(byte* dest, byte drive, byte track, byte sector)
{
    return _dskcon(DSKCON_READ, dest, drive, track, sector);
}


