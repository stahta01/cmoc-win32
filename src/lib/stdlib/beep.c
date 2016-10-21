
#include "_stdlib.h"

void beep(int tone, int duration)
{
    _sndton = (byte)tone;
    _snddur = (word)duration;
    system_sound();
}

