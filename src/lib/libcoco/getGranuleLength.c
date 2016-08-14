
#include <coco.h>

word getGranuleLength(byte* fat, byte granule, word numBytesLastSector)
{
    if (fat == 0) {
        return 0;
    }
    if (granule < 0) {
        return 0;
    }
    if (granule > 67) {
        return 0;
    }

    byte entry = fat[granule];
    if (entry > 0xC9) {
        return 0;    // free granule, or invalid FAT entry
    }
    if (entry >= 0xC1) {
        return ((word) entry - 0xC1) * 256 + numBytesLastSector;
    }

    return 2304;  // this entry points to a following granule, so 'granule' is full
}


