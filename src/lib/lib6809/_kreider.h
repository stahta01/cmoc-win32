
void asm _NAME(void)
{
    asm {
#define psect *
#define endsect *
#include _FILE
#undef psect
#undef endsect
    }
}
