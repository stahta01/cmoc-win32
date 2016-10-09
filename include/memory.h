
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

#ifndef _MEMORY_H
#define _MEMORY_H

#include <sys/size.h>

int memcmp(void* ptr1, void* ptr2, size_t size);    // ANSIC
void* memchr(void* dst, int val, size_t size);      // ANSIC

void* memcpy(void* dst, void* src, size_t size);    // ANSIC

void* memmove(void* dst, void* src, size_t size);   // ANSIC
void* memset(void* dst, int val, size_t size);      // ANSIC

void* memlsr(void* dst, size_t size);               // CMOC
void* memlsl(void* dst, size_t size);               // CMOC
void* memror(void* dst, int val, size_t size);      // CMOC
void* memrol(void* dst, int val, size_t size);      // CMOC

void* memrol2(void* dst, int val, size_t size);     // CMOC
void* memror2(void* dst, int val, size_t size);     // CMOC

void* memand(void* dst, int val, size_t size);      // CMOC
void* memccpy(void* dst, void* src,
              int val, size_t size);                // CMOC

void* memcpy16(void* dst, void* src, size_t size);  // CMOC
void* memor(void* dst, int val, size_t size);       // CMOC
void* memxor(void* dst, int val, size_t size);      // CMOC
void  memcom(void* dst, size_t size);               // CMOC
void* memcpy_r(void* dst, void* src, size_t size);  // CMOC

void memcpy_unpack(void* dst, void* src, size_t count,
                   size_t size, size_t dstoff);     // CMOC

void memset_w(void* dst, word val, size_t size);    // CMOC

void bzero(void* dst, size_t size);                 // BSD

#endif

