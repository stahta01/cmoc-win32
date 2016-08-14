
#include <stdlib.h>

// Return SQUARE ROOT of argument
int asm sqrt(int a)
{
    asm {
        MICROC_MUL: extern

        ldx     #256        // Assumed result
        ldd     2,S         // Get argument
        cmpd    #255*255    // Over limit
        bhi     sqrt_exit   // Assume 256
        ldx     #0          // Start with ZERO

        sqrt_loop:
        tfr     X,D         // Copy for multiply
        lbsr    MICROC_MUL  // Perform multiply
        cmpd    2,S         // Do we have it?
        bhs     sqrt_exit   // Yes, this is it
        leax    1,X         // Advance count
        bra     sqrt_loop   // And go again

        sqrt_exit:
        tfr     X,D         // Get result
    }
}


