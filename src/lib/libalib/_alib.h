
#define IS_ALNUM _IS_ALNUM
#define IS_ALPHA _IS_ALPHA
#define IS_CNTRL _IS_CNTRL
#define IS_DIGIT _IS_DIGIT
#define IS_LOWER _IS_LOWER
#define IS_PRINT _IS_PRINT
#define IS_PUNCT _IS_PUNCT
#define IS_SPACE _IS_SPACE
#define IS_TERMIN _IS_TERMIN
#define IS_UPPER _IS_UPPER
#define IS_XDIGIT _IS_XDIGIT

void asm __ALIB(void)
{
    asm {
#ifdef _NAME
        _NAME:
#endif
#define section *
#define endsect *
#include _FILE
#undef section
#undef endsect
#undef u
    }
}

