
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

unsigned asm strlwr(char* str)
{
    asm {
        pshs    x
        ldx     4,s                         // string address
        bra     strlwr_020

        strlwr_010:
        cmpa    #65                         // 'A'
        blo     strlwr_020
        cmpa    #90                         // 'Z'
        bhi     strlwr_020
        adda    #32                         // make lowercase
        sta     -1,x

        strlwr_020:
        lda     ,x+
        bne     strlwr_010
        ldd     4,s                         // return string address
        puls    x,pc
    }
}

