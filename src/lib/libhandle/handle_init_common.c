
#include "_handle.h"

#include <equates.h>

void handle_init_common(void)
{
    handle_vidram = _VIDRAM;
    handle_polcat = (handle_t)*(word*)_POLCAT;
    handle_fputc  = (handle_t)*(word*)_CHROUT;
    handle_csrdon = (handle_t)*(word*)_CSRDON;
    handle_blkin  = (handle_t)*(word*)_BLKIN;
    handle_blkout = (handle_t)*(word*)_BLKOUT;
    handle_joyin  = (handle_t)*(word*)_JOYIN;
    handle_wrtldr = (handle_t)*(word*)_WRTLDR;
}

