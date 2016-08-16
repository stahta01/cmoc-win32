
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

// Multiply D by X, unsigned; return result in D; preserve X.

void asm __MUL16(void)
{
    asm {
        MUL16: export

        MUL16:
        pshs    U,X,B,A // U pushed to create 2 temp bytes at 4,S
        ldb     3,S     // low byte of original X
        mul
        std     4,S     // keep for later
        ldd     1,S     // low byte of orig D, high byte of orig X
        mul
        addb    5,S     // only low byte is needed
        stb     5,S
        lda     1,S     // low byte of orig D
        ldb     3,S     // low byte of orig X
        mul
        adda    5,S
        leas    6,S
    }
}



