
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

#ifndef _STRING_H
#define _STRING_H

#include <sys/errno.h>

#include <stddef.h>
#include <memory.h>

char* strcat(char* dst, char* src);                 // ANSIC
char* strchr(char* s, int c);                       // ANSIC
char* strcpy(char* dst, char* src);                 // ANSIC
char* strdup(char* s);                              // SYSV/BSD
char* strerror(int errcode);                        // ANSIC
char* strncat(char* s1, char* s2, size_t n);        // ANSIC
char* strncpy(char* dst, char* src, size_t n);      // ANSIC
char* strrchr(char* s, int c);                      // ANSIC
char* strstr(char* str, char* substr);              // ANSIC
char* strtok(char* s1, char* s2);                   // ANSIC

int strmemcmp(char* str, char* mem, size_t size);   // CMOC
char* stpcpy(char* dst, char* src);                 // CMOC
char* strlwr(char* str);                            // UNIX
char* strrev(char* str);                            // CMOC
char* strupr(char* str);                            // UNIX

//char* _strqtok(char* s1, char* s2);               // UNIX
//char* _strlower(char* s);                         // UNIX
//char* _strupper(char* s);                         // UNIX

int strcasecmp(char* s1, char* s2);                 // UNIX
int strcmp(char* s1, char* s2);                     // ANSIC
int strcoll(char* s1, char* s2);                    // ANSIC
int stricmp(char* s1, char* s2);                    // DOS/Windows
int strncasecmp(char* s1, char* s2, size_t n);      // UNIX
int strncmp(char* s1, char* s2, size_t n);          // ANSIC
int strnicmp(char* s1, char* s2, size_t n);         // DOS/Windows
int strtoi(char* s, char** endptr, int radix);      // CMOC

size_t strcspn(char* s1, char* s2);                 // ANSIC
size_t strlen(char* s);                             // ANSIC
size_t strspn(char* s1, char* s2);                  // ANSIC
size_t strxfrm(char* s1, char* s2, size_t n);       // ANSIC

char* strerror(errno_t error);                      // ANSIC

#define _stroserror strerror                        // CC65

#endif

