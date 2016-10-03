
/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

I dedicate any and all copyright interest in this software to the
public domain. I make this dedication for the benefit of the public at
large and to the detriment of my heirs and successors. I intend this
dedication to be an overt act of relinquishment in perpetuity of all
present and future rights to this software under copyright law.

Derek John Evans <https://sourceforge.net/u/buzzphp/profile/>
*/

#ifndef _FLOAT_H
#define _FLOAT_H

#include <sys/float.h>
#include <stdarg.h>

// float constants

#define M_2_PI  (*(float_t*)0xbfbd)
#define M_1     (*(float_t*)0xbac5)
#define M_1_2   (*(float_t*)0xbec0)
#define M_1_4   (*(float_t*)0xbfc2)
#define M_10    (*(float_t*)0xbb7d)

// float conversion functions

int _ftoi(float_t* src);
char* _ftoa(float_t* src, char* dst);
float_t* _itof(int src, float_t* dst);
float_t* _atof(char* src, float_t* dst);

// basic float functions

char _fsign(float_t* src);
float_t* _fadd(float_t* dst, float_t* fp1, float_t* fp2);
float_t* _fsub(float_t* dst, float_t* fp1, float_t* fp2);
float_t* _fmul(float_t* dst, float_t* fp1, float_t* fp2);
float_t* _fdiv(float_t* dst, float_t* fp1, float_t* fp2);
float_t* _fdiv10(float_t* dst, float_t* src);

// trigonometric functions

// Contributed by Brian K. Holman (me@brianholman.com)
// Based on information provided by Pierre Sarrazin <http://sarrazip.com/>
// Many thanks, Derek :-)

float_t* _fsin(float_t* dst, float_t* src);
float_t* _fcos(float_t* dst, float_t* src);
float_t* _ftan(float_t* dst, float_t* src);
float_t* _fatan(float_t* dst, float_t* src);

// exponential, logarithmic, and power functions

float_t* _flog(float_t* dst, float_t* src);
float_t* _fexp(float_t* dst, float_t* src);
float_t* _flog10(float_t* dst, float_t* src);
float_t* _flogbase(float_t* dst, float_t* src, float_t* base);
float_t* _fsqrt(float_t* dst, float_t* src);
float_t* _fpow(float_t* dst, float_t* base, float_t* power);
float_t* _froot(float_t* dst, float_t* base, float_t* root);

// rad/deg conversion functions

float_t* _fdeg(float_t* dst, float_t* rad);
float_t* _frad(float_t* dst, float_t* deg);

// a simple RPN calc for floats. only supports basic functions atm

float_t* _vfrpn(float_t* dst, va_list args);
float_t* _frpn(float_t* dst, ...);

// raw float constants

#define _FLOAT_SIZE 5

extern byte FP_ONE[_FLOAT_SIZE];
extern byte FP_MINUSONE[_FLOAT_SIZE];
extern byte FP_RAD_TO_DEG[_FLOAT_SIZE];
extern byte FP_PI[_FLOAT_SIZE];
extern byte FP_MAXEXP[_FLOAT_SIZE];
extern byte FP_LOGOF10[_FLOAT_SIZE];

// internal use only

void _fruny2(void);
void _fruny3(void);

#endif

