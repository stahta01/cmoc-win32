
#include "_heap.h"

size_t heap_block_size(heap_block_t* block)
{
    return *block < 0 ? -*block : *block;
}

