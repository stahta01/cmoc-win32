
#define atoi        _atoi
#define abs         _abs
#define umin        _umin
#define umax        _umax
#define pffloat     _pffloat
#define pflong      _pflong
#define strlen      _strlen
#define putc        _putc
#define toupper     _toupper
#define tolower     _tolower
#define _chcodes    __chcodes
#define memccpy     _memccpy
#define memchr      _memchr
#define index       _index
#define rindex      _rindex
#define strchr      _strchr
#define strrchr     _strrchr
#define memcmp      _memcmp
#define memcpy      _memcpy
#define memset      _memset
#define min         _min
#define max         _max
#define reverse     _reverse
#define strcmp      _strcmp
#define strhcpy     _strhcpy
#define strcat      _strcat
#define strcpy      _strcpy
#define strend      _strend
#define strucat     _strucat
#define strucpy     _strucpy
#define strncat     _strncat
#define strncmp     _strncmp
#define strncpy     _strncpy
#define strnucmp    _strnucmp
#define strpbrk     _strpbrk

void asm __libkreider(void)
{
    asm {
#define section *
#define endsect *
#include _FILE
#undef section
#undef endsect
    }
}

