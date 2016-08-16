
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

// Preserves X and U. Trashes D.
unsigned asm memcpy(void* dst, void* src, int n)
{
    asm {
        pshs    u,x
        ldx     6,s         // destination string
        ldu     8,s         // source string
        tfr     u,d
        addd    10,s        // end of destination region
        pshs    b,a
        bra     memcpy_100

        memcpy_050:
        lda     ,u+
        sta     ,x+

        memcpy_100:
        cmpu    ,s          // compare with end address
        bne     memcpy_050

        leas    2,s         // dispose of end address
        ldd     6,s         // return start address
        puls    x,u,pc
    }
}



