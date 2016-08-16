
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

unsigned asm strncpy(char* dest, char* src, int n)
{
    asm {
        pshs    u,y,x
        ldx     8,s             // destination string
        ldu     10,s            // source string
        ldy     #0              // counts bytes filled
        bra     strncpy_020

        strncpy_010:
        lda     ,u+             // is next source byte terminator?
        beq     strncpy_050     // yes

        sta     ,x+             // store in destination string
        leay    1,y             // one more byte filled

        strncpy_020:
        cmpy    12,s            // filled all bytes to fill?
        blo     strncpy_010     // no

        bra     strncpy_090

        strncpy_040:
        clr     ,x+             // pad with '\0'
        leay    1,y

        strncpy_050:
        cmpy    12,s            // filled all bytes to fill?
        blo     strncpy_040     // no

        strncpy_090:
        ldd     8,s             // destination string
        puls    x,y,u,pc
    }
}




