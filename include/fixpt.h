
#ifndef _FIXPT_H
#define _FIXPT_H

#include <motorola/types.h>

typedef struct {
    int v;
    union {
        sbyte h;
        byte l;
    };
} fixed_t;

int fxsin(int x);
int fxcos(int x);

#define i2f(x) ((x)<<8)
#define f2i(x) ((x)>>8)

// OLD!!!!
#define _i2f(x) ((x)<<8)
#define _f2i(x) ((int)((char*)&(x))[0])

#endif

