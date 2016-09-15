
#ifndef _MEM_H
#define _MEM_H

#include <sys/size.h>

int memcmp(void* ptr1, void* ptr2, size_t n);   // ANSIC
void* memcpy(void* dst, void* src, size_t n);   // ANSIC
void* memmove(void* dst, void* src, size_t n);  // ANSIC

void* memchr(void* dst, int value, size_t n);   // ANSIC
void* memset(void* dst, int value, size_t n);   // ANSIC

void  memcom(void* dst, size_t n);              // CMOC
void* memxor(void* dst, int value, size_t n);   // CMOC
void* memand(void* dst, int value, size_t n);   // CMOC
void* memor(void* dst, int value, size_t n);    // CMOC

void bzero(void* dst, size_t n);                // BSD

void* memccpy(void* dst, void* src, int c, size_t count); // CMOC

#endif

