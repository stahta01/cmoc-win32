
#include <basic.h>

void POKE(word addr, byte value)
{
    *(byte*)addr = value;
}


