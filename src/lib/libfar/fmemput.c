
#include "_far.h"

void _fmemput(fvoid_t* dst, void* src, size_t n)
{
    bank_t bank = bank_set(dst->bank);
    memcpy(dst->ptr, src, n);
    bank_set(bank);
}

