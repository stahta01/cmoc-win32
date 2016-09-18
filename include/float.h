
#ifndef _FLOAT_H
#define _FLOAT_H

#include <sys/float.h>
#include <stdarg.h>

#define M_2_PI  ((float_t*)0xbfbd)
#define M_1     ((float_t*)0xbac5)
#define M_1_2   ((float_t*)0xbec0)
#define M_1_4   ((float_t*)0xbfc2)
#define M_10    ((float_t*)0xbb7d)

int _ftoi(float_t* src);
char* _ftoa(char* dst, float_t* src);
float_t* _itof(float_t* dst, int src);
float_t* _atof(float_t* dst, char* src);

float_t* _fadd(float_t* dst, float_t* fp1, float_t* fp2);
float_t* _fsub(float_t* dst, float_t* fp1, float_t* fp2);
float_t* _fmul(float_t* dst, float_t* fp1, float_t* fp2);
float_t* _fdiv(float_t* dst, float_t* fp1, float_t* fp2);
float_t* _fdiv10(float_t* dst, float_t* src);

float_t* _vfrpn(float_t* dst, va_list args);
float_t* _frpn(float_t* dst, ...);

#endif

