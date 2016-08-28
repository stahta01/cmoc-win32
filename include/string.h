
/*****************************************************************************/
/*                                                                           */
/*                                 string.h                                  */
/*                                                                           */
/*                              String handling                              */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* (C) 1998-2014, Ullrich von Bassewitz                                      */
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

#ifndef _STRING_H
#define _STRING_H

#include <stddef.h>

char* strcat(char* dest, const char* src);
char* strchr(const char* s, int c);
int strcmp(const char* s1, const char* s2);
int strcoll(const char* s1, const char* s2);
char* strcpy(char* dest, const char* src);
size_t strcspn(const char* s1, const char* s2);
char* strerror(int errcode);
size_t strlen(const char* s);
char* strncat(char* s1, const char* s2, size_t count);
int strncmp(const char* s1, const char* s2, size_t count);
char* strncpy(char* dest, const char* src, size_t count);
char* strrchr(const char* s, int c);
size_t strspn(const char* s1, const char* s2);
char* strstr(const char* str, const char* substr);
char* strtok(char* s1, const char* s2);
size_t strxfrm(char* s1, const char* s2, size_t count);
void* memchr(const void* mem, int c, size_t count);
int memcmp(const void* p1, const void* p2, size_t count);
void* memcpy(void* dest, const void* src, size_t count);
void* memmove(void* dest, const void* src, size_t count);
void* memset(void* s, int c, size_t count);

/* The following is an internal function, the compiler will replace memset
** with it if the fill value is zero. Never use this one directly!
*/
void* _bzero(void* ptr, size_t n);

/* Non standard: */
void bzero(void* ptr, size_t n);                 /* BSD */
char* strdup(const char* s);                     /* SYSV/BSD */
int stricmp(const char* s1, const char* s2);     /* DOS/Windows */
int strcasecmp(const char* s1, const char* s2);  /* Same for Unix */
int strnicmp(const char* s1, const char* s2, size_t count);      /* DOS/Windows */
int strncasecmp(const char* s1, const char* s2, size_t count);   /* Same for Unix */
char* strlwr(char* s);
char* strlower(char* s);
char* strupr(char* s);
char* strupper(char* s);
char* strqtok(char* s1, const char* s2);

char* strrev(char* s);
char* stpcpy(char* dest, char* src);

const char* _stroserror(unsigned char errcode);
/* Map an operating system error number to an error message. */



void memcpy_fast(void* dst, void* src, size_t len);

#endif

