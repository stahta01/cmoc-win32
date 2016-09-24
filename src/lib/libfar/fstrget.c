
#include "_far.h"

void _fstrget(char* dst, fchar_t* src)
{
    bank_t bank = bank_set(src->bank);
    strcpy(dst, src->ptr);
    bank_set(bank);
}

