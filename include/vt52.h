
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

#ifndef _VT52_H
#define _VT52_H

#define VT52_CHR_NULL       0
#define VT52_CHR_ESCAPE     27

#define VT52_CHR_UP         'A'
#define VT52_CHR_DOWN       'B'
#define VT52_CHR_RIGHT      'C'
#define VT52_CHR_LEFT       'D'
#define VT52_CHR_HOME       'H'
#define VT52_CHR_XPOS       'X'
#define VT52_CHR_YPOS       'Y'
#define VT52_CHR_INSLINE    'L'
#define VT52_CHR_DELLINE    'M'

#define VT52_ESC_UP         "\033A"
#define VT52_ESC_DOWN       "\033B"
#define VT52_ESC_RIGHT      "\033C"
#define VT52_ESC_LEFT       "\033D"

#endif

