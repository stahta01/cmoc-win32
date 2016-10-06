
#include "_stdio.h"

FILE* fopen(char* name, char* mode)
{
    FILE* fp = nullptr;
    if (name && mode && *name && (*mode == 'r' || *mode == 'w')) {
        drive_t drive;
        dev_t dev;
        char* colon = strrchr(name, ':'), colon_chr;
        if (!colon) {
            colon = strrchr(name, ',');
        }
        if (colon) {
            colon_chr = *colon;
            *colon = 0;
            drive = atoi(colon + 1);
            if (drive < 0) {
                dev = drive;
                drive = -1;
            } else {
                dev = fcb_aval() + 1;
                if (!dev) {
                    return nullptr;
                }
            }
        } else {
            drive = getdisk();
            dev = fcb_aval() + 1;
            if (!dev || drive < 0) {
                return nullptr;
            }
        }
        errno = systemf(dev <= DEV_SCREEN ? "OPEN\"%c\",#%d,\"%s\"" : "OPEN\"%c\",#%d,\"%s:%u\"",
                        *mode == 'r' ? 'I' : 'O',
                        dev, name, drive);
        if (colon) {
            *colon = colon_chr;
        }
        if (!errno) {
            fp = new(FILE);
            if (fp) {
                fp->dev = dev;
            }
        }
    }
    return fp;
}

