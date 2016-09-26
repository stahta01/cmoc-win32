
#include "_heap.h"

heap_block_t* heap_block_next(heap_block_t* block)
{
    return (heap_block_t*)(*block ? (int)block + (*block < 0  ? -*block : *block) : nullptr);
}

