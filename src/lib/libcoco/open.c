
#include <assert.h>
#include <coco.h>

// Initializes a file descriptor with the given filename.
// The filename must not contain a drive specification
// (the drive used is the one set by setDefautlDriveNo()).
// Filename search is not case sensitive.
// Period must be used as extension separator.
// Filenames do not have to be padded to 8 characters,
// nor extensions to 3.
// fileDesc must point to a 3-byte region.
// Returns 1 upon success, 0 upon failure (*fd is then undefined).
// close() must be called with fileDesc to release the
// underlying resources.
//
byte open(struct FileDesc* fd, char* filename)
{
    if (fd == 0 || filename == 0) {
        return 0;    // invalid arguments
    }
    //printf("- open(0x%x, %s): fd->curSector=0x%x\n", fd, filename, fd->curSector);
    assert(fd->curSector != 0);

    char dirEntry[16];
    if (!findDirEntry(dirEntry, filename)) {
        return 0;    // file not found
    }

    byte* fat = updateFAT();
    if (!fat) {
        return 0;
    }

    byte firstGran = dirEntry[13];
    word numBytesLastSector = * (word*)(dirEntry + 14);

    fd->drive = curDriveNo;
    fd->firstGran = firstGran;
    fd->numBytesLastSector = numBytesLastSector;
    computeFileLength(fd->length, fd->firstGran, fd->numBytesLastSector);

    _rewind(fd);

    return 1;
}


