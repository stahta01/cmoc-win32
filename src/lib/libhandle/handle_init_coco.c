
#include "_handle.h"

void handle_init_coco(void)
{
    handle_init_common();
    handle_line     = 0x94A1;
    handle_getchr   = 0xa176;
    handle_putchr   = 0xa282;
    handle_sound    = 0xa951;
    handle_crunch   = 0xb821;
    handle_execute  = 0xadc6;
    handle_screen   = 0x95aa;
}

