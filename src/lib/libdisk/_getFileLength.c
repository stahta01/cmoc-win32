
#include "_disk.h"

byte _getFileLength(struct FileDesc* fd, word* dwLengthInBytes)
{
    if (!fd || !dwLengthInBytes) {
        dwLengthInBytes[0] = 0;
        dwLengthInBytes[1] = 0;
        return FALSE;
    }

    return _computeFileLength(dwLengthInBytes,
                             fd->firstGran, fd->numBytesLastSector);
}

