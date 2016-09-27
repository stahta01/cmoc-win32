
#include "_hank.h"

hank_t* hank_create(bank_t bank, heap_t* heap)
{
    return hank_init(&hanks.data[hanks.size++], bank, heap);
}

