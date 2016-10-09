
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

#ifndef _INT_H
#define _INT_H

// These will soon be functions.

#define _imul2(A)   ((A)<<1)
#define _imul4(A)   ((A)<<2)
#define _imul8(A)   ((A)<<3)
#define _imul16(A)  ((A)<<4)
#define _imul32(A)  ((A)<<5)
#define _imul64(A)  ((A)<<6)
#define _imul127(A) ((A)<<7)
#define _imul256(A) ((A)<<8)

#define _imul3(A)   (_imul2(A)+(A))
#define _imul5(A)   (_imul4(A)+(A))
#define _imul6(A)   (_imul4(A)+_imul2(A))
#define _imul7(A)   (_imul8(A)-(A))

#define _imul10(A)  (_imul8(A)+_imul2(A))

#define _imul40(A)  (_imul32(A)+_imul8(A))
#define _imul80(A)  (_imul64(A)+_imul16(A))

// Im experimenting with int shift functions. CMOC outputs a lot of code
// for bit shifts. Im testing if using functions will reduce bin sizes.

int _ishl6(int val);
int _ishr6(int val);

#endif

