
#include "_malloc.h"

void* calloc(size_t count, size_t size)
{
    void* memory = malloc(size *= count);
    return memory ? memset(memory, 0, size) : (void*)nullptr;
}

