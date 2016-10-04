
#include "_hank.h"

hank_t* hank_create_clear(bank_t bank, heap_t* heap, size_t size)
{
    return hank_clear(hank_create(bank, heap), size);
}

