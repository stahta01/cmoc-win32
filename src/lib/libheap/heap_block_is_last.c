
#include "_heap.h"

bool heap_block_is_last(heap_block_t* block)
{
    return !*block;
}

