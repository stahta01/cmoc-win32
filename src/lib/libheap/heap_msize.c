
#include "_heap.h"

size_t heap_msize(void* memory)
{
    return memory && ((int*)memory)[-1] > sizeof(int) ? ((int*)memory)[-1] - sizeof(int) : 0;
}

