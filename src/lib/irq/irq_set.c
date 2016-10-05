
#include <irq.h>

asm word irq_set(word irq)
{
    asm {
        tfr     cc,b                            // get current irq flags to return
        andb    #%01010000
        lda     3,s                             // get new flags and keep only the irq bits
        anda    #%01010000
        sta     3,s
        tfr     cc,a                            // get the irq
        anda    #%10101111                      // clear the irq bits
        ora     3,s                             // or in the new bits
        tfr     a,cc                            // set the new cc
        clra                                    // clear a and mask off b
    }
}

