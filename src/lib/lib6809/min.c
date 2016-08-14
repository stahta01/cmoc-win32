
#include <stdlib.h>

// Return MINIMUM of two arguments

int asm min(int a, int b)
{
    asm {
        ldd     2,S         // Get first argument
        cmpd    4,S         // Compare with second
        ble     min_exit    // Already have smallest
        ldd     4,S         // Get smallest
        min_exit:
    }
}


