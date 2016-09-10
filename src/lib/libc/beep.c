
#include "_libc.h"

void beep(unsigned char tone, unsigned duration)
{
    system_sound(tone, duration);
}

