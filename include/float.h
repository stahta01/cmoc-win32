
#ifndef _FLOAT_H
#define _FLOAT_H

#define M_2_PI  ((float_t*)0xbfbd)
#define M_1     ((float_t*)0xbac5)
#define M_1_2   ((float_t*)0xbec0)
#define M_1_4   ((float_t*)0xbfc2)
#define M_10    ((float_t*)0xbb7d)

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

