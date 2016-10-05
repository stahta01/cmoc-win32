
#include "_stdio.h"

int fputc(int chr, FILE* fp)
{
    if (fp->dev) {
        chr <<= 8;
        fputs((char*)&chr, fp);
    } else {
        cputc(chr);
    }
    return 0;
}

