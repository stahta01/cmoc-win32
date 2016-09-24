
#include "_handle.h"

void handle_init_common(void)
{
    handle_polcat = (handle_t)*(word*)0xa000;
    handle_chrout = (handle_t)*(word*)0xa002;
    handle_csrdon = (handle_t)*(word*)0xa004;
    handle_blkin  = (handle_t)*(word*)0xa006;
    handle_blkout = (handle_t)*(word*)0xa008;
    handle_joyin  = (handle_t)*(word*)0xa00a;
    handle_wrtldr = (handle_t)*(word*)0xa00c;
}

