
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

#include <cmoc.h>

// Writes quotient into dividend[0..3].
// Does nothing if divisor is zero.

void asm div328(byte* dividend, byte divisor)
{
    asm {
        pshs    u
        tfr     s,u

        tst     7,u         // load divisor
        beq     div328_900  // division by zero: do nothing

        clra                // push 32-bit zero
        clrb
        pshs    b,a
        pshs    b,a         // -4,u will be 32-bit quotient

        ldx     4,u         // X points to 4-byte dividend

        ldb     #32         // one iteration per bit in the dividend
        pshs    b           // -5,u is loop counter

        clra                // dividend will be shifted left into D
        clrb

        div328_loop:
        lsl     3,x         // shift dividend left
        rol     2,x
        rol     1,x
        rol     ,x          // MSB of dividend now in carry
        rolb
        rola
        cmpd    6,u         // does divisor fit into D?
        blo     div328_nofit// if not

        subd    6,u
        orcc    #1          // set carry
        bra     div328_rolq

        div328_nofit:
        andcc   #$fe        // reset carry

        div328_rolq:
        rol     -1,u        // shift carry into quotient
        rol     -2,u
        rol     -3,u
        rol     -4,u

        dec     -5,u        // dec loop counter
        bne     div328_loop

// Copy quotient into dividend space.

        ldd     -4,u
        std     ,x
        ldd     -2,u
        std     2,x

        div328_900:
        tfr     u,s
        puls    u,pc
    }
}
