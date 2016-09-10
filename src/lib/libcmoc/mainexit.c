
#include "_cmoc.h"

unsigned exitstack;

void _main(void)
{
    asm {
        leax    0,s
        stx     _exitstack,DAT
    }
    system_init();
    exit(main());
}

void exit(int status)
{
    if (status) {
        printf("EXIT STATUS: %d\n", status);
    }
    //memset(0x2dd, 0, 250);
    asm {
        lds _exitstack,DAT
        rts                                 // Skip the user stack frame
    }
}

