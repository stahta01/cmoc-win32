
#include "_heman.h"

void heman_free(void* memory)
{
    if (memory && ((int*)memory)[-1] > 0) {
        ((int*)memory)[-1] = -((int*)memory)[-1];
    }
}

