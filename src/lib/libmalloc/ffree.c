
#include "_malloc.h"

void _ffree(far_void_t* memory)
{
    far_free(memory);
    free(memory);
}

