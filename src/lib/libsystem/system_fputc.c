
#include "_system.h"

byte _static_dev;

asm void system_fputc(int chr, dev_t dev)
{
    asm {
        lda     _DEVNUM
        sta     _static_dev
        lda     5,s
        sta     _DEVNUM
        lda     3,s
        jsr     [handle_fputc]
        lda     _static_dev
        sta     _DEVNUM
    }
}

