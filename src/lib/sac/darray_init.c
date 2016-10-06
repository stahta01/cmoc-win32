
#include "_sac.h"

void darray_init(darray_t* array, size_t itemsize)
{
    array->size = 0;
    array->itemsize = itemsize;
    array->data = nullptr;
}

