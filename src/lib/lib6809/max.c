
#include <stdlib.h>

// Return MAXIMUM of two arguments

int asm max(int a, int b)
{
    asm {
        ldd     2,S         // Get first argument
        cmpd    4,S         // Compare with second
        bge     max_exit    // Already have largest
        ldd     4,S         // Get largest
        max_exit:
    }
}



