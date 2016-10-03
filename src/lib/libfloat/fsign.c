
// Contributed by Brian K. Holman (me@brianholman.com)
// Based on information provided by Pierre Sarrazin <http://sarrazip.com/>
// Many thanks, Derek :-)

#include "_float.h"

// Returns -1, 0 or +1 depending on the sign of the float value.

asm char _fsign(float_t* src)
{
    asm {
        ldx     2,s
        jsr     _LBC14                          // COPY A PACKED FP NUMBER FROM (X) TO FPA0
        jsr     _LBC6D                          // CALL BASIC SGN0 FPA0
    }
}

