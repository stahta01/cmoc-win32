
#include <vectrex.h>

asm void vectrex_init_os()
{
    asm {
        jsr Init_OS
    }
}

