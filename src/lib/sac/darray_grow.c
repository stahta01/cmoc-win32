
#include "_sac.h"

darray_t* darray_grow(darray_t* array, size_t size)
{
    return darray_resize(array, array->size + size);
}

