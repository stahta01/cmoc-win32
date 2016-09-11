
void asm __ASM(void)
{
    asm {
        _NAME: export
#define section *
#define endsect *
#include _FILE
#undef section
#undef endsect
    }
}

