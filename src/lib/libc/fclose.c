
#include <stdio.h>
#include <stdlib.h>

int fclose(FILE* fp)
{
    systemf("CLOSE#%d", fp);
    return 0;
}

