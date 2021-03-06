
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

#ifndef _STDLIB_H
#define _STDLIB_H

#include <malloc.h>
#include <search.h>

#include <sys/long.h>
#include <sys/ulong.h>
#include <sys/div.h>
#include <sys/ldiv.h>

#define EXIT_SUCCESS    0
#define EXIT_FAILURE    1

#define RAND_MAX        0x7fff

// max. length of full pathname
#define _MAX_PATH       16

// max. length of drive component
#define _MAX_DRIVE      2

// max. length of path component
#define _MAX_DIR        0

// max. length of file name component
#define _MAX_FNAME      8

// max. length of extension component
#define _MAX_EXT        3

#define _max(_a,_b)     (((_a) > (_b)) ? (_a) : (_b))
#define _min(_a,_b)     (((_a) < (_b)) ? (_a) : (_b))
#define _abs(_a)        ((_a) < 0 ? -(_a) : (_a))

int max(int a, int b);                              // ANSIC
int min(int a, int b);                              // ANSIC
int abs(int n);                                     // ANSIC

int atexit(void(*func)(void));                      // TODO

int atoi(char* s);                                  // ANSIC

div_t* div(div_t* result, int numer, int denom);    // ANSIC
void exit(int status);                              // ANSIC
char* _getcmd(void);                                // REMOVE!
char* itoa(int value, char* s, int radix);          // ANSIC
char* utoa(unsigned value, char* s, int radix);     // ANSIC
char* ltoa(long_t* value, char* string, int radix); // ANSIC
int rand(void);                                     // ANSIC
void srand(unsigned seed);                          // ANSIC

int strtoi(char* str, char** endptr, int base);     // CMOC

int system(char* cmd);                              // ANSIC
int systemf(char* fmt, ...);                        // CMOC

// systemex() is the same as system, except it will raise exceptions.

void systemex(char* cmd);                           // CMOC

int putenv(char* envptr);                           // ANSIC
char* getenv(char* varname);                        // ANSIC

// Non-Standard access to BASIC variables

int putenvstr(char* name, char* value);             // CMOC
char* getenvstr(char* name, char* dst);             // CMOC
int putenvuint(char* name, unsigned value);         // CMOC
unsigned getenvuint(char* name);                    // CMOC

//void uldiv(uldiv_t* result, unsigned long numer, unsigned long denom);
//char* ultoa(unsigned long value, char* string, int radix);

void beep(int frequency, int duration);             // CMOC

#endif

