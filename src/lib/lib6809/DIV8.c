
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

// Divide A by B, unsigned; return quotient in B, remainder in A.
// Does not preserve X.

asm void _static_(void)
{
    asm {
        DIV8: export

        DIV8:
        pshs    a                               // push dividend
        pshs    b                               // push divisor
        lda     #8                              // loop counter
        clrb
        pshs    b

// 0,S=8-bit quotient;
// 1,S=8-bit divisor; 2,S=8-bit dividend

        DV8010:
        lsl     2,s                             // shift dividend into carry
        rolb                                    // new bit of dividend now in bit 0 of B
        cmpb    1,s                             // does the divisor "fit" into B?
        blo     DV8020                          // if not
        subb    1,s
        orcc    #1                              // set carry
        bra     DV8030

        DV8020:
        andcc   #$FE                            // reset carry

        DV8030:
        rol     ,s                              // shift carry into quotient

        deca                                    // another bit of the dividend to process?
        bne     DV8010                          // if yes

        tfr     b,a                             // remainder to return
        puls    b                               // quotient to return
        leas    2,s
        rts
    }
}

