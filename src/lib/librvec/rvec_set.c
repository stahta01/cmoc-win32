
#include "_rvec.h"

void rvec_set(rvec_t* rvec, int n)
{
    ((rvec_t*)0x15e)[n] = *rvec;
}

