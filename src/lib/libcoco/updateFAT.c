
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <coco.h>

// Reads the current drive's FAT and returns the address of the
// internal buffer that contains it.
//
// Returns 0 upon failure to allocate memory or to read the FAT sector.
// Reads the FAT sector the first time, but not the following times,
// unless fatUpToDate is reset to 0.
//
// All accesses to the FAT must use the pointer returned by this function.
//
byte* updateFAT()
{
    if (fatUpToDate) {
        return fatBuffer;
    }

    if (!fatBuffer) {
        byte* p = (byte*) malloc(MAX_NUM_GRANULES);
        if (p == (byte*) -1) {
            printf("updateFAT: failed to allocate memory for FAT of drive %u\n", curDriveNo);
            return (byte*) 0;
        }
        fatBuffer = p;
    }

    byte fatSector[256];
    if (!readDiskSector(fatSector, curDriveNo, 17, 2)) {
        printf("updateFAT: failed to read FAT of drive %u\n", curDriveNo);
        return (byte*) 0;
    }

    memcpy(fatBuffer, fatSector, MAX_NUM_GRANULES);
    fatUpToDate = TRUE;
    return fatBuffer;
}

