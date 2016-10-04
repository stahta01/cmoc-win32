
/*****************************************************************************/
/*                                                                           */
/*                                  stdio.h                                  */
/*                                                                           */
/*                               Input/output                                */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* (C) 1998-2011, Ullrich von Bassewitz                                      */
/*                Roemerstrasse 52                                           */
/*                D-70794 Filderstadt                                        */
/* EMail:         uz@cc65.org                                                */
/*                                                                           */
/*                                                                           */
/* This software is provided 'as-is', without any expressed or implied       */
/* warranty.  In no event will the authors be held liable for any damages    */
/* arising from the use of this software.                                    */
/*                                                                           */
/* Permission is granted to anyone to use this software for any purpose,     */
/* including commercial applications, and to alter it and redistribute it    */
/* freely, subject to the following restrictions:                            */
/*                                                                           */
/* 1. The origin of this software must not be misrepresented; you must not   */
/*    claim that you wrote the original software. If you use this software   */
/*    in a product, an acknowledgment in the product documentation would be  */
/*    appreciated but is not required.                                       */
/* 2. Altered source versions must be plainly marked as such, and must not   */
/*    be misrepresented as being the original software.                      */
/* 3. This notice may not be removed or altered from any source              */
/*    distribution.                                                          */
/*                                                                           */
/*****************************************************************************/

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
extern FILE* stdin;
extern FILE* stdout;
extern FILE* stderr;

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

void clearerr(FILE* fp);
int fclose(FILE* fp);
int feof(FILE* fp);
int ferror(FILE* fp);
int fflush(FILE* fp);
int fgetc(FILE* fp);
char* fgets(char* buf, size_t size, FILE* fp);
FILE* fopen(char* name, char* mode);
int fprintf(FILE* fp, char* fmt, ...);
int fputc(int c, FILE* fp);
int fputs(char* s, FILE* fp);
size_t fread(void* buf, size_t size, size_t count, FILE* fp);
FILE* freopen(char* name, char* mode, FILE* f);
size_t fwrite(void* buf, size_t size, size_t count, FILE* fp);
int fgetpos(FILE* fp, fpos_t* pos);
int fsetpos(FILE* fp, fpos_t* pos);
size_t ftell(FILE* fp);
int fseek(FILE* fp, size_t offset, int whence);
void rewind(FILE* fp);
int getchar(void);
char* gets(char* s);
void perror(char* s);
//int vfprintf(FILE* f, char* format, va_list ap);
int vprintf(char* fmt, va_list args);
int printf(char* fmt, ...);
int putchar(int c);
int puts(char* s);
int remove(char* name);
int rename(char* oldname, char* newname);
int ungetc(int c, FILE* fp);


// scanf functions are not written yet...

//int scanf(char* fmt, ...);
//int vfscanf(FILE* fp, char* fmt, va_list args);
//int fscanf(FILE* fp, char* fmt, ...);
//int vscanf(char* fmt, va_list args);

size_t _fsize(FILE* fp);                        // CMOC

// Masking macros for some functions
#define getc(_f)        fgetc(_f)               // ANSI
#define putc(_c,_f)     fputc(_c,_f)            // ANSI

#endif

