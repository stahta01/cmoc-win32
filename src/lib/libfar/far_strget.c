
#include "_far.h"

void far_strget(char* dst, far_char_t* src)
{
    bank_t bank = bank_set(src->bank);
    strcpy(dst, src->ptr);
    bank_set(bank);
}

