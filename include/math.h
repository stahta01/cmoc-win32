
#ifndef _MATH_H
#define _MATH_H

#include <stddef.h>

#define _i2f(x) ((x)<<8)
#define _f2i(x) ((int)((sbyte*)&(x))[0])

int sqrt(int a);

#endif

