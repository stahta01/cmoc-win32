
#include "_gmalloc.h"

void* grealloc(void* memory, size_t size)
{
    return heap_realloc(gheap(), memory, size);
}

