
#include "_int.h"

// Return SQUARE ROOT of argument

asm word _usqrt(word val)
{
    asm {
        ldx     #256                                // Assumed result
        ldd     2,s                                 // Get argument
        cmpd    #255*255                            // Over limit
        bhi     sqrt_exit                           // Assume 256
        ldx     #0                                  // Start with ZERO

        sqrt_loop:
        tfr     X,D                                 // Copy for multiply
        lbsr    MUL16                               // Perform multiply
        cmpd    2,s                                 // Do we have it?
        bhs     sqrt_exit                           // Yes, this is it
        leax    1,x                                 // Advance count
        bra     sqrt_loop                           // And go again

        sqrt_exit:
        tfr     x,d                                 // Get result
    }
}

