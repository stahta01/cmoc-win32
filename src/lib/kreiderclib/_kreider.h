
// Raw Kreider asm. These can not be called from CMOC C.
// ie: They need a C wrapper.

#define _linc       ___linc
#define _ldec       ___ldec
#define _lmul       ___lmul
#define _lbexit     ___lbexit
#define _ltoacc     ___ltoacc
#define _lneg       ___lneg
#define _lnegx      ___lnegx
#define _lcompl     ___lcompl
#define _lshl       ___lshl
#define _lshr       ___lshr
#define _lmove      ___lmove
#define _litol      ___litol
#define _lutol      ___lutol
#define _lcmpr      ___lcmpr
#define _land       ___land
#define _lor        ___lor
#define _lxor       ___lxor
#define _lnot       ___lnot
#define _ladd       ___ladd
#define _lsub       ___lsub
#define _ldiv       ___ldiv
#define _lmod       ___lmod

#define ltoa        ___ltoa
#define atol        ___atol
#define ccdiv       ___ccdiv
#define ccmod       ___ccmod
#define ccudiv      ___ccudiv
#define ccumod      ___ccumod
#define ccmult      ___ccmult

// ANSIC Functions

#define rand        _rand
#define bsearch     _bsearch
#define srand       _srand
#define abs         _abs
#define atoi        _atoi
#define max         _max
#define memchr      _memchr
#define memcmp      _memcmp
#define memcpy      _memcpy
#define memset      _memset
#define min         _min
#define putc        _putc
#define strcat      _strcat
#define strchr      _strchr
#define strcmp      _strcmp
#define strcpy      _strcpy
#define strlen      _strlen
#define strncmp     _strncmp
#define strncpy     _strncpy
#define strpbrk     _strpbrk
#define strrchr     _strrchr
#define strspn      _strspn
#define strtok      _strtok
#define tolower     _tolower
#define toupper     _toupper
#define setjmp      _setjmp
#define longjmp     _longjmp
#define qsort       _qsort
#define strncat     _strncat
#define memccpy     _memccpy

// Functions defined in os9.h

#define htoi        __htoi
#define swab        __swab
#define umax        __umax
#define umin        __umin
#define strucat     __strucat
#define strucpy     __strucpy
#define strnucmp    __strnucmp
#define reverse     __reverse
#define strhcpy     __strhcpy
#define strend      __strend
#define utoa        __utoa
#define itoa        __itoa
#define patmatch    __patmatch
#define findstr     __findstr

// Variables for kreider lib functions

#define _chcodes    __chcodes
#define _flacc      __flacc

// Unsure if these are used

#define index       __index
#define rindex      __rindex
#define pffloat     __pffloat
#define pflong      __pflong

void asm _static_(void)
{
    asm {
#define psect *
#define vsect *
#define ends  *
#define section *
#define endsect *

#include _FILE

#undef psect
#undef vsect
#undef ends
#undef section
#undef endsect
    }
}

