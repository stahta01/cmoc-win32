
#include "_cmoc.h"

// Blocks the execution for the specified time in 60ths of a second.
//
void asm delay(size_t sixtiethsOfASecond)
{
    asm {
// Wait for a number of ticks (1/60 second) which is given on the stack.
        pshs    b,a
        ldd     4,s                         // number of ticks to wait
        beq     delay9
        addd    $0112                       // value that TIMER must reach

        delay1:
        cmpd    $0112
        bne     delay1

        delay9:
        puls    a,b,pc
    }
}

