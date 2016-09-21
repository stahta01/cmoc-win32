
#ifndef _MALLOC_H
#define _MALLOC_H

#include <sys/size.h>

void* malloc(size_t size);
void* calloc(size_t num, size_t size);
void free(void* mem);
size_t _msize(void* mem);
void* realloc(void* mem, size_t size);

extern int heap_memory[1];                      // INTERNAL USE ONLY

#define new(A)     ((A*)calloc(sizeof(A), 1))
#define delete(A)  free(A)

#endif

