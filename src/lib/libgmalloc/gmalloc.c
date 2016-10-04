
#include "_gmalloc.h"

void* gmalloc(size_t size)
{
    return heap_malloc(gheap(), size);
}

