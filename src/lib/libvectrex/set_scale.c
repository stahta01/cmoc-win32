
#include <vectrex.h>

// Set the scale. With this you can zoom in and out objects.
void set_scale(int8_t scale)
{
    asm {
        LDA     :scale
        STA     <VIA_t1_cnt_lo
    }
}

