
#include "_malloc.h"

void* calloc(int n, int s)
{
    void* m = malloc(n *= s);
    return m ? memset(m, 0, n) : (void*)0;
}

