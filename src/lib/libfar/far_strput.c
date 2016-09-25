
#include "_far.h"

void far_strput(far_char_t* dst, char* src)
{
    bank_t bank = bank_set(dst->bank);
    strcpy(dst->data, src);
    bank_set(bank);
}

