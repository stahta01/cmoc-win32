
#include <system.h>

void system_init_dragon(void)
{
    sysptr_line     = 0;
    sysptr_getchr   = 0xb50a;
    sysptr_putchr   = 0xb54a;
    sysptr_sound    = 0xbaa0;
    sysptr_crunch   = 0x8f67;
    sysptr_execute  = 0x84dc;
}

