
#ifndef _FLOAT_H
#define _FLOAT_H

typedef struct {
    char a[5];
} float_t;

void _itof(float_t* dst, int src);
int _ftoi(float_t* src);
void _ftoa(char* dst, float_t* src);
void _atof(float_t* dst, char* src);

void _fadd(float_t* dst, float_t* fp1, float_t* fp2);
void _fsub(float_t* dst, float_t* fp1, float_t* fp2);
void _fmul(float_t* dst, float_t* fp1, float_t* fp2);
void _fdiv(float_t* dst, float_t* fp1, float_t* fp2);
void _fdiv10(float_t* dst, float_t* src);

#endif

