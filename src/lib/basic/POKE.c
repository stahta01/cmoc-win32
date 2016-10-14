
#include "_basic.h"

void POKE(word addr, word value)
{
    *(byte*)addr = (byte)value;
}


