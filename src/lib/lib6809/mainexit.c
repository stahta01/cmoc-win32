
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int main(void);
extern unsigned exitstack;

unsigned exitstack;

void _main(void)
{
    asm {
        leax    0,s
        stx     _exitstack,DAT
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
        lds _exitstack,DAT
        rts // Skip the user stack frame
    }
}



