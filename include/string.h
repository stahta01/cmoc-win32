
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
#include <memory.h>

char* strcat(char* dst, char* src);             // ANSIC
char* strchr(char* s, int c);                   // ANSIC
int strcmp(char* s1, char* s2);                 // ANSIC
int strcoll(char* s1, char* s2);                // ANSIC
char* strcpy(char* dst, char* src);             // ANSIC
size_t strcspn(char* s1, char* s2);             // ANSIC
char* strerror(int errcode);                    // ANSIC
size_t strlen(char* s);                         // ANSIC
char* strncat(char* s1, char* s2, size_t n);    // ANSIC
int strncmp(char* s1, char* s2, size_t n);      // ANSIC
char* strncpy(char* dst, char* src, size_t n);  // ANSIC
char* strrchr(char* s, int c);                  // ANSIC
size_t strspn(char* s1, char* s2);              // ANSIC
char* strstr(char* str, char* substr);          // ANSIC
char* strtok(char* s1, char* s2);               // ANSIC
size_t strxfrm(char* s1, char* s2, size_t n);   // ANSIC

int strtoi(char* s, char** endptr, int radix);  // CMOC

char* strdup(char* s);                          // SYSV/BSD
int strcasecmp(char* s1, char* s2);             // UNIX
int strncasecmp(char* s1, char* s2, size_t n);  // UNIX
int stricmp(char* s1, char* s2);                // DOS/Windows
int strnicmp(char* s1, char* s2, size_t n);     // DOS/Windows

char* _strlwr(char* s);                         // UNIX
char* _strlower(char* s);                       // UNIX
char* _strupr(char* s);                         // UNIX
char* _strupper(char* s);                       // UNIX
char* _strqtok(char* s1, char* s2);             // UNIX

char* _strrev(char* s);                         // CMOC
char* _stpcpy(char* dst, char* src);            // CMOC

// Map an operating system error number to an error message.

char* _stroserror(unsigned char errcode);

#endif

