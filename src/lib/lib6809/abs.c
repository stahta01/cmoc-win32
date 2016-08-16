
// Converted to C for WinCMOC by Derek Evans 2016

#include <stdlib.h>

// Return ABSOLUTE VALUE of argument

int asm abs(int a)
{
    asm{
        ldd     2,S         // Get argument
        bpl     abs_exit    // Alreay positive
        coma                // Convert to
        comb                // Negative
        addd    #1
        abs_exit:
    }
}


