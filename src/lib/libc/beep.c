
#include "_libc.h"

void beep(unsigned char tone, unsigned duration)
{
    _sndton = tone;
    _snddur = duration;
    system_sound();
}

