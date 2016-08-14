
#include <coco.h>

byte isLastSectorOfFile(struct FileDesc* fd)
{
    byte* fat = updateFAT();
    if (!fat) {
        return 1;    // hope that caller will stop using disk...
    }
    byte g = fat[fd->curGran];
    if (g >= 0xC1)
        if (fd->curSec == g - 0xC0) {
            return 1;
        }
    return 0;
}


