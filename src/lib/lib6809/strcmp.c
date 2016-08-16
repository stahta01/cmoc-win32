
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

int asm strcmp(char* s1, char* s2)
{
    asm {
        pshs    u,x
        ldx     6,s         // 1st string
        ldu     8,s         // 2nd string

        strcmp_050:
        ldb     ,u+
        lda     ,x+
        bne     strcmp_010
        tstb
        beq     strcmp_900  // return 0 (in B)


        strcmp_040:         // a zero but b non zero, so 1st string comes before
        ldb     #$ff
        bra     strcmp_900

        strcmp_010:
        tstb
        bne     strcmp_020

        strcmp_030:         // a non zero but b zero, so 1st string comes after
        ldb     #1
        bra     strcmp_900

        strcmp_020:         // a and b non zero.
        cmpa    -1,u
        bhi     strcmp_030  // return +1
        blo     strcmp_040  // return -1
        bra     strcmp_050

        strcmp_900:
        sex
        puls    x,u,pc
    }
}



