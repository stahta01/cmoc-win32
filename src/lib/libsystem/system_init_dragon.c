
#include <system.h>

void system_init_dragon(void)
{
    sysptr_line     = 0;
    sysptr_getchr   = 0xb50a;
    sysptr_putchr   = 0xb54a;
    sysptr_sound    = 0xbaa0;
}

