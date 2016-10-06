
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

#define ERRNO_NONE      255

// ERROR MESSAGES AND THEIR NUMBERS AS USED INTERNALLY

// The CoCo uses a 2 char per error lookup table at $abaf. An error is raised by calling
// the "error servicing routine" at $ac46 with regb loaded with an offset into this table.
// Therefore regb is ment to be even, but it so happends (by luck), that calling
// with odd offsets, also gives error strings which dont clash with standard errors.
// Therefore, I define system errors as even, and user errors as odd. Use what you
// want, but I'll probably define some of the odd ones if I need them.

// Note: The system() command returns these values, therefore ERRNO_NF is not supported
// since system() returns 0 for SUCCESS. If you need to detect ERRNO_NF, use systemex()
// which raises exceptions.

#define ERRNO_NF         0                      // NEXT WITHOUT FOR

#define ERRNO_FS         1                      //
#define ERRNO_SN         2                      // SYNTAX ERROR
#define ERRNO_NR         3                      //
#define ERRNO_RG         4                      // RETURN WITHOUT GOSUB
#define ERRNO_GO         5                      //
#define ERRNO_OD         6                      // OUT OF DATA
#define ERRNO_DF         7                      //
#define ERRNO_FC         8                      // ILLEGAL FUNCTION CALL
#define ERRNO_CO         9                      //
#define ERRNO_OV        10                      // OVERFLOW
#define ERRNO_VO        11                      //
#define ERRNO_OM        12                      // OUT OF MEMORY
#define ERRNO_MU        13                      //
#define ERRNO_UL        14                      // UNDEFINED LINE NUMBER
#define ERRNO_LB        15                      //
#define ERRNO_BS        16                      // BAD SUBSCRIPT
#define ERRNO_SD        17                      //
#define ERRNO_DD        18                      // REDIMENSIONED ARRAY
#define ERRNO_DS        19                      // (D/)
#define ERRNO_D0        20                      // DIVISION BY ZERO (/0)
#define ERRNO_0I        21                      //
#define ERRNO_ID        22                      // ILLEGAL DIRECT STATEMENT
#define ERRNO_DT        23                      //
#define ERRNO_TM        24                      // TYPE MISMATCH
#define ERRNO_MO        25                      //
#define ERRNO_OS        26                      // OUT OF STRING SPACE
#define ERRNO_SL        27                      //
#define ERRNO_LS        28                      // STRING TOO LONG
#define ERRNO_SS        29                      //
#define ERRNO_ST        30                      // STRING FORMULA TOO COMPLEX
#define ERRNO_TC        31                      //
#define ERRNO_CN        32                      // CAN'T CONTINUE
#define ERRNO_NF        33                      //
#define ERRNO_FD        34                      // BAD FILE DATA
#define ERRNO_DA        35                      //
#define ERRNO_AO        36                      // FILE ALREADY OPEN
#define ERRNO_OD        37                      //
#define ERRNO_DN        38                      // DEVICE NUMBER ERROR
#define ERRNO_NI        39                      //
#define ERRNO_IO        40                      // I/O ERROR
#define ERRNO_OF        41                      //
#define ERRNO_FM        42                      // BAD FILE MODE
#define ERRNO_MN        43                      //
#define ERRNO_NO        44                      // FILE NOT OPEN
#define ERRNO_OI        45                      //
#define ERRNO_IE        46                      // INPUT PAST END OF FILE
#define ERRNO_EI        47                      //
#define ERRNO_IE        48                      // DIRECT STATEMENT IN FILE
#define ERRNO_EU        49                      //

// Extended BASIC Errors

#define ERRNO_UF        50                      // UNDEFINED FUNCTION (FN) CALL
#define ERRNO_FN        51                      //
#define ERRNO_NE        52                      // FILE NOT FOUND

// Behond Extended BASIC

// These strings are shown for error numbers behond the documented ones.
// They might not show for all systems, but at least they are named.
// Use with care.

#define ERRNO_BR        54                      // BREAK
#define ERRNO_RD        55                      //
#define ERRNO_DF2       56                      //
#define ERRNO_FO        57                      //
#define ERRNO_OB        58                      //
#define ERRNO_BW        59                      //
#define ERRNO_WP        60                      //
#define ERRNO_PF        61                      //
#define ERRNO_FN2       62                      //
#define ERRNO_NF2       63                      //
#define ERRNO_FS2       64                      //
#define ERRNO_SA        65                      //
#define ERRNO_AE        66                      //
#define ERRNO_EF        67                      //
#define ERRNO_FO2       68                      //
#define ERRNO_OS2       69                      //
#define ERRNO_SE        70                      //
#define ERRNO_EV        71                      //
#define ERRNO_VF        72                      //
#define ERRNO_FE        73                      //
#define ERRNO_ER        74                      //
#define ERRNO_RB        75                      //
#define ERRNO_BA        76                      //
#define ERRNO_AS        77                      //
#define ERRNO_S_        78                      //
#define ERRNO___        79                      //
#define ERRNO___2       80                      //
#define ERRNO__D        81                      //
#define ERRNO_DA2       82                      //
#define ERRNO_AT        83                      //
#define ERRNO_TB        84                      //
#define ERRNO_BI        85                      //
#define ERRNO_IN        86                      //
#define ERRNO_N4        87                      //
#define ERRNO_4_        88                      //
#define ERRNO_IN        86                      //

#define ERRNO_CMOC      127

#endif

