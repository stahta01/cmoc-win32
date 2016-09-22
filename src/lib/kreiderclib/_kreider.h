
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

#define abs         _abs
#define atoi        _atoi
#define index       _index
#define max         _max
#define memccpy     __memccpy
#define memchr      _memchr
#define memcmp      _memcmp
#define memcpy      _memcpy
#define memset      _memset
#define min         _min
#define pffloat     __pffloat
#define pflong      __pflong
#define putc        _putc
#define reverse     __reverse
#define rindex      _rindex
#define strcat      _strcat
#define strchr      _strchr
#define strcmp      _strcmp
#define strcpy      _strcpy
#define strend      _strend
#define strhcpy     _strhcpy
#define strlen      _strlen
#define strncat     __strncat
#define strncmp     _strncmp
#define strncpy     _strncpy
#define strnucmp    __strnucmp
#define strpbrk     _strpbrk
#define strrchr     _strrchr
#define strspn      _strspn
#define strtok      _strtok
#define strucat     __strucat
#define strucpy     __strucpy
#define swab        __swab
#define tolower     _tolower
#define toupper     _toupper
#define umax        _umax
#define umin        _umin
#define _chcodes    __chcodes

void asm _static_libkreider(void)
{
    asm {
        linc: extern
        ldec: extern
        lmul: extern
        lbexit: extern
        ltoacc: extern
        lnegx: extern

#define section *
#define endsect *
#include _FILE
#undef section
#undef endsect
    }
}

