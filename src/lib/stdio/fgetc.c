
#include "_stdio.h"

int fgetc(FILE* fp)
{
    int chr = EOF;
    if (!fp->eof) {
        if ((chr = fp->dev ? system_fgetc(fp->dev) : cgetc()) == EOF) {
            fp->eof = true;
        }
    }
    return chr;
}

