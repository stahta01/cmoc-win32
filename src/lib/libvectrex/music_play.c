
#include <vectrex.h>

// Call this in the main loop to play the music.
void vectrex_music_play()
{
    asm {
        jsr     Do_Sound
    }
}

