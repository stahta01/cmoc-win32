
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

#define _isascii(_C)        ((unsigned)(_C)<=0x7f)
#define _iscntrl(_C)        (_chcodes[_C]&CTYPE_CONTROL)
#define _isdigit(_C)        (_chcodes[_C]&CTYPE_DIGIT)
#define _isupper(_C)        (_chcodes[_C]&CTYPE_UPPER)
#define _islower(_C)        (_chcodes[_C]&CTYPE_LOWER)
#define _isalpha(_C)        (_chcodes[_C]&CTYPE_ALPHA)
#define _isalnum(_C)        (_chcodes[_C]&CTYPE_ALNUM)
#define _isxdigit(_C)       (_chcodes[_C]&CTYPE_HEXDIG)
#define _ispunct(_C)        (_chcodes[_C]&CTYPE_PUNCT)
#define _isspace(_C)        (_chcodes[_C]&CTYPE_WHITE)
#define _isprint(_C)        (_chcodes[_C]&CTYPE_PRINT)

#define _isgraph(_C)        ((unsigned)((_C)-33)<94)

#define _toascii(_C)        ((_C)&0x7f)
#define _toupper(_C)        ((_C)&0xdf)
#define _tolower(_C)        ((_C)|0x20)

// I recommend using the function versions, as these are a bit long.

#define _isxupper(_C)       (_isdigit(_C)||((_C)>='A'&&(_C)<='F'))
#define _isxlower(_C)       (_isdigit(_C)||((_C)>='a'&&(_C)<='f'))

// Not standard. Might get removed.

#define _isrange(_C,_L,_H)  ((_C)>=(_L)&&(_C)<=(_H))

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

int toascii(int chr);
int toupper(int chr);
int tolower(int chr);

#endif

