
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

// Future RS232 Notes:

// L8DBC = RS232 read. A = data. Z = 0 = timeout.
// L8E0C = RS232 write. A = data.

// Store Cobado BIOS into cas buffer.

#define COBADO_EXEC 0x1da

#define _RVEC12     386
#define _LINBUF     732

extern byte cobado_start[1];
extern byte cobado_end[1];

asm void cobado_install(void)
{
    asm {
        _cobado_start:
        leax    cobado_vector,pcr
        cmpx    _RVEC12+1                           // check if already installed
        beq     cobado_uninstall                    // uninstall if we are installed
        lda     _RVEC12+0                           // save current vector 12
        sta     vector12+0,pcr
        ldd     _RVEC12+1
        std     vector12+1,pcr
        lda     #$7E                                // install new vector 12
        sta     _RVEC12+0
        stx     _RVEC12+1
        rts

        cobado_uninstall:
        lda     vector12+0,pcr                      // restore old vector 12
        sta     _RVEC12+0
        ldd     vector12+1,pcr
        std     _RVEC12+1
        cobado_rts:
        rts

        vector12:
        fcb     0,0,0

        cobado_vector:
        bsr     vector12                            // branch to old vector12
        puls    x                                   // pull return address
        jsr     ,x                                  // execute caller
        bcs     cobado_rts                          // exit if break key hit
        pshs    d,x,y,cc                            // push registers
        inx                                         // x = start of line buffer
        send_line_buffer:
        lda     ,x+                                 // get char from line buffer
        bsr     becker_send_a                       // send to server
        bne     send_line_buffer                    // repeat until null

        command_loop:
        bsr     becker_a                            // get command from server
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
        bra     command_loop                        // repeat until #0 (uninstall) or #1 (return)

        do_uninstall:                               // uninstall cobado and return
        bsr     cobado_uninstall

        do_return:                                  // return from cobado hook
        puls    d,x,y,cc,pc

        do_chrout:
        bsr     becker_a                            // chr to output
        jsr     [$a002]                             // $a30a
        bra     command_loop

do_getmem:
        bsr     becker_x                            // src
        bsr     becker_y                            // count
        addd    #0                                  // exit if count = 0
        beq     command_loop
do_getmem_loop:
        lda     ,x+                                 // get a byte
        bsr     becker_send_a                       // send to server
        dey                                         // decrease counter
        bne     do_getmem_loop                      // repeat until done
        bra     command_loop

do_setmem:
        bsr     becker_x                            // dst
        bsr     becker_y                            // count
        addd    #0                                  // exit if count = 0
        beq     command_loop
do_setmem_loop:
        bsr     becker_a                            // get a byte from server
        sta     ,x+                                 //store the byte
        dey                                         // decrease counter
        bne     do_setmem_loop                      // repeat until done
        bra     command_loop

do_jsrmem:
        bsr     becker_x                            // x = routine address
        jsr     ,x                                  // jump to rountine
        bra     command_loop

becker_send_d:
        stb     $ff42                               // send b (low) byte to server
becker_send_a:
        sta     $ff42                               // send a (high) byte to server
        rts

request_time:
        fdb     0                                   // request tick. used for timeouts

becker_d:
        bsr     becker_a                            // get low byte from server
        tfr     a,b                                 // b = low byte
becker_a:
        pshs    b                                   // save b
        ldd     $112                                // get current time
        std     request_time,pcr                    // store time
        puls    b                                   // restore b
becker_a_loop:
        lda     $ff41                               // check beckers data status
        anda    #2
        bne     becker_a_success                    // branch if data avaliable
        pshs    b                                   // save b
        ldd     $112                                // get current time
        subd    request_time,pcr                    // subtract start time
        subd    #2*60                               // subtract timeout (2 seconds)
        puls    b                                   // restore b
        blo     becker_a_loop                       // repeat until timeout or data
        clra                                        // if timeout then uninstall
        rts
becker_a_success:
        lda     $ff42                               // get byte from server
        sta     $ff42                               // echo byte to server
        rts

becker_x:
        bsr     becker_d                            // get d (word) from server
        tfr     d,x                                 // x = d
        rts

becker_y:
        bsr     becker_d                            // get d (word) from server
        tfr     d,y                                 // y = d
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

