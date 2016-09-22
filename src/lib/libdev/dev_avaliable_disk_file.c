
#include "_dev.h"

dev_t dev_avaliable_disk_file(void)
{
    dev_t dev = 0;
    if (getdisk() >= 0) {
        for (dev = _fcbact; dev > 0; dev--) {
            byte* fcb = (byte*)((word*)_FCBV1)[dev - 1];
            if (!fcb[_FCBTYP]) {
                break;
            }
        }
    }
    return dev;
}

