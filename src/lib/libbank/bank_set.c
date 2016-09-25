
#include "_bank.h"

bank_t _static_bank = 15;

bank_t bank_set(bank_t bank)
{
    bank_t result = _static_bank;
    _static_bank = bank;
    asm {
        seif
    }
    byte page = (byte)(bank << 2) & 63;
    *(byte*)0xffa4 = page++;
    *(byte*)0xffa5 = page++;
    *(byte*)0xffa6 = page++;
    *(byte*)0xffa7 = page++;
    if (bank == 15) {
        *(byte*)0xffde = true;
        asm {
            clif
        }
    } else if (bank == 0) {
        *(byte*)0xffdf = true;
    }
    return result;
}

bank_t bank_get(void)
{
    return _static_bank;
}

