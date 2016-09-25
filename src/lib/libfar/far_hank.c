
#include "_far.h"

hank_t* far_hank(heap_t* heap, bank_t bank, size_t size)
{
    bank = bank_set(bank);
    heap_init(heap, size);
    bank = bank_set(bank);
    hank_t* hank = &hanks.data[hanks.size++];
    hank->heap = heap;
    hank->bank = bank;
    return hank;
}

