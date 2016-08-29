
#include "_disk.h"

byte* _getCurrentlyAvailableBytes(struct FileDesc* fd, word* numAvailBytes)
{
    //printf("- getCurrentlyAvailableBytes: start: %u, %u\n",
    //        fd->secOffset, fd->curSectorAvailBytes);

    if (fd->curSectorAvailBytes == 0) {
        // This is the state after a seek. secOffset can be 0..256.
        //
        *numAvailBytes = 0;
        return (byte*) 0;
    }

    assert(fd->secOffset <= fd->curSectorAvailBytes);

    byte* availBytes = (byte*) fd->curSector + fd->secOffset;

    *numAvailBytes = fd->curSectorAvailBytes - fd->secOffset;

    //printf("- getCurrentlyAvailableBytes: %u at 0x%x\n", *numAvailBytes, availBytes);
    return availBytes;
}


