
#ifndef _MALLOC_H
#define _MALLOC_H

#include <sys/size.h>

void* malloc(int size);
void* calloc(int num, int size);
void free(void* mem);
int _msize(void* mem);
void* realloc(void* mem, int size);

extern int heap_memory[1];                      // INTERNAL USE ONLY

#define new(A)     ((A*)calloc(sizeof(A), 1))
#define delete(A)  free(A)

#endif

