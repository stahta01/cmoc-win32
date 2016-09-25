
#include "_hank.h"

hank_t* hank_create(heap_t* heap, bank_t bank, size_t size)
{
    bank = bank_set(bank);
    heap_init(heap, size);
    bank = bank_set(bank);
    hank_t* hank = &hanks.data[hanks.size++];
    hank->heap = heap;
    hank->bank = bank;
    return hank;
}

