
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

#ifndef _STDIO_H
#define _STDIO_H

#include <sys/dev.h>
#include <sys/fpos.h>

#include <stddef.h>
#include <sprintf.h>
#include <sscanf.h>

typedef struct {
    dev_t   dev;
    int     eof;
} FILE;

// Standard file descriptors

extern FILE* stderr;
extern FILE* stdin;
extern FILE* stdout;

// Standard defines

#define _IOFBF          0
#define _IOLBF          1
#define _IONBF          2
#define BUFSIZ          256
#define EOF             -1
// FOPEN_MAX does not include the default printer(-2), cas(-1) and screen(0) files.
#define FOPEN_MAX       15
#define SEEK_CUR        0
#define SEEK_END        1
#define SEEK_SET        2
#define TMP_MAX         256

#define FILENAME_MAX    (16+1)
#define L_tmpnam        FILENAME_MAX

//int vfprintf(FILE* f, char* format, va_list ap);

char* fgets(char* buf, size_t size, FILE* fp);  // ANSIC
char* gets(char* str);                          // ANSIC

FILE* fopen(char* name, char* mode);            // ANSIC
//FILE* freopen(char* name, char* mode, FILE* f);

int fclose(FILE* fp);                           // ANSIC
int feof(FILE* fp);                             // ANSIC
int ferror(FILE* fp);                           // ANSIC
int fflush(FILE* fp);                           // ANSIC
int fgetc(FILE* fp);                            // ANSIC
int fgetpos(FILE* fp, fpos_t* pos);             // ANSIC
int fprintf(FILE* fp, char* fmt, ...);          // ANSIC
int fputc(int chr, FILE* fp);                   // ANSIC
int fputs(char* str, FILE* fp);                 // ANSIC
int fseek(FILE* fp, size_t offset, int whence); // ANSIC
int fsetpos(FILE* fp, fpos_t* pos);             // ANSIC
int getchar(void);                              // ANSIC
int printf(char* fmt, ...);                     // ANSIC
int putchar(int chr);                           // ANSIC
int puts(char* str);                            // ANSIC
int remove(char* name);                         // ANSIC
int rename(char* oldname, char* newname);       // ANSIC
int ungetc(int chr, FILE* fp);                  // ANSIC
int vprintf(char* fmt, va_list args);           // ANSIC

size_t fread(void* buf, size_t size, size_t count, FILE* fp);
size_t ftell(FILE* fp);
size_t fwrite(void* buf, size_t size, size_t count, FILE* fp);

void clearerr(FILE* fp);
void perror(char* str);
void rewind(FILE* fp);

// scanf functions are not written yet...

//int scanf(char* fmt, ...);
//int vfscanf(FILE* fp, char* fmt, va_list args);
//int fscanf(FILE* fp, char* fmt, ...);
//int vscanf(char* fmt, va_list args);

size_t _fsize(FILE* fp);                        // CMOC

#define getc(_f)        fgetc(_f)               // ANSI
#define putc(_c,_f)     fputc(_c,_f)            // ANSI

#endif

