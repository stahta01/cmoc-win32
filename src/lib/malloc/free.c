
#include "_malloc.h"

void free(void* memory)
{
    heap_free(memory);
}

