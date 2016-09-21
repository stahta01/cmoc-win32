
#include "_heman.h"

void heman_init(int* heap, void* end)
{
    heap[0] = end;
    heap[1] = 0;
}

