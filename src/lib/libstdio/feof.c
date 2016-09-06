
#include "_stdio.h"

int feof(FILE* fp)
{
    return fp->buffer == EOF;
}

