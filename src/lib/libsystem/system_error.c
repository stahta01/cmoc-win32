
#include "_system.h"

asm void system_error(errno_t err, word line)
{
    asm {
        ldd     4,s
        std     _CURLIN
        ldb     3,s
        jmp     [handle_error]
    }
}

