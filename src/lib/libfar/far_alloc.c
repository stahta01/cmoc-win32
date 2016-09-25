
#include "_far.h"

far_void_t* far_alloc(far_void_t* dst, size_t size)
{
    dst->data = nullptr;
    for (int i = 0; i < far_banks.size; i++) {
        bank_t bank = bank_set(far_banks.data[i]);
        dst->data = heman_alloc(BANK_MEMORY, size);
        dst->bank = bank_set(bank);
        if (dst->data) {
            break;
        }
    }
    return dst;
}

