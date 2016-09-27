
#ifndef _SYS_LDIV_H
#define _SYS_LDIV_H

#include <sys/long.h>

typedef struct _ldiv_t {
    long_t quot;
    long_t rem;
} ldiv_t;

#endif
