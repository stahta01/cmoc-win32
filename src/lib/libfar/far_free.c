
#include "_far.h"

void far_free(far_void_t* memory)
{
    heman_free(far_zoom(memory));
    far_zoom(memory);
}

