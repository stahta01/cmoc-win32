
#ifndef _HEMAN_H
#define _HEMAN_H

void* heman_alloc(int* heap, int size);
void heman_free(void* m);
int heman_size(void* m);

#endif

