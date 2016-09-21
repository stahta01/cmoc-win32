
#ifndef _IFF_H
#define _IFF_H

#include <sys/long.h>

typedef struct {
    char type[4];
    long_t size;
} iff_head_t;

typedef struct {
    iff_head_t head;
    char type[4];
} iff_form_t;

bool iff_head_is(iff_head_t* head, char* type);
bool iff_head_read(iff_head_t* head, FILE* fp);

#endif

