
#ifndef _SYS_ULONG_H
#define _SYS_ULONG_H

typedef struct {
    word hi;
    word lo;
} _CRT_ULONG, ulong_t;

typedef struct _uldiv_t {
    ulong_t quot;
    ulong_t rem;
} uldiv_t;

#endif

