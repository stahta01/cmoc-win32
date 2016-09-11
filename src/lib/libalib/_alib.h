
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

