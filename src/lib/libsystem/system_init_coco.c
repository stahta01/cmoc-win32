
#include <system.h>

void system_init_coco(void)
{
    sysptr_line     = 0x94A1;
    sysptr_getchr   = 0xa176;
    sysptr_putchr   = 0xa282;
    sysptr_sound    = 0xa951;
}

