
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

unsigned asm strcpy(char* dest, char* src)
{
    asm {
        pshs    u,x
        ldx     6,s     // destination string
        ldu     8,s     // source string

        strcpy_010:
        lda     ,u+
        sta     ,x+
        bne     strcpy_010

        ldd     6,s     // destination string
        puls    x,u,pc
    }
}



