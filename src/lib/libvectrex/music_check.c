
#include <vectrex.h>

// Point the BIOS play routine to a piece of music.
// Info about the format: http://www.playvectrex.com/designit/chrissalo/soundplaying.htm
void vectrex_music_check(unsigned char* music)
{
    asm {
        pshs    U
        jsr     DP_to_C8
        ldu     :music
        jsr     Init_Music_chk
        puls    U
    }
}

