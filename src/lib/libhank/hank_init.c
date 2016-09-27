
#include "_hank.h"

hank_t* hank_init(hank_t* hank, bank_t bank, heap_t* heap)
{
    hank->bank = bank;
    hank->heap = heap;
    return hank;
}

