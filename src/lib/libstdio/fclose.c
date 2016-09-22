
#include "_stdio.h"

int fclose(FILE* fp)
{
    close(fp->dev);
    free(fp);
    return 0;
}

