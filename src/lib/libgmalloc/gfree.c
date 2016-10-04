
#include "_gmalloc.h"

void gfree(void* memory)
{
    heap_free(memory);
}

