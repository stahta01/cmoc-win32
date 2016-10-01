
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

#ifndef _OS9_H
#define _OS9_H

// For information about these functions, please read:
// https://sourceforge.net/p/nitros9/wiki/C_Compiler_User's_Guide/

#include <sys/clock.h>
#include <sys/size.h>

char* _strend(char* str);
char* _strass(char* s1, char* s2, size_t count);
char* _strhcpy(char* s1, char* s2);
char* _strclr(char* str);
char* _reverse(char* str);
char* _itoa(int src, char* dst);
char* _utoa(unsigned src, char* dst);
unsigned _umin(unsigned a, unsigned b);
unsigned _umax(unsigned a, unsigned b);
void _tsleep(clock_t ticks);
word _swab(word val);

// Note: pos starts at 1. Returns 0 = not found, or > 0 for char pos (1 based).

int _findstr(int pos, char* str, char* pat);
int _findnstr(int pos, char* str, char* pat, size_t len);

// Non documented OS9, but are used by OS9 via KreiderLib

bool _patmatch(char* pat, char* str, bool ignorecase);

#endif

