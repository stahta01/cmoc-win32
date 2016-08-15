
#include <stdlib.h>
#include <basic.h>

void SOUND(byte tone, byte duration)
{
    _beep(tone, duration << 2);
}


