
#include "_disk.h"

void _rewind(struct FileDesc* fd)
{
    if (fd == 0) {
        return;    // invalid arguments
    }

    byte* fat = _updateFAT();
    if (!fat) {
        return;
    }

    fd->curGran = fd->firstGran;
    fd->curSec = 1;
    fd->curGranLen = _getGranuleLength(fat, fd->firstGran, fd->numBytesLastSector);
    fd->offset[0] = 0;
    fd->offset[1] = 0;
    fd->secOffset = 0;
    fd->curSectorAvailBytes = 0;
}


