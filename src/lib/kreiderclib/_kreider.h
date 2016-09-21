
#define _linc       linc
#define _ldec       ldec
#define _lmul       lmul
#define _lbexit     lbexit
#define _ltoacc     ltoacc
#define _lneg       lneg
#define _lnegx      lnegx
#define _lcompl     lcompl
#define _lshl       lshl
#define _lshr       lshr
#define _lmove      lmove
#define _litol      litol
#define _lutol      lutol
#define _lcmpr      lcmpr
#define _land       land
#define _lor        lor
#define _lxor       lxor
#define _lnot       lnot
#define _ladd       ladd
#define _lsub       lsub
#define _ldiv       ldiv
#define _lmod       lmod

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

void asm __libkreider(void)
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

