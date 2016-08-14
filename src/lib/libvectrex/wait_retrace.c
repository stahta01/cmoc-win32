
#include <vectrex.h>

// This call waits for timer two to timeout and restarts it, it then recalibrates the vector generators to
// coordinate (0, 0) it also calls the BIOS routine behind reset_beam in the process.
void asm wait_retrace()
{
    asm {
        JSR Wait_Recal
    }
}

