
#include <vectrex.h>

asm void vectrex_init_os_ram()
{
    asm {
        jsr   Init_OS_RAM
    }
}

