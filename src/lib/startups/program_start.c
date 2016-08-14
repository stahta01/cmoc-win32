
#include <stdlib.h>

extern int main(void);

void asm __program_start(void)
{
    asm {
        endsection
        section start

        INITGL:         extern

        program_start:  export
        INISTK:         export

        program_start:
        lbsr    INILIB          // initialize global variables
        lbsr    _main           // call main()
        pshs    B,A             // send main() return value to exit()
        lbra    _exit           // use LBSR to respect calling convention

        nop_handler:
        rts

        INILIB:
        leax    2,S             // X = initial stack pointer
        stx     INISTK,DAT      // save this for exit()
        leax    nop_handler,DAT
        stx     null_ptr_handler,DAT
        ldx     #0
        stx     stack_overflow_handler,DAT
        lbra    INITGL          // initialize global variables

        INISTK:
        rmb 2                   // receives initial stack pointer
        stack_overflow_handler:
        rmb 2
        null_ptr_handler:
        rmb 2
    }
}




