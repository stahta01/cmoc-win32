
asm {
    ldy     ANUM
    beq     LEXIT
    ldx     ADST
#ifdef ASRC
    stu     -2,s
    ldu     ASRC
#endif
#ifdef ACHR
    lda     1+ACHR
#endif
    ldb     1+ANUM
    andb    #7
    beq     LCOPY8
    negb
    leay    b,y
    negb
    LCOPY1:
    LOAD1
    SAVE1
    decb
    bne     LCOPY1
    cmpy    #0
    beq     LEXIT
    LCOPY8:
    tfr     a,b
    LLOOP8:
    LOAD2
    SAVE2
    LOAD2
    SAVE2
    LOAD2
    SAVE2
    LOAD2
    SAVE2
    leay    -8,y
    bne     LLOOP8
    LEXIT:
    ldd     ADST
#ifdef ASRC
    ldu     -2,s
#endif
}

