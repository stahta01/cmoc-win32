
#include "_memory.h"

void _bzero(void* ptr, size_t n)
{
    memset(ptr, 0, n);
}
