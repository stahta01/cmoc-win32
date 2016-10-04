
#include "_malloc.h"

bool _static_mheap_initialized;

heap_t* mheap(void)
{
    heap_t* result = (heap_t*)program_end;
    if (!_static_mheap_initialized) {
        _static_mheap_initialized = true;
        int size = _topram - (int)result - 1024;
        if (size < 1024) {
            exit("OM:HEAP");
        }
        heap_init(result, size);
    }
    return result;
}

