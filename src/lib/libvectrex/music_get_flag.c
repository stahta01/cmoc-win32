
#include <vectrex.h>

// Get the music flag, which can have the states documented with the get method.
// If you want to repeat the music, you should check this flag and if it is 0 set to 1 again.
uint8_t music_get_flag()
{
    uint8_t flag;
    asm {
        LDA     Vec_Music_Flag
        STA     flag
    }
    return flag;
}

