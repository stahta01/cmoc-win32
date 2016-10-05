
#include "_heap.h"

void heap_free(void* memory)
{
    if (memory && ((int*)memory)[-1] > 0) {
        ((int*)memory)[-1] = -((int*)memory)[-1];
    }
}

