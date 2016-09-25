
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

#ifndef _BANK_H
#define _BANK_H

// Banks are always located at $8000 (32768)
#define BANK_MEMORY 32768

// Bank 0  is the only bank common to 64K CoCo's, Dragons & CoCo 3's
// Bank 15 is the default BASIC ROM bank.
// Bank 14 is a copy of memory $0000.

// These functions provide 15 32k banks.

// Bank  0 = GIME $00000 (page $00) (Also RAM under BASIC ROM)
// Bank  1 = GIME $08000 (page $04) [512K CoCo3]
// Bank  2 = GIME $10000 (page $08) [512K CoCo3]
// Bank  3 = GIME $18000 (page $0C) [512K CoCo3]

// Bank  4 = GIME $20000 (page $10) [512K CoCo3]
// Bank  5 = GIME $28000 (page $14) [512K CoCo3]
// Bank  6 = GIME $30000 (page $18) [512K CoCo3]
// Bank  7 = GIME $38000 (page $1C) [512K CoCo3]

// Bank  8 = GIME $40000 (page $20) [512K CoCo3]
// Bank  9 = GIME $48000 (page $24) [512K CoCo3]
// Bank 10 = GIME $50000 (page $28) [512K CoCo3]
// Bank 11 = GIME $58000 (page $2C) [512K CoCo3]

// Bank 12 = GIME $60000 (page $30) [128K CoCo3]
// Bank 13 = GIME $68000 (page $34) [128K CoCo3]
// Bank 14 = $0000 RAM (first 32K)  [128K CoCo3]
// Bank 15 = $8000 BASIC ROM

typedef int bank_t;

bank_t bank_set(bank_t bank);
bank_t bank_get(void);

#endif
