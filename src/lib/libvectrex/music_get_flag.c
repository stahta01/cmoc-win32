
#include <vectrex.h>

// Get the music flag, which can have the states documented with the get method.
// If you want to repeat the music, you should check this flag and if it is 0 set to 1 again.
uint8_t vectrex_music_get_flag()
{
    uint8_t flag;
    asm {
        lda     Vec_Music_Flag
        sta     flag
    }
    return flag;
}

