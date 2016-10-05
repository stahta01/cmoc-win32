
#include "_heap.h"

bool heap_block_is_used(heap_block_t* block)
{
    return *block > 0;
}

