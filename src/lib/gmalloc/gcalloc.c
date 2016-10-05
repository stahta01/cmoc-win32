
#include "_gmalloc.h"

void* gcalloc(size_t count, size_t size)
{
    return heap_calloc(gheap(), count, size);
}

