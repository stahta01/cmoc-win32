
#include "_heap.h"

bool heap_block_is_free(heap_block_t* block)
{
    return *block < 0;
}

