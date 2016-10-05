
#include "_stdio.h"

FILE* fopen(char* name, char* mode)
{
    FILE* fp = nullptr;
    if (name && mode && *name && (*mode == 'r' || *mode == 'w')) {
        int drive = -1;
        dev_t dev = 0;
        if (name[1] == ':') {
            switch (*name) {
            case 'A':
            case 'B':
            case 'C':
            case 'D':
                if (!hasdisk()) {
                    return nullptr;
                }
                dev = fcb_aval() + 1;
                drive = *name - 'A';
                if (!dev) {
                    return nullptr;
                }
                break;
            case 'S':
                dev = DEV_SCREEN;
                break;
            case 'T':
                dev = DEV_CASSETTE;
                break;
            case 'P':
                dev = DEV_PRINTER;
                break;
            default:
                return nullptr;
            }
            name += 2;
        } else {
            dev = fcb_aval() + 1;
            drive = getdisk();
            if (!dev || drive < DRIVE_MIN) {
                return nullptr;
            }
        }
        systemf(dev <= DEV_SCREEN ? "OPEN\"%c\",#%d,\"%s\"" : "OPEN\"%c\",#%d,\"%s:%u\"",
                *mode == 'r' ? 'I' : 'O',
                dev, name, drive);
        fp = new(FILE);
        if (fp) {
            fp->dev = dev;
        }
    }
    return fp;
}
