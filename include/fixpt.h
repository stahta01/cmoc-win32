
#ifndef _FIXPT_H
#define _FIXPT_H

#include <cmoc/types.h>

int fxsin(byte x);
int fxcos(byte x);

#define fxtoi(A) (*(unsigned char*)&(A))

#endif

