
#include <conio.h>
#include <jsr.h>

// TODO: putch should always output to the screen,
// so we should change/restore the output settings.

char putch(char c)
{
    switch (c) {
    case 12:
        asm {
            JSR_CLRSCR
        }
        break;
    default:
        asm {
            lda c
            JSR_CHROUT
        }
    }
    return c;
}










