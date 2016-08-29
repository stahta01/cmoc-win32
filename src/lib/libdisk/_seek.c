
#include "_disk.h"

// newPos: 2-word position in bytes.
// Returns 0 for success, -1 for failure.
//
sbyte seek(struct FileDesc* fd, word* newPos)
{
    //printf("\n- seek(at %5u:%3u): start\n", newPos[0], newPos[1]);
    if (fd == 0) {
        return -1;
    }

    // If requested position is beyond end of file, clamp requested position.
    //
    sbyte comp = dwcompare(newPos, fd->length);
    if (comp > 0) {
        //printf("- seek: clamping\n");
        newPos[0] = fd->length[0];
        newPos[1] = fd->length[1];
    }

    // Compute granule index by dividing newPos by GRANULE_SIZE.
    // The granule index is relative to logical file contents,
    // it is not an index into the FAT.
    //
    byte granIndex = 0;
    word pos[2];
    pos[0] = newPos[0];
    pos[1] = newPos[1];
    //printf("- seek: before while: pos=(%5u:%5u) %2u\n", pos[0], pos[1], granIndex);
    while (pos[0] || pos[1] >= GRANULE_SIZE) { // while pos >= 2304
        ++granIndex;

        // Substract GRANULE_SIZE from 32-bit 'pos'.
        byte borrow = (pos[1] < GRANULE_SIZE);
        pos[1] -= GRANULE_SIZE;
        if (borrow) {
            --pos[0];
        }
        //printf("- seek:      pos=(%u, %u) %u\n", pos[0], pos[1], granIndex);
    }

    // Here, pos[1] is the offset in the last granule.
    word offsetInLastGranule = pos[1];
    assert(offsetInLastGranule < GRANULE_SIZE);

    // Determine the granule (0..67) from granIndex and the FAT.
    //
    byte* fat = _updateFAT();
    if (!fat) {
        return -1;
    }
    byte gran = fd->firstGran;
    //printf("- seek: granIndex=%u, offsetInLastGranule=%u, gran=%u\n",
    //        granIndex, offsetInLastGranule, gran);
    for (; granIndex; --granIndex) {
        assert(gran < 0xC0);  // not supposed to be the last granule
        gran = fat[gran];
    }
    assert(gran >= 0 && gran < MAX_NUM_GRANULES);
    fd->curGran = gran;

    // Determine the sector (1..9) inside granule 'gran'.
    //
    fd->curSec = (byte)((offsetInLastGranule >> 8) + 1);
    assert(fd->curSec >= 1 && fd->curSec <= 9);

    // Determine the current granule's length in bytes.
    //
    fd->curGranLen = _getGranuleLength(fat, gran, fd->numBytesLastSector);

    fd->secOffset = offsetInLastGranule & 0xFF;

    fd->curSectorAvailBytes = 0;

    fd->offset[0] = newPos[0];
    fd->offset[1] = newPos[1];
    //printf("- seek: %u %u %u %u:%u %u %u\n",
    //        fd->curGran, fd->curSec, fd->curGranLen,
    //        fd->offset[0], fd->offset[1], fd->secOffset,
    //        fd->curSectorAvailBytes);

    return 0;  // success
}


