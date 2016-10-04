
#include "_hank.h"

hank_t* hank_clear(hank_t* hank, size_t size)
{
    bank_t bank = bank_set(hank->bank);
    heap_init(hank->heap, size);
    bank_set(bank);
    return hank;
}

