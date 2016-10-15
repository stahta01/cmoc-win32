

// Cobado - A CoCo Back Door (keylogger) [All for good reasons]

// The idea of Cobado came to me tonight. I wanted a simple system for
// accessing Windows though a CoCo. Ive been playing with the Becker port
// for a few days, and then it all came together. Why not write a remote
// control interface, which can be controled via a TCP server?

// Cobado hooks into the chrout of the CoCo. It then monitors the keypresses
// and records a buffer of the current command line. When you press enter,
// Cobado is able to intercept and start doing stuff to the CoCo. ie: Poke
// memory, write text, move memory, clear memory, get memory, put memory,
// etc, etc. ie: remote controlling. Once the Cobado server is done,
// control returns to the CoCo, and Cobado waits for more keypresses.

// The system enables you to intercept the command line, and add new commands
// to the CoCo... remotely. There is no need to install, patch, modify the
// ROM, or load in a new DOS, etc.

// Ive only just started to play with this idea, but it should be able todo
// anything. You can even put code into the CoCo's memory, and execute it.

// If I get this working the way I want, you should be able to
// extend a basic CoCo 1,2,3 DOS/NO DOS, even maybe a Dragon, without adding
// more code to the system. I might even be able to run remote app's though
// the CoCo display system.

// Eventually, I want a RS232 version of this idea. Im using the Becker Port
// ATM because VCC/XRoar dont support serial comunications.

asm void cobado_install(void)
{
    asm {
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

        cobado_vector3:
        bsr     vector3
        pshs    d,x,y,u
        tst     111                                 // test devnum
        bne     do_nothing                          // return if not screen
        bsr     becker_send_a                       // send screen char

        command_loop:
        bsr     becker_a
        beq     do_nothing                          // #0
        deca
        beq     do_uninstall                        // #1
        deca
        beq     do_chrout                           // #2
        deca
        beq     do_getmem                           // #3
        deca
        beq     do_setmem                           // #4
        deca
        beq     do_poke                             // #5
        deca
        beq     do_pokew                            // #6
        deca
        beq     do_peek                             // #7
        deca
        beq     do_peekw                            // #8
        deca
        beq     do_memset                           // #9
        deca
        beq     do_memcpy                           // #10
        deca
        beq     do_jsrmem                           // #11

        bra     command_loop

        do_uninstall:
        bsr     cobado_uninstall

        do_nothing:
        puls    d,x,y,u,pc

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

becker_send_d:
        stb     $ff42
becker_send_a:
        sta     $ff42
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
        lda     #1                                  // failed: uninstall
        rts
becker_a_success:
        lda     $ff42
        sta     $ff42
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

vector3:
        fcb     0,0,0

request_time:
        fdb     0
    }
}

int main(void)
{
    cobado_install();
    return 0;
}

