
#include "_far.h"

void _fstrput(fchar_t* dst, char* src)
{
    bank_t bank = bank_set(dst->bank);
    strcpy(dst->ptr, src);
    bank_set(bank);
}

