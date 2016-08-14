
#include <cmoc.h>
#include <coco.h>

void advanceOffset(struct FileDesc* fd, word numBytes)
{
    adddww(fd->offset, numBytes);
    fd->secOffset += numBytes;

    //printf("- advanceOffset: now 0x%04x%04x\n", fd->offset[0], fd->offset[1]);
    assert(fd->secOffset <= fd->curSectorAvailBytes);

    if (fd->secOffset >= fd->curSectorAvailBytes) { // if reached end of available bytes
        // Declare 'fd' to be empty of available bytes.
        // This will force another read.
        //
        fd->secOffset = 0;
        fd->curSectorAvailBytes = 0;
    }
}


