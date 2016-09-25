
#include "_far.h"

size_t far_size(far_void_t* memory)
{
    size_t size = heap_msize(far_zoom(memory));
    far_zoom(memory);
    return size;
}

