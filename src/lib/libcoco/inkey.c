
#include <equates.h>

// Returns 0 if no key is currently pressed.
//
unsigned char asm inkey()
{
    asm {
        JSR_POLCAT
        tfr     a,b         // byte return value goes in B
    }
}


