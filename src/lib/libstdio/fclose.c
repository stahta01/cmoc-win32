
#include "_stdio.h"

int fclose(FILE* fp)
{
    systemf("CLOSE#%d", fp->devnum);
    free(fp);
    return 0;
}
