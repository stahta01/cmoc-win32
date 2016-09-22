
#include "_stdio.h"

size_t _fsize(FILE* fp)
{
    size_t size = 0;
    fcb_t* fcb = fcb_get(fp->dev - 1);
    if (fcb) {
        fat_t* fat = fat_get(fcb->drv);
        if (fat) {
            byte gr = fcb->fgr;
            while (gr < 64) {
                size += 2304;                   // bytes per granule
                gr = fat->dat[gr];
            }
            size += ((word)(gr & 63) << 8) - 2304 - (256 - fcb->lst);
        }
    }
    return size;
}

