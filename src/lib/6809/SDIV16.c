
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

// Divide X by D, signed; return quotient in X, remainder in D.
// Non-zero remainder is negative iff dividend is negative.

asm void _static_(void)
{
    asm {
        SDIV16: export

        SDIV16:
        pshs    X,B,A
        clr     ,-S                             // counter: number of negative arguments (0..2)
        clr     ,-S                             // boolean: was dividend negative?
        tsta                                    // is divisor negative?
        bge     SDIV16_10                       // if not
        inc     1,S
        coma                                    // negate divisor
        comb
        addd    #1
        std     2,S

        SDIV16_10:
        ldd     4,S                             // is dividend negative?
        bge     SDIV16_20                       // if not
        inc     ,S
        inc     1,S
        coma                                    // negate dividend
        comb
        addd    #1
        std     4,S

        SDIV16_20:
        ldd     2,S                             // reload divisor
        ldx     4,S                             // reload dividend
        lbsr     DIV16

// Counter is 0, 1 or 2. Quotient negative if counter is 1.

        lsr     1,S                             // check bit 0 of counter (1 -> negative quotient)
        bcc     SDIV16_30                       // quotient not negative
        exg     X,D                             // put quotient in D and remainder in X
        coma                                    // negate quotient
        comb
        addd    #1
        exg     X,D                             // return quotient and remainder in X and D

        SDIV16_30:                              // Negate the remainder if the dividend was negative.
        tst     ,S                              // was dividend negative?
        beq     SDIV16_40                       // if not
        coma                                    // negate remainder
        comb
        addd    #1

        SDIV16_40:
        leas    6,S
    }
}

