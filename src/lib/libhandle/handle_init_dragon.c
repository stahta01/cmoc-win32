
#include "_handle.h"

void handle_init_dragon(void)
{
    handle_init_common();
    handle_line     = 0;
    handle_getchr   = 0xb50a;
    handle_putchr   = 0xb54a;
    handle_sound    = 0xbaa0;
    handle_crunch   = 0x8f67;
    handle_execute  = 0x84dc;
    handle_screen   = 0xa938;
}

