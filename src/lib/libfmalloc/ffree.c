
#include "_fmalloc.h"

void ffree(far_void_t* memory)
{
    far_free(memory);
    free(memory);
}

