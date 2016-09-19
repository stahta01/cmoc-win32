
#include "_libc.h"

void beep(int tone, int duration)
{
    _sndton = (char)tone;
    _snddur = (char)duration;
    system_sound();
}

