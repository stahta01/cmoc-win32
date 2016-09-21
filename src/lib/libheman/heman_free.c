
#include "_heman.h"

void heman_free(void* m)
{
    if (m && ((int*)m)[-1] > 0) {
        ((int*)m)[-1] = -((int*)m)[-1];
    }
}

