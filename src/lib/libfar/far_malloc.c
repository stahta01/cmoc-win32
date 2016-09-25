
#include "_far.h"

far_void_t* far_malloc(far_void_t* dst, size_t size)
{
    for (int i = 0; i < hanks.size; i++) {
        dst->hank = &hanks.data[i];
        bank_t bank = bank_set(dst->bank = dst->hank->bank);
        dst->data = heap_malloc(dst->hank->heap, size);
        bank_set(bank);
        if (dst->data) {
            return dst;
        }
    }
    dst->hank = nullptr;
    dst->data = nullptr;
    return dst;
}

