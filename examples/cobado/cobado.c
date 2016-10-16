
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
// ROM, or load in a new DOS.

// Ive only just started to play with this idea, but it should be able todo
// anything. You can even put code into the CoCo's memory, and execute it.

// If I get this working the way I want, you should be able to
// extend a basic CoCo 1,2,3 DOS/NO DOS, even maybe a Dragon, without adding
// more code to the system. I might even be able to run remote app's though
// the CoCo display system.

// Eventually, I want a RS232 version of this idea. Im using the Becker Port
// ATM because VCC/XRoar dont support serial comunications.

#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define COBADO_EXEC 0x1d1

extern byte cobado_start[1];
extern byte cobado_end[1];

asm void cobado_install(void)
{
    asm {
        _cobado_start:
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

        cobado_vector3:
        bsr     vector3
        pshs    d,x,y
        tst     $6f                                 // test devnum
        bne     do_return                           // return if not screen
        bsr     becker_send_a                       // send screen char

        command_loop:
        bsr     becker_a
        beq     do_uninstall                        // #0
        deca
        beq     do_return                           // #1
        deca
        beq     do_chrout                           // #2
        deca
        beq     do_getmem                           // #3
        deca
        beq     do_setmem                           // #4
        deca
        beq     do_jsrmem                           // #5
        bra     command_loop

        do_uninstall:
        bsr     cobado_uninstall

        do_return:
        puls    d,x,y,pc

        do_chrout:
        bsr     becker_a                            // chr to output
        jsr     $a30a
        bra     command_loop

        do_getmem:
        bsr     becker_x                            // src
        bsr     becker_y                            // count
        addd    #0
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
        addd    #0
        beq     command_loop
        do_setmem_loop:
        bsr     becker_a
        sta     ,x+
        dey
        bne     do_setmem_loop
        bra     command_loop

        do_jsrmem:
        bsr     becker_x                            // routine address
        jsr     ,x
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
        subd    #2*60
        puls    b
        blo     becker_a_loop
        clra                                        // failed: uninstall
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
_cobado_end:
    }
}

int main(void)
{
    size_t size = cobado_end - cobado_start;

    clrscr();
    cprintf("COBADO BIOS SIZE: %d BYTES\n", size);
    memcpy(COBADO_EXEC, cobado_start, size);
    cputs("SAVING COBADO BIOS TO DISK ...\n\n");
    systemf("SAVEM \"COBADO.BIN\",%u,%u,%u", COBADO_EXEC, COBADO_EXEC + size, COBADO_EXEC);
    cputs("DONE. TO INSTALL TYPE:\n");
    cputs("LOADM \"COBADO\":EXEC\n\nBACK TO BASIC\n");
    return 0;
}

