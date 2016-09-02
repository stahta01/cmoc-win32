
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

#include <cmoc.h>

// Prints the 32-bit unsigned integer given by 'hi' and 'lo'
// in the designated 11-byte buffer as an ASCII decimal string
// terminated by a '\0' character.
// The resulting buffer always receives a 10-character string
// and is zero padded at the left.
// Returns the address of the first non-'0' character in the
// resulting buffer, or of the last '0' character if the given
// value was zero.

char* dwtoa(char* buffer, unsigned hi, unsigned lo)
{
    char* result = 0;
    asm {
        //PSHS    U
        //TFR     S,U
        leas    -5,S
// Line 125: init of variable dest
        ldd     4,U                     // variable buffer
        std     -4,U                    // variable dest
// Line 127: init of variable pPower
        leax    powersOfTen,pcr         // variable pow10_9_hi
        stx     -2,U                    // variable pPower
// Line 131: for init
// Line 131: init of variable i
        ldb     #$09
        stb     -5,U                    // variable i
        bra     dwtoa_020               // jump to for condition

        dwtoa_010:
// Line 131: for body

// Line 138: function call: doDigit()
        ldx     -4,U                    // variable dest
        pshs    x                       // argument 4 of doDigit()
        leax    1,x                     // point to next byte for next iteration
        stx     -4,u

        ldx     -2,U                    // variable pPower

        ldd     2,X                     // low word of that power of 10
        pshs    B,A                     // argument 3 of doDigit()

        ldd     ,X                      // high word of a power of 10
        pshs    B,A                     // argument 2 of doDigit()

        leax    4,x                     // advance pPower to next power of 10
        stx     -2,U                    // store into variable pPower for next iteration

        leax    6,U                     // point to argument 'hi', which is followed by 'lo'
        pshs    X                       // argument 1 of doDigit()

        bsr     doDigit

        leas    8,S

// Line 131: for increment
        dec     -5,U                    // variable i

        dwtoa_020:
// Line 131: for condition
        tst     -5,U
        bne     dwtoa_010               // end of loop of calls to doDigit()

// Store last digit, which is in variable 'lo', at 'dest'.
// Line 143: assignment: =
        ldb     9,U                     // low byte of variable lo (contains 0..9)
        addb    #$30                    // make 0..9 into '0'..'9' in ASCII
        ldx     -4,U                    // variable dest
        stb     ,X+
        clr     ,x                      // write terminating '\0'

// Skip leading zeroes in the resulting string.
        ldx     4,U                     // variable buffer

        dwtoa_030:
        ldb     ,X+
        cmpb    #$30
        beq     dwtoa_030

        leax    -1,x

// If entire string contains '\0' characters, return address of last '\0'.
        tst     ,X
        bne     dwtoa_040
        leax    -1,x

        dwtoa_040:
        stx     result
        bra     dwtoa_exit
        //tfr     x,d             // return address of 1st non-0 digit, or of last 0 if value is 0

        //tfr     U,S
        //puls    U,PC

// Powers of ten as 32-bit integers, in descending order.
// Used by dwtoa.

        powersOfTen:
        fdb     $3b9a,$ca00             // 10**9
        fdb     $05f5,$e100             // 10**8
        fdb     $0098,$9680             // 10**7
        fdb     $000f,$4240             // 10**6
        fdb     $0001,$86a0             // 10**5
        fdb     $0000,$2710             // 10**4
        fdb     $0000,$03E8             // 10**3
        fdb     $0000,$0064             // 10**2
        fdb     $0000,$000A             // 10**1

        doDigit:
        pshs    U
        tfr     S,U
        leas    -5,S
// Line 84: init of variable c
        clr     -1,U                    // variable c

        doDigit_010:
// Line 85: for body
// Line 87: init of variable hiCopy
        ldx     4,U                     // variable hi (word *)
        ldd     ,X                      // read *hi (word)
        std     -5,U                    // variable hiCopy
// Line 88: init of variable loCopy
        ldd     2,X                     // load hi[1] (word)
        std     -3,U                    // variable loCopy
// Line 90: if
// Line 90: function call: sub32()
        ldd     8,U                     // variable l
        pshs    B,A                     // argument 3 of sub32()
        ldd     6,U                     // variable h
        pshs    B,A                     // argument 2 of sub32()
        pshs    X                       // 'hi': argument 1 of sub32()
        lbsr     _sub32                 // sub32(): returns carry in B
        leas    6,S
        tstb
        beq     doDigit_020             // no carry: continue subtracting
// Line 93: assignment: =
        ldx     4,U                     // variable hi
        ldd     -5,U
        std     ,X
// Line 94: assignment: =
        ldd     -3,U
        std     2,X
        bra     doDigit_030             // break

        doDigit_020:
        inc     -1,U                    // variable c
        bra     doDigit_010

        doDigit_030:
// Line 101: assignment: +=
        ldb     -1,U
        addb    #$30
// Line 103: assignment: =
        ldx     10,U                    // variable dest (byte *)
        stb     ,X                      // store character in *dest

        tfr     U,S
        puls    U,PC                    // end of doDigit

        dwtoa_exit:
    }
    return result;
}

