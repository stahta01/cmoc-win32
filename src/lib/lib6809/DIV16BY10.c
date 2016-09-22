
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

// Divide D by 10.
// Quotient left in D.
// Does not preserve X.
// Source: Hacker's Delight (Addison-Wesley, 2003, 2012)
//         http://www.hackersdelight.org/divcMore.pdf

asm void _static_DIV16BY10(void)
{
    asm {
        DIV16BY10: export
        DIV16BY10:

        tfr     d,x                         // save n
        lsra
        rorb                                // D = n >> 1
        pshs    b,a                         // q := ,S (word)
        lsra
        rorb                                // D = n >> 2
        addd    ,s
        std ,s                              // q = (n >> 1) + (n >> 2)
        lsra
        rorb
        lsra
        rorb
        lsra
        rorb
        lsra
        rorb
        addd    ,s
        std     ,s                          // D = q + (q >> 4)
        tfr     a,b
        clra                                // q >> 8
        addd    ,s
        lsra
        rorb
        lsra
        rorb
        lsra
        rorb                                // q >> 3
        std     ,s
        lslb
        rola
        lslb
        rola                                // q << 2
        addd    ,s
        lslb
        rola
        pshs    b,a
        tfr     x,d                         // D = n
        subd    ,s++                        // D = r
        cmpd    #9                          // r > 9 ?
        bls     DIV16BY10_010
        ldb     #1
        bra     DIV16BY10_020

        DIV16BY10_010:
        clrb

        DIV16BY10_020:
        lda     ,s
        addb    1,s
        adca    #0
        puls    x,pc                        // discard q and return D
    }
}

