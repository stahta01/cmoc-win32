
#include <conio.h>
#include <equates.h>

// TODO: putch should always output to the screen,
// so we should change/restore the output settings.

char putch(char c)
{
    asm {
        lda c
        JSR_CHROUT
    }
    return c;
}











