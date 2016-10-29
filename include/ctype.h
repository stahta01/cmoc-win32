
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

#ifndef _CTYPE_H
#define _CTYPE_H

#define CTYPE_CONTROL       0x01
#define CTYPE_UPPER         0x02
#define CTYPE_LOWER         0x04
#define CTYPE_DIGIT         0x08
#define CTYPE_WHITE         0x10
#define CTYPE_PUNCT         0x20
#define CTYPE_HEXDIG        0x40

#define CTYPE_ALPHA         (CTYPE_UPPER|CTYPE_LOWER)
#define CTYPE_ALNUM         (CTYPE_UPPER|CTYPE_LOWER|CTYPE_DIGIT)
#define CTYPE_PRINT         (CTYPE_UPPER|CTYPE_LOWER|CTYPE_DIGIT|CTYPE_PUNCT)

#define _isascii(X)         ((unsigned)(X)<=0x7f)
#define _iscntrl(X)         (_chcodes[X]&CTYPE_CONTROL)
#define _isdigit(X)         (_chcodes[X]&CTYPE_DIGIT)
#define _isupper(X)         (_chcodes[X]&CTYPE_UPPER)
#define _islower(X)         (_chcodes[X]&CTYPE_LOWER)
#define _isalpha(X)         (_chcodes[X]&CTYPE_ALPHA)
#define _isalnum(X)         (_chcodes[X]&CTYPE_ALNUM)
#define _isxdigit(X)        (_chcodes[X]&CTYPE_HEXDIG)
#define _ispunct(X)         (_chcodes[X]&CTYPE_PUNCT)
#define _isspace(X)         (_chcodes[X]&CTYPE_WHITE)
#define _isprint(X)         (_chcodes[X]&CTYPE_PRINT)

#define _isgraph(X)         ((unsigned)((X)-33)<94)

#define _toascii(X)         ((X)&0x7f)
#define _toupper(X)         ((X)&0xdf)
#define _tolower(X)         ((X)|0x20)

// I recommend using the function versions, as these are a bit long.

#define _isident(X)         (_isalpha(X)||((X)=='_'))
#define _isxupper(X)        (_isdigit(X)||((X)>='A'&&(X)<='F'))
#define _isxlower(X)        (_isdigit(X)||((X)>='a'&&(X)<='f'))

// Not standard. Might get removed.

#define _isrange(X,_L,_H)   ((X)>=(_L)&&(X)<=(_H))

extern char _chcodes[128];

bool isascii(int chr);
bool iscntrl(int chr);
bool isdigit(int chr);
bool isupper(int chr);
bool islower(int chr);
bool isprint(int chr);
bool isspace(int chr);
bool isalpha(int chr);
bool isalnum(int chr);
bool isgraph(int chr);
bool ispunct(int chr);
bool isxupper(int chr);
bool isxlower(int chr);
bool isxdigit(int chr);
bool isident(int chr);

int toascii(int chr);
int toupper(int chr);
int tolower(int chr);

#endif

