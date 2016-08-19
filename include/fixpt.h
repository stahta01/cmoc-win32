
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

#endif

