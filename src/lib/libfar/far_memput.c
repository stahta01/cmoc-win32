
#include "_far.h"

void far_memput(far_void_t* dst, void* src, size_t size)
{
    bank_t bank = bank_set(dst->bank);
    memcpy(dst->data, src, size);
    bank_set(bank);
}

