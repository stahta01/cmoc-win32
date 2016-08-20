
#include <stdlib.h>

extern int _main(void);

void asm __program_start(void)
{
    asm {
        endsection
        section start

        INITGL:         extern

        program_start:  export

        program_start:
        lbsr    INILIB          // initialize global variables
        lbsr    __main           // call _main()

        nop_handler:
        rts

        INILIB:
        leax    nop_handler,DAT
        stx     null_ptr_handler,DAT
        ldx     #0
        stx     stack_overflow_handler,DAT
        lbra    INITGL          // initialize global variables

        stack_overflow_handler:
        rmb 2
        null_ptr_handler:
        rmb 2
    }
}




