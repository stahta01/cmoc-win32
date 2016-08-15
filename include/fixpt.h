
#ifndef _FIXPT_H
#define _FIXPT_H

#include <cmoc/types.h>

int fxsin(byte x);
int fxcos(byte x);

#define int_hi(A) ((signed char*)&(A))[0]
#define int_lo(A) ((unsigned char*)&(A))[1]

#endif

