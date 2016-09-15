
#include "_malloc.h"

void free(void* m)
{
    if (m && ((int*)m)[-1] > 0) {
        ((int*)m)[-1] = -((int*)m)[-1];
    }
}

