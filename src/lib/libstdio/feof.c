
#include "_stdio.h"

int feof(FILE* fp)
{
    return fp->cinbfl ? EOF : 0;
}

