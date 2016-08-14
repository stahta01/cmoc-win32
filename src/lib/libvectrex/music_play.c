
#include <vectrex.h>

// Call this in the main loop to play the music.
void music_play()
{
    asm {
        JSR     Do_Sound
    }
}

