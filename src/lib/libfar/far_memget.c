
#include "_far.h"

void far_memget(void* dst, far_void_t* src, size_t size)
{
    bank_t bank = bank_set(src->bank);
    memcpy(dst, src->data, size);
    bank_set(bank);
}

