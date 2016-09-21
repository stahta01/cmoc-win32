
#ifndef _IFF_H
#define _IFF_H

#include <sys/long.h>

typedef struct {
    char type[4];
    long_t size;
} iff_chunk_t;

typedef struct {
    iff_chunk_t chunk;
    char type[4];
} iff_form_t;

#endif

