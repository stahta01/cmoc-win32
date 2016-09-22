
#include "_stdio.h"

int fgetc(FILE* fp)
{
    if (fp->dev) {
        // TODO: We need to check for R/W and tape/printer
        if (fp->eof || fcb_get(fp->dev - 1)->cnt.seq.dfl) {
            return fp->eof = EOF;
        }
        return system_getchr(fp->dev);
    } else {
        return cgetc();
    }
}

