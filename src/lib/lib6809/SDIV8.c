
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

// Divide A by B, signed; return quotient in B, remainder in A.
// Non-zero remainder is negative iff dividend is negative.
// Does not preserve X.

void asm __SDIV8(void)
{
    asm {
        SDIV8: export

        SDIV8:
        clr     ,-S         // counter: number of negative arguments (0..2)
        clr     ,-S         // boolean: was dividend negative?
        tstb                // is divisor negative?
        bge     SDIV8_10    // if not
        inc     1,S         // increment counter of negative arguments
        negb                // negate divisor

        SDIV8_10:
        tsta                // is dividend negative?
        bge     SDIV8_20    // if not
        inc     ,S          // remember that dividend was negative
        inc     1,S         // increment counter of negative arguments
        nega                // negate dividend

        SDIV8_20:
        lbsr    DIV8

// Counter is 0, 1 or 2. Quotient negative if counter is 1.
        lsr     1,S         // check bit 0 of counter (1 -> negative quotient)
        bcc     SDIV8_30    // quotient not negative
        negb                // negate quotient

        SDIV8_30:
// Negate the remainder if the dividend was negative.
        tst     ,S          // was dividend negative?
        beq     SDIV8_40    // if not
        nega                // negate remainder

        SDIV8_40:
        leas    2,S
    }
}



