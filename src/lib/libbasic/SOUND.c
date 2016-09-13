
#include <stdlib.h>
#include <basic.h>

void SOUND(int tone, int duration)
{
    beep((char)tone, (char)duration);
}

