
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

// Divide X by D, unsigned; return quotient in X, remainder in D.

void asm __DIV16(void)
{
    asm {
        DIV16: export

        DIV16:
        pshs    X,B,A
        ldb     #16
        pshs    B
        clra
        clrb
        pshs    B,A

// 0,S=16-bit quotient; 2,S=loop counter;
// 3,S=16-bit divisor; 5,S=16-bit dividend

        D16010:
        lsl     6,S                         // shift MSB of dividend into carry
        rol     5,S                         // shift carry and MSB of dividend, into carry
        rolb                                // new bit of dividend now in bit 0 of B
        rola
        cmpd    3,S                         // does the divisor "fit" into D?
        blo     D16020                      // if not
        subd    3,S
        orcc    #1                          // set carry
        bra     D16030

        D16020:
        andcc   #$FE                        // reset carry

        D16030:
        rol     1,S                         // shift carry into quotient
        rol     ,S

        dec     2,S                         // another bit of the dividend to process?
        bne     D16010                      // if yes

        puls    X                           // quotient to return
        leas    5,S

    }
}

