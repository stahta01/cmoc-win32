
#include "_far.h"

void far_memget(void* dst, far_void_t* src, size_t n)
{
    bank_t bank = bank_set(src->bank);
    memcpy(dst, src->ptr, n);
    bank_set(bank);
}

