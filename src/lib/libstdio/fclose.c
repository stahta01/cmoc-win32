
#include "_stdio.h"

int fclose(FILE* fp)
{
    close(fp->devnum);
    free(fp);
    return 0;
}

