
#ifndef _STDLIB_H
#define _STDLIB_H

#include <stddef.h>
#include <crt.h>
#include <math.h>

#include <sys/size.h>

#define EXIT_SUCCESS    0
#define EXIT_FAILURE    1

#define RAND_MAX        0x7fff

// max. length of full pathname
#define _MAX_PATH       260

// max. length of drive component
#define _MAX_DRIVE      4

// max. length of path component
#define _MAX_DIR        256

// max. length of file name component
#define _MAX_FNAME      256

// max. length of extension component
#define _MAX_EXT        3

#define _sys_nerr       (_crt_base->_crt_nerr)
#define _sys_errlist    (_crt_base->_crt_syserrlist)

// Return type of the div function
typedef struct {
    int rem;
    int quot;
} div_t;

typedef struct _ldiv_t {
    long quot;
    long rem;
} ldiv_t;

typedef struct _uldiv_t {
    unsigned long quot;
    unsigned long rem;
} uldiv_t;

#define _max(_a,_b)     (((_a) > (_b)) ? (_a) : (_b))
#define _min(_a,_b)     (((_a) < (_b)) ? (_a) : (_b))
#define _abs(_a)        ((_a) < 0 ? -(_a) : (_a))

int max(int a, int b);
int min(int a, int b);
int abs(int n);

void* malloc(int size);
void* calloc(int num, int size);
void free(void* mem);
int _msize(void* mem);
void* realloc(void* mem, int size);

int atoi(char* string);
//long atol(char* string);
int atexit(void(*func)(void));
void* bsearch(void* keyval, void* base, size_t num, size_t width,
              int(*cmp)(void* keyval, void* elem));

void div(div_t* result, int numer, int denom);
void exit(int status);
char* _getcmd(void);
char* itoa(int value, char* string, int radix);
char* utoa(unsigned value, char* string, int radix);
void ldiv(ldiv_t* result, long numer, long denom);
char* ltoa(long value, char* string, int radix);
void qsort(void* base, size_t num, size_t width, int(*cmp)(void* elem1, void* elem2));
int rand(void);
void srand(unsigned int seed);
long strtol(char* nptr, char** endptr, int base);
unsigned long strtoul(char* nptr, char** endptr, int base);

int system(char* cmd);
int systemf(char* fmt, ...);

int putenv(char* envptr);
char* getenv(char* varname);

// Non-Standard access to BASIC variables
int putenvstr(char* name, char* value);
char* getenvstr(char* name, char* dst);
int putenvuint(char* name, unsigned value);
unsigned getenvuint(char* name);

void uldiv(uldiv_t* result, unsigned long numer, unsigned long denom);
char* ultoa(unsigned long value, char* string, int radix);

void beep(unsigned char _Frequency, unsigned _Duration);

extern int heap_memory[1]; // INTERNAL USE ONLY

#endif

