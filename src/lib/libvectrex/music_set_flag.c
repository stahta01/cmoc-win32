
#include <vectrex.h>

// Set the music flag, which should be set to 1 to start playing music using the BIOS routine.
// The music flag has 3 states: 0, 1 and 0x80.
// State 0 means no music is playing. A 1 means we are about to start the music.
// And 0x80 means the music is currently playing.
void music_set_flag(uint8_t flag)
{
    asm {
        LDA     :flag
        STA     Vec_Music_Flag
    }
}

