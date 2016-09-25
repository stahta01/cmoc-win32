
#include "_heap.h"

int heap_msize(void* memory)
{
    return memory ? ((int*)memory)[-1] - sizeof(int) : 0;
}

