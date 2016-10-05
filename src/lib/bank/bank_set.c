
#include "_bank.h"
#include <coco/coco3.h>

bank_t _static_bank = 15;

bank_t bank_set(bank_t bank)
{
    bank_t result = _static_bank;
    _static_bank = bank;
    asm {
        seif
    }
    byte page = (byte)(bank << 2) & 63;
    _mmureg[4] = page + 0;
    _mmureg[5] = page + 1;
    _mmureg[6] = page + 2;
    _mmureg[7] = page + 3;
    if (bank == 15) {
        _romclr = true;
        asm {
            clif
        }
    } else if (bank == 0) {
        _romset = true;
    }
    return result;
}

bank_t bank_get(void)
{
    return _static_bank;
}

