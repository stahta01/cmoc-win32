
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

// I could not find the ctype.h file for kreiderlib, so I recreated this file.
// If you find an error, email me.

#define _CONTROL            0x01
#define _UPPER              0x02
#define _LOWER              0x04
#define _DIGIT              0x08
#define _WHITE              0x10
#define _PUNCT              0x20
#define _HEXDIG             0x40

#define _ALPHA              (_UPPER|_LOWER)
#define _ALNUM              (_UPPER|_LOWER|_DIGIT)

#define _iscntrl(_C)        (_chcodes[_C]&_CONTROL)
#define _isdigit(_C)        (_chcodes[_C]&_DIGIT)
#define _isupper(_C)        (_chcodes[_C]&_UPPER)
#define _islower(_C)        (_chcodes[_C]&_LOWER)
#define _isalpha(_C)        (_chcodes[_C]&_ALPHA)
#define _isalnum(_C)        (_chcodes[_C]&_ALNUM)
#define _isxdigit(_C)       (_chcodes[_C]&_HEXDIG)
#define _ispunct(_C)        (_chcodes[_C]&_PUNCT)
#define _isspace(_C)        (_chcodes[_C]&_WHITE)
#define _isprint(_C)        (((byte)(_C)-32)<95)
#define _isgraph(_C)        (((byte)(_C)-33)<94)

#define _toascii(_C)        ((_C) & 0x7f)
#define _toupper(_C)        (_islower(_C) ? ((_C) - ' ') : (_C))
#define _tolower(_C)        (_isupper(_C) ? ((_C) + ' ') : (_C))

// I recommend using the function versions, as these are a bit long.

#define _isxupper(_C)       (_isdigit(_C) || ((_C) >= 'A' && (_C) <= 'F'))
#define _isxlower(_C)       (_isdigit(_C) || ((_C) >= 'a' && (_C) <= 'f'))

// Not standard. Might get removed.

#define _isrange(_C,_L,_H)  ((_C)>=(_L)&&(_C)<=(_H))
#define _isascii(_C)        ((_C) >= 0 && (_C) <= 0x7f)

extern char _chcodes[128];

bool isascii(int chr);
bool iscntrl(int c);
bool isdigit(int c);
bool isupper(int c);
bool islower(int c);
bool isprint(int c);
bool isspace(int c);
bool isalpha(int c);
bool isalnum(int c);
bool isgraph(int c);
bool ispunct(int c);
bool isxupper(int c);
bool isxlower(int c);
bool isxdigit(int c);

int toascii(int c);
int toupper(int c);
int tolower(int c);

#endif

