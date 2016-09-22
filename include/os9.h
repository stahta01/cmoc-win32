
#ifndef _OS9_H
#define _OS9_H

#include <time.h>

void _tsleep(clock_t ticks);
char* _strend(char* str);
char* _strass(char* s1, char* s2, size_t count);
char* _strhcpy(char* s1, char* s2);
char* _strclr(char* str);
char* _reverse(char* str);
unsigned _umin(unsigned a, unsigned b);
unsigned _umax(unsigned a, unsigned b);

#endif
