
#include <stdlib.h>

// Clean up before returning control to CoCo DECB.
//
// MUST be called by BSR, LBSR or JSR, not jumped to with BRA, LBRA or JMP,
// so that 2,S can be used to get 'exitStatus'.

void asm exit(int exitStatus)
{
    asm {
        INISTK:  extern
// Zero out the LINBUF line buffer.  This seems necessary to avoid
// ?SN ERROR after program execution on the CoCo.
        ldx     #$2DD

        EXIT10:
        clr     ,X+
        cmpx    #$2DD+1+250
        blo     EXIT10
        ldd     2,S         // get exit() argument
        jsr     $B4F4       // use as USR() return value, in case USR() is the caller
        lds     INISTK,DAT  // retrieve stack pointer saved at beginning
    }
}

