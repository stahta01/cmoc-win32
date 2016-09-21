
#include "_malloc.h"

void* calloc(size_t n, size_t s)
{
    void* m = malloc(n *= s);
    return m ? memset(m, 0, n) : (void*)nullptr;
}

