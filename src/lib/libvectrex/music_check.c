
#include <vectrex.h>

// Point the BIOS play routine to a piece of music.
// Info about the format: http://www.playvectrex.com/designit/chrissalo/soundplaying.htm
void music_check(unsigned char* music)
{
    asm {
        PSHS    U
        JSR     DP_to_C8
        LDU     music
        JSR     Init_Music_chk
        PULS    U
    }
}

