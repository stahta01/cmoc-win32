
#include "_far.h"

void far_bank(bank_t bank, size_t size)
{
    bank = bank_set(bank);
    heman_init(BANK_MEMORY, (void*)(BANK_MEMORY + size));
    bank = bank_set(bank);
    for (int i = 0; i < far_banks.size; i++) {
        if (far_banks.data[i] == bank) {
            return;
        }
    }
    far_banks.data[far_banks.size++] = bank;
}

