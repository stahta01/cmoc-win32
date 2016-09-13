
#ifndef _MEMORY_H
#define _MEMORY_H

#include <sys/size.h>

int memcmp(void* ptr1, void* ptr2, size_t n);   // ANSIC
void* memcpy(void* dst, void* src, size_t n);   // ANSIC
void* memmove(void* dst, void* src, size_t n);  // ANSIC

void* memchr(void* ptr, int value, size_t n);   // ANSIC
void* memset(void* ptr, int value, size_t n);   // ANSIC

void  memcom(void* ptr, size_t n);              // CMOC
void* memxor(void* ptr, int value, size_t n);   // CMOC
void* memand(void* ptr, int value, size_t n);   // CMOC
void* memor(void* ptr, int value, size_t n);    // CMOC

void bzero(void* ptr, size_t n);                // BSD

#endif

