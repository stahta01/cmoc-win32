
#include "_system.h"

byte _static_dev;

asm void system_putchr(int chr, dev_t dev)
{
    asm {
        lda     _DEVNUM
        sta     _static_dev
        lda     5,s
        sta     _DEVNUM
        lda     3,s
        jsr     [sysptr_putchr]
        lda     _static_dev
        sta     _DEVNUM
    }
}

