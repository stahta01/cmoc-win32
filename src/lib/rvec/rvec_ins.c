
#include "_rvec.h"

void rvec_ins(rvec_t* dst, int n, void* addr)
{
    *dst = _rvecs[n];
    _rvecs[n].inst = 0x7e;
    _rvecs[n].addr = addr;
}

