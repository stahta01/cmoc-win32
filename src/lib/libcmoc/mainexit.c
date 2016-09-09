
#include "_cmoc.h"

unsigned exitstack;
unsigned char _get_ostype;

void _main(void)
{
    asm {
        leax    0,s
        stx     _exitstack,DAT
    }
    _get_ostype = get_ostype();
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

