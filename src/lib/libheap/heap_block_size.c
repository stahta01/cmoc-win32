
#include "_heap.h"

int heap_block_size(heap_block_t* block)
{
    return *block < 0 ? -*block : *block;
}

