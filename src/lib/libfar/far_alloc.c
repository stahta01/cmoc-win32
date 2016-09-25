
#include "_far.h"

far_void_t* far_alloc(far_void_t* memory, size_t size)
{
    memory->data = nullptr;
    for (int i = 0; i < far_banks.size; i++) {
        bank_t bank = bank_set(far_banks.data[i]);
        memory->data = heman_alloc(BANK_MEMORY, size);
        memory->bank = bank_set(bank);
        if (memory->data) {
            break;
        }
    }
    return memory;
}

