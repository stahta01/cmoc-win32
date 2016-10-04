
#include "_gmalloc.h"

bool _static_gheap_initialized;

heap_t* gheap(void)
{
    heap_t* result = (heap_t*)((word)_grpram << 8);
    if (!_static_gheap_initialized) {
        _static_gheap_initialized = true;
        heap_init(result, (_txttab - 1) - (word)result);
    }
    return result;
}

