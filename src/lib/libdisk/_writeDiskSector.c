
#include "_disk.h"

byte _writeDiskSector(byte* src, byte drive, byte track, byte sector)
{
    return _dskcon(DSKCON_WRITE, src, drive, track, sector);
}


