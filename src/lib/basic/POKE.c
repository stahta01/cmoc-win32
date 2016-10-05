
#include <basic.h>

void POKE(unsigned addr, unsigned char value)
{
    *(unsigned char*)addr = value;
}


