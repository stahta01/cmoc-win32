
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

#ifndef _ERRNO_H
#define _ERRNO_H

#include <sys/errno.h>

extern errno_t errno;

/*
ERROR MESSAGES AND THEIR NUMBERS AS USED INTERNALLY

LABAF	FCC	'NF'	0 NEXT WITHOUT FOR
FCC	'SN'	1 SYNTAX ERROR
FCC	'RG'	2 RETURN WITHOUT GOSUB
FCC	'OD'	3 OUT OF DATA
FCC	'FC'	4 ILLEGAL FUNCTION CALL
FCC	'OV'	5 OVERFLOW
FCC	'OM'	6 OUT OF MEMORY
FCC	'UL'	7 UNDEFINED LINE NUMBER
FCC	'BS'	8 BAD SUBSCRIPT
FCC	'DD'	9 REDIMENSIONED ARRAY
FCC	'/0'	10 DIVISION BY ZERO
FCC	'ID'	11 ILLEGAL DIRECT STATEMENT
FCC	'TM'	12 TYPE MISMATCH
FCC	'OS'	13 OUT OF STRING SPACE
FCC	'LS'	14 STRING TOO LONG
FCC	'ST'	15 STRING FORMULA TOO COMPLEX
FCC	'CN'	16 CAN'T CONTINUE
FCC	'FD'	17 BAD FILE DATA
FCC	'AO'	18 FILE ALREADY OPEN
FCC	'DN'	19 DEVICE NUMBER ERROR
FCC	'IO'	20 I/O ERROR
FCC	'FM'	21 BAD FILE MODE
FCC	'NO'	22 FILE NOT OPEN
FCC	'IE'	23 INPUT PAST END OF FILE
FCC	'DS'	24 DIRECT STATEMENT IN FILE
*/

/*
* ADDITIONAL ERROR MESSAGES ADDED BY EXTENDED BASIC
L890B	FCC	'UF'	25 UNDEFINED FUNCTION (FN) CALL
L890D	FCC	'NE'	26 FILE NOT FOUND
*/

#endif

