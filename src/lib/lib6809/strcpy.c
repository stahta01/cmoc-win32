
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


