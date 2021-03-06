
#include "_program.h"

void* _static_stack;

void _main(void)
{
    asm {
        sts     _static_stack
    }
    system_init();
    asm {
        INITGL__STDIO_O: extern
        lbsr    INITGL__STDIO_O                 // stdio needs to init stdin/stdout
        // other priority lib calls should be placed here
        lbsr    INITGL                          // initialize global variables
    }
    exit(main());
}

void exit(int status)
{
    if (status) {
        char s[64];
        _itoa(status, stpcpy(s, "EXIT STATUS #"));
        if (status >= 1024) {
            strcat(strcat(s, "\r"), (char*)status);
        }
        system_cputs(s);
    }
    asm {
        lds     _static_stack
        rts                                     // Skip the user stack frame
    }
}

asm void _static_(void)
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

        _program_start:

        leax    nop_handler,pcr
        stx     null_ptr_handler,pcr
        ldx     #0
        stx     stack_overflow_handler,pcr
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

