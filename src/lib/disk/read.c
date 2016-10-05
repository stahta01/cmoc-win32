
#include "_disk.h"

// Returns number of bytes read.
//
word _read(struct FileDesc* fd, char* buf, word numBytesRequested)
{
    //printf("- read(%u bytes): start: offset=$%04x%04x, secOffset=$%04x, curGran=%2u\n",
    //        numBytesRequested, fd->offset[0], fd->offset[1], fd->secOffset, fd->curGran);
    if (fd == 0) {
        return 0;
    }
    if (buf == 0) {
        return 0;
    }
    if (numBytesRequested == 0) {
        return 0;
    }

    char* bufStart = buf;
    for (;;) {
        word numAvailBytes;
        byte* availBytes = _getCurrentlyAvailableBytes(fd, &numAvailBytes);
        //printf("- read: AVAIL=%u, $%x\n", numAvailBytes, availBytes);

        if (numAvailBytes >= numBytesRequested) { // enough to finish request
            memcpy(buf, availBytes, numBytesRequested);
            buf += numBytesRequested;
            _advanceOffset(fd, numBytesRequested);
            //printf("- read: enough to finish request: %p - %p\n", buf, bufStart);
            return buf - bufStart;
        }

        // Currently loaded sector not enough.

        if (numAvailBytes > 0) {
            //printf("- read: delivering %u avail bytes\n", numAvailBytes);
            memcpy(buf, availBytes, numAvailBytes);  // send what we currently have
            buf += numAvailBytes;
            numBytesRequested -= numAvailBytes;
            _advanceOffset(fd, numAvailBytes);
        }

        if (!_getNextSector(fd)) { // if reached EOF
            //printf("- read: reached EOF: %p - %p\n", buf, bufStart);
            return buf - bufStart;
        }
    }
}


