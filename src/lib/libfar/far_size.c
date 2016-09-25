
#include "_far.h"

size_t far_size(far_void_t* memory)
{
    bank_t bank = bank_set(memory->bank);
    size_t size = heman_size(memory->ptr);
    bank_set(bank);
    return size;
}

