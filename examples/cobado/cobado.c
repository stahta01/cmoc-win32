
extern word vec3[2];

word vec3[2];

void cobado_install(void)
{
    if (*(word*)0x168 != cobado) {
        vec3[0] = *(word*)0x167;
        vec3[1] = *(word*)0x169;
        *(byte*)0x167 = 0x7E;
        *(word*)0x168 = cobado;
    }
}

asm void cobado(void)
{
    asm {
        bsr     _vec3
        pshs    d,x,y,u
        tst     111                                 // test devnum
        bne     do_nothing                          // return if not screen
        bsr     becker_send_a                       // set back screen char

        command_loop:

        bsr     becker_a                            // get command code
        beq     do_nothing                          // #0
        deca
        beq     do_chrout                           // #1
        deca
        beq     do_getmem                           // #2
        deca
        beq     do_setmem                           // #3
        deca
        beq     do_poke                             // #4
        deca
        beq     do_pokew                            // #5
        deca
        beq     do_peek                             // #6
        deca
        beq     do_peekw                            // #7
        deca
        beq     do_memset                           // #8
        deca
        beq     do_memcpy                           // #9
        deca
        beq     do_jsrmem                           // #10

        bra     command_loop

        do_nothing:
        puls    d,x,y,u,pc

        becker_send_d:
        stb     $ff42
        becker_send_a:
        sta     $ff42
        rts

        becker_a:
        lda     $ff41
        anda    #2
        beq     becker_a
        lda     $ff42
        sta     $ff42
        rts

        becker_d:
        bsr     becker_a                            // lo byte
        tfr     a,b
        bsr     becker_a                            // hi byte
        rts

        becker_x:
        bsr     becker_d
        tfr     d,x
        rts

        becker_y:
        bsr     becker_d
        tfr     d,y
        rts

        becker_u:
        bsr     becker_d
        tfr     d,u
        rts

        do_chrout:
        bsr     becker_a                            // chr to output
        jsr     $a30a
        bra     command_loop

        do_getmem:
        bsr     becker_x                            // src
        bsr     becker_y                            // count
        beq     command_loop
        do_getmem_loop:
        lda     ,x+
        bsr     becker_send_a
        dey
        bne     do_getmem_loop
        bra     command_loop

        do_setmem:
        bsr     becker_x                            // dst
        bsr     becker_y                            // count
        beq     command_loop
        do_setmem_loop:
        bsr     becker_a
        sta     ,x+
        dey
        bne     do_setmem_loop
        bra     command_loop

        do_poke:
        bsr     becker_x                            // dst
        bsr     becker_a                            // value
        sta     ,x
        bra     command_loop

        do_pokew:
        bsr     becker_x                            // dst
        bsr     becker_d                            // value
        std     ,x
        bra     command_loop

        do_peek:
        bsr     becker_x                            // src
        lda     ,x                                  // value
        bsr     becker_send_a
        bra     command_loop

        do_peekw:
        bsr     becker_x                            // src
        ldd     ,x                                  // value
        bsr     becker_send_d
        bra     command_loop

        do_memcpy:
        bsr     becker_x                            // dst
        bsr     becker_u                            // src
        bsr     becker_y                            // count
        beq     command_loop
        do_memcpy_loop:
        lda     ,u+
        sta     ,x+
        dey
        bne     do_memcpy_loop
        bra     command_loop

        do_memset:
        bsr     becker_x                            // dst
        bsr     becker_a                            // value
        tfr     d,y                                 // save a in y
        bsr     becker_d                            // count
        beq     command_loop
        exg     d,y                                 // restore a and y = count
        do_memset_loop:
        sta     ,x+
        dey
        bne     do_memset_loop
        bra     command_loop

        do_jsrmem:
        bsr     becker_x                            // routine address
        jsr     [,x]
        bra     command_loop
    }
}

int main(void)
{
    cobado_install();
    return 0;
}

