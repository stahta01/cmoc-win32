
#include "_hank.h"

hank_t* hank_malloc(void** data, size_t size)
{
    for (int i = 0; i < hanks.size; i++) {
        hank_t* hank = &hanks.data[i];
        bank_t bank = bank_set(hank->bank);
        *data = heap_malloc(hank->heap, size);
        bank_set(bank);
        if (*data) {
            return hank;
        }
    }
    *data = nullptr;
    return nullptr;
}

