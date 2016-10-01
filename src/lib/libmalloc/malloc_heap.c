
#include "_malloc.h"

heap_t* _static_heap;

heap_t* malloc_heap(heap_t* heap)
{
    heap_t* result = _static_heap;
    if (heap) {
        _static_heap = heap;
    } else {
        if (!result) {
            result = _static_heap = (heap_t*)program_end;
            // TODO: We should be checking for 16K machines here. They
            // have a lower top of ram.
            heap_init(result, 0x7c00 - (int)result);
        }
    }
    return result;
}

