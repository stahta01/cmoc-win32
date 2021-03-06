
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

asm char* strupr(char* str)
{
    asm {
        pshs    x
        ldx     4,s                             // string address
        bra     strupr_020

        strupr_010:
        cmpa    #97                             // 'a'
        blo     strupr_020
        cmpa    #122                            // 'z'
        bhi     strupr_020
        suba    #32                             // make uppercase
        sta     -1,x

        strupr_020:
        lda     ,x+
        bne     strupr_010
        ldd     4,s                             // return string address
        puls    x,pc
    }
}

