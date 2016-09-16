
#define asm_argword(X) X*2,s
#define asm_argbyte(X) X*2+1,s

asm {
    ldy     asm_argword(3)
    beq     exit$
    ldx     asm_argword(1)
#ifdef IS_COPY
    stu     asm_argword(-1)
    ldu     asm_argword(2)
#else
    lda     asm_argbyte(2)
#endif
    ldb     asm_argbyte(3)
    andb    #7
    beq     copy8$
    negb
    leay    b,y
    negb
copy1$:
    LOAD1
    SAVE1
    decb
    bne     copy1$
    cmpy    #0
    beq     exit$
copy8$:
    tfr     a,b
loop8$:
    LOAD2
    SAVE2
    LOAD2
    SAVE2
    LOAD2
    SAVE2
    LOAD2
    SAVE2
    leay    -8,y
    bne     loop8$
exit$:
    ldd     2,s
#ifdef IS_COPY
    ldu     asm_argword(-1)
#endif
}

