
#include "_malloc.h"

bool _static_mheap_setup;

heap_t* mheap(void)
{
    if (!_static_mheap_setup) {
        _static_mheap_setup = true;
        // TODO: We should be checking for 16K machines here. They
        // have a lower top of ram.
        heap_init((heap_t*)program_end, 0x7c00 - (int)program_end);
    }
    return (heap_t*)program_end;
}

