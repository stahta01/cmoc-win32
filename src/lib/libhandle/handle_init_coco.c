
#include "_handle.h"

#include <coco/ecb_equates.h>

void handle_init_coco(void)
{
    handle_init_common();
    handle_line     = _L94A1;
    handle_getchr   = _LA176;
    handle_putchr   = _PUTCHR;
    handle_sound    = _LA951;
    handle_crunch   = _LB821;
    handle_execute  = _LADC6;
    handle_screen   = _L95AA;
}

