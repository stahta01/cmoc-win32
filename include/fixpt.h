
#ifndef _FIXPT_H
#define _FIXPT_H

#include <motorola/types.h>

int fxsin(int x);
int fxcos(int x);

#define _F2I(A) ((int)((sbyte*)&(A))[0])
#define _I2F(A) ((A)<<8)

#endif

