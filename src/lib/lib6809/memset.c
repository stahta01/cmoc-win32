
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

unsigned asm memset(void* s, int c, unsigned n)
{
    asm {
        pshs    u
        tfr     s,u
        leas    -2,s            // end address

        ldd     4,u             // start address (s)
        tfr     d,x
        addd    8,u             // add number of bytes (n) to get end address
        std     -2,u            // store in local var

        lda     7,u             // byte to write (c)
        bra     memset_cond

        memset_loop:
        sta     ,x+

        memset_cond:
        cmpx    -2,u            // at end?
        bne     memset_loop     // no, continue

        ldd     4,u             // return start address
        tfr     u,s
        puls    u,pc
    }
}


