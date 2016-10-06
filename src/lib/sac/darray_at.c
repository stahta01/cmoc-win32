
#include "_sac.h"

byte* darray_at(darray_t* array, size_t index)
{
    return &array->data[index * array->itemsize];
}

