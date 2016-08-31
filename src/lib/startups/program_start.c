
#include <stdlib.h>

extern int _main(void);

void asm __program_start(void)
{
    asm {
        // Note: endsection not required but LWTools recommends it.
        endsection

        // WARNING: program_start must be the first section to
        // be linked into the binary. Todo this, we change the
        // section name to SECTION_ORIGIN. This name _MUST_ match
        // the first section listed in /lib/linkscript.txt
        // Otherwise, you will get crashing binaries, and sometimes,
        // XRoar will take down your computer with a blue screen of
        // death. Crazy stuff. I thought emulators were ment to be
        // safe.

        section SECTION_ORIGIN

        INITGL:         extern

        program_start:  export

        program_start:
        lbsr    INILIB          // initialize global variables
        lbsr    __main          // call _main()

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




