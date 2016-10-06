
#include "_stdio.h"

int fclose(FILE* fp)
{
    int result = close(fp->dev);
    free(fp);
    return result;
}

