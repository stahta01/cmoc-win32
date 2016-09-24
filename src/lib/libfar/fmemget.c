
#include "_far.h"

void _fmemget(void* dst, fvoid_t* src, size_t n)
{
    bank_t bank = bank_set(src->bank);
    memcpy(dst, src->ptr, n);
    bank_set(bank);
}

