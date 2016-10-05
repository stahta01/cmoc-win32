
#include <vectrex.h>

// Reset the beam to the middle of the screen.
// This is necassary from time to time as there is drift on the Vectrex integrators.
// Caling this makes coordinate (0,0) the middle of the screen.
void vectrex_reset_beam()
{
    asm {
        JSR Reset0Ref
    }
}

