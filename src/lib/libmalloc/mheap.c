
#include "_malloc.h"

bool _static_mheap_initialized;

heap_t* mheap(void)
{
    heap_t* result = (heap_t*)program_end;
    if (!_static_mheap_initialized) {
        _static_mheap_initialized = true;
        // TODO: We should be checking for 16K machines here. They
        // have a lower top of ram.
        heap_init(result, 0x7c00 - (int)result);
    }
    return result;
}

