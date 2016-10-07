
#include "_memory.h"

void bzero(void* ptr, size_t n)
{
    memset(ptr, 0, n);
}
