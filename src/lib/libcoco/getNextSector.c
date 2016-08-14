
#include <coco.h>

// Returns true if sector successfully read, false otherwise.
//
byte getNextSector(struct FileDesc* fd)
{
    //printf("- getNextSector: start: curGran=%u, curSec=%u\n",
    //        fd->curGran, fd->curSec);
    if (fd->curGran == 0xFF) { // if at EOF
        //printf("- getNextSector: EOF\n");
        return 0;
    }

    byte track;
    byte sec;
    granuleToTrack(fd->curGran, &track, &sec);
    if (!readDiskSector(fd->curSector, fd->drive, track, sec + fd->curSec)) {
        return 0;
    }

    // Sector read successfully.
    // Determine how many bytes in it are part of the file.
    //
    if (isLastSectorOfFile(fd)) {
        fd->curSectorAvailBytes = fd->numBytesLastSector;
    } else {
        fd->curSectorAvailBytes = 256;
    }

    // Determine number of sectors in current granule that are
    // part of the file (1..9).
    //
    byte* fat = updateFAT();
    if (!fat) {
        return 0;
    }
    byte g = fat[fd->curGran];
    byte numSectorsCurGran;
    if (g >= 0xC1) {
        numSectorsCurGran = g - 0xC0;
    } else {
        numSectorsCurGran = 9;
    }

    //printf("- getNextSector: sector has %u, g=%2u, gran has %u\n",
    //        fd->curSectorAvailBytes, g, numSectorsCurGran);

    // Advance sector index. Go to next granule if needed.
    //
    ++fd->curSec;
    if (fd->curSec > numSectorsCurGran) { // if current granule finished
        if (g >= 0xC1) { // if current granule is last
            fd->curGran = 0xFF;    // marks file descriptor as at EOF, for next call
        } else {
            fd->curSec = 1;
            fd->curGran = g;
        }
    }
    //printf("- getNextSector: end: curGran=%u, curSec=%u\n", fd->curGran, fd->curSec);
    return 1;
}


