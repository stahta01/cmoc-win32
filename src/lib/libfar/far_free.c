
#include "_far.h"

void far_free(far_void_t* memory)
{
    bank_t bank = bank_set(memory->bank);
    heman_free(memory->ptr);
    bank_set(bank);
}

