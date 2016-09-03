
#include "_disk.h"

// TODO: test this on file whose length is multiple of 256 bytes.

byte _computeFileLength(word* dwLength, byte firstGran, word numBytesLastSector)
{
    if (dwLength == 0) {
        return FALSE;
    }

    // Presume error:
    dwLength[0] = 0xFFFF;
    dwLength[1] = 0xFFFF;

    if (firstGran > 67) {
        return FALSE;
    }
    if (numBytesLastSector > 256) {
        return FALSE;
    }

    byte* fat = _updateFAT();
    if (!fat) {
        return FALSE;
    }

    byte curGran = fat[firstGran];
    zerodw(dwLength);
    while (curGran <= 0xC0) {
        adddww(dwLength, 2304);
        curGran = fat[curGran];
    }

    word numBytesLastGran = curGran - 0xC1;  // for now, this is number of full sectors
    asm("LDD", numBytesLastGran);  // B = num full sectors, A = 0
    asm("EXG", "A,B");  // A = num full sectors, B = 0, i.e., D = num bytes in full sectors
    asm("STD", numBytesLastGran);
    numBytesLastGran += numBytesLastSector;

    adddww(dwLength, numBytesLastGran);  // add numBytesLastGran to dwLength[0]:dwLength[1]

    return TRUE;
}


