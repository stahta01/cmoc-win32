
#define abs         _abs
#define atoi        _atoi
#define index       _index
#define max         _max
#define memccpy     _memccpy
#define memchr      _memchr
#define memcmp      _memcmp
#define memcpy      _memcpy
#define memset      _memset
#define min         _min
#define pffloat     _pffloat
#define pflong      _pflong
#define putc        _putc
#define reverse     _reverse
#define rindex      _rindex
#define strcat      _strcat
#define strchr      _strchr
#define strcmp      _strcmp
#define strcpy      _strcpy
#define strend      _strend
#define strhcpy     _strhcpy
#define strlen      _strlen
#define strncat     _strncat
#define strncmp     _strncmp
#define strncpy     _strncpy
#define strnucmp    _strnucmp
#define strpbrk     _strpbrk
#define strrchr     _strrchr
#define strspn      _strspn
#define strtok      _strtok
#define strucat     _strucat
#define strucpy     _strucpy
#define tolower     _tolower
#define toupper     _toupper
#define umax        _umax
#define umin        _umin
#define _chcodes    __chcodes

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

