
#include "_disk.h"

// dirEntry: 16-byte region
//
byte findDirEntry(char* dirEntry, char* filename)
{
    char normalizedFilename[12];
    normalizeFilename(normalizedFilename, filename);
    //printf("Normalized filename: '%s'\n", normalizedFilename);

    for (byte sector = 3; sector <= 18; ++sector) {
        byte dirSector[256];
        if (!readDiskSector(dirSector, curDriveNo, 17, sector)) {
            return 0;    // TODO: report I/O error instead of "not found"
        }

        byte* entry;
        for (word index = 0; index < 256; index += 32) {
            entry = dirSector + index;
            if (!*entry) { // if erased entry
                continue;
            }
            if (*entry == 0xFF) { // if end of dir
                break;
            }

            if (memcmp(entry, normalizedFilename, 11) == 0) { // if filename matches
                memcpy(dirEntry, entry, 16);
                return 1;  // found
            }
        }
        if (*entry == 0xFF) { // if end of dir
            break;
        }
    }

    return 0;  // not found
}


