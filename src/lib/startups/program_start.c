
#include <stdio.h>
#include <stdlib.h>
#include <system.h>
#include <heman.h>

extern int main(void);

unsigned _static_exitstack;

void _main(void)
{
    asm {
        sts     _static_exitstack
    }
    system_init();
    heap_init(heap_memory, 0x7c00 - (int)heap_memory);
    asm {
        INITGL__STDIO_O: extern
        lbsr    INITGL__STDIO_O                 // stdio needs to init stdin/stdout
         // other important lib calls should be placed here
        lbsr    INITGL                          // initialize global variables
    }
    exit(main());
}

void exit(int status)
{
    if (status) {
        printf("EXIT STATUS: %d\n", status);
    }
    //memset(0x2dd, 0, 250);
    asm {
        lds _static_exitstack
        rts                                     // Skip the user stack frame
    }
}

asm void _static_program_start(void)
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

        leax    nop_handler,DAT
        stx     null_ptr_handler,DAT
        ldx     #0
        stx     stack_overflow_handler,DAT
        lbsr    __main                          // call _main()
        rts                                     // Return to BASIC

        nop_handler:
        rts
        stack_overflow_handler:
        rmb 2
        null_ptr_handler:
        rmb 2
    }
}

