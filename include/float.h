
#ifndef _FLOAT_H
#define _FLOAT_H

typedef struct {
    char a[5];
} float_t;

void _itof(float_t* f, int val);
int _ftoi(float_t* f);

#endif

