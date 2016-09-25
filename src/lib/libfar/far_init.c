
#include "_far.h"

void far_init(bank_t bank)
{
    bank = bank_set(bank);
    heman_init(0x8000, 0xff00);
    bank_set(bank);
}

