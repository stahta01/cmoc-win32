
#include <system.h>

void system_init_coco(void)
{
    sysptr_line     = 0x94A1;
    sysptr_getchr   = 0xa176;
    sysptr_putchr   = 0xa282;
    sysptr_sound    = 0xa951;
    sysptr_crunch   = 0xb821;
    sysptr_execute  = 0xadc6;
}

