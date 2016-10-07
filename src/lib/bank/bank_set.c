
#include "_bank.h"

bank_t _static_bank = 15;

void bank_set_mmu(bank_t bank)
{
    byte page = (byte)(bank << 2) & 63;
    _mmureg[4] = page + 0;
    _mmureg[5] = page + 1;
    _mmureg[6] = page + 2;
    _mmureg[7] = page + 3;
}

bank_t bank_set(bank_t bank)
{
    asm {
        seif
    }
    switch (bank) {
    case 0:
        bank_set_mmu(15);
        _romset = true;
        break;
    case 15:
        bank_set_mmu(15);
        _romclr = true;
        asm {
            clif
        }
        break;
    default:
        bank_set_mmu(bank);
        break;
    }
    bank_t result = _static_bank;
    _static_bank = bank;
    return result;
}

bank_t bank_get(void)
{
    return _static_bank;
}

