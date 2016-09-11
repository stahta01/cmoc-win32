
void asm __kreiderclib(void)
{
    asm {
#define section *
#define endsect *
#include _FILE
#undef section
#undef endsect
    }
}

