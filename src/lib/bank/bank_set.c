
#include "_bank.h"

bank_t _static_bank = BANK_DEFAULT;

bank_t bank_set(bank_t bank)
{
    bank_t result = _static_bank;
    _static_bank = bank;
    asm {
        seif
    }
    if (machine.typ == MAC_TYP_COCO3) {
        byte page = (byte)(bank << 2) & 63;
        _mmureg[4] = page + 0;
        _mmureg[5] = page + 1;
        _mmureg[6] = page + 2;
        _mmureg[7] = page + 3;
    } else {
        if (bank == BANK_DEFAULT) {
            _romclr = true;
        } else {
            _romset = true;
        }
    }
    if (bank == BANK_DEFAULT) {
        asm {
            clif
        }
    }
    return result;
}

bank_t bank_get(void)
{
    return _static_bank;
}

