
#include "_rvec.h"

void rvec_get(rvec_t* rvec, int n)
{
    *rvec = ((rvec_t*)0x15e)[n];
}

