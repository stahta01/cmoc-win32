
#include "_heman.h"

int heman_size(void* memory)
{
    return memory ? ((int*)memory)[-1] - sizeof(int) : 0;
}

