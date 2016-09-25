
#include "_far.h"

far_void_t* far_alloc(far_void_t* memory, size_t size)
{
    bank_t bank = bank_set(memory->bank);
    memory->ptr = heman_alloc(0x8000, size);
    bank_set(bank);
    return memory;
}


