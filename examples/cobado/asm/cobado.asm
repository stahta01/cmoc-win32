    pragma  6809,6800compat ;,autobranchlength

    org     465

cobado_install:
    leax    cobado_vector3,pcr
    cmpx    $168
    beq     cobado_uninstall
    lda     $167
    sta     vector3+0,pcr
    ldd     $168
    std     vector3+1,pcr
    lda     #$7E
    sta     $167
    stx     $168
    rts

cobado_uninstall:
    lda     vector3+0,pcr
    sta     $167
    ldd     vector3+1,pcr
    std     $168
    rts

vector3:
    fcb     0,0,0

request_time:
    fdb     0

becker_send_d:
    stb     $ff42
becker_send_a:
    sta     $ff42
    rts

cobado_vector3:
    lbsr     vector3
    pshs    d,x,y,u
    tst     111
    bne     do_nothing
    bsr     becker_send_a

command_loop:
    lbsr    becker_a
    beq     do_nothing
    deca
    beq     do_uninstall
    deca
    beq     do_chrout
    deca
    beq     do_getmem
    deca
    beq     do_setmem
    deca
    beq     do_memset
    deca
    beq     do_memcpy
    deca
    beq     do_jsrmem
    bra     command_loop

do_uninstall:
    bsr     cobado_uninstall

do_nothing:
    puls    d,x,y,u,pc

do_chrout:
    bsr     becker_a
    jsr     $a30a
    bra     command_loop

do_getmem:
    bsr     becker_x
    bsr     becker_y
    beq     command_loop

do_getmem_loop:
    lda     ,x+
    bsr     becker_send_a
    dey
    bne     do_getmem_loop
    bra     command_loop

do_setmem:
    bsr     becker_x
    bsr     becker_y
    beq     command_loop

do_setmem_loop:
    bsr     becker_a
    sta     ,x+
    dey
    bne     do_setmem_loop
    bra     command_loop

do_memcpy:
    bsr     becker_x
    bsr     becker_d
    tfr     d,u
    bsr     becker_y
    beq     command_loop
do_memcpy_loop:
    lda     ,u+
    sta     ,x+
    dey
    bne     do_memcpy_loop
    bra     command_loop

do_memset:
    bsr     becker_x
    bsr     becker_a
    tfr     d,y
    bsr     becker_d
    beq     command_loop
    exg     d,y
do_memset_loop:
    sta     ,x+
    dey
    bne     do_memset_loop
    bra     command_loop

do_jsrmem:
    bsr     becker_x
    jsr     [,x]
    bra     command_loop

becker_x:
    bsr     becker_d
    tfr     d,x
    rts

becker_y:
    bsr     becker_d
    tfr     d,y
    rts

becker_d:
    bsr     becker_a
    tfr     a,b
becker_a:
    pshs    b
    ldd     $112
    std     request_time,pcr
    puls    b
becker_a_loop:
    lda     $ff41
    anda    #2
    bne     becker_a_success
    pshs    b
    ldd     $112
    subd    request_time,pcr
    cmpd    #2*60
    puls    b
    blo     becker_a_loop
    lda     #1
    rts
becker_a_success:
    lda     $ff42
    sta     $ff42
    rts


