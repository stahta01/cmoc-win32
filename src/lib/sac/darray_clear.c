
#include "_sac.h"

darray_t* darray_clear(darray_t* array)
{
    return darray_resize(array, 0);
}

