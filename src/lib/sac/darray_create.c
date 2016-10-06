
#include "_sac.h"

darray_t* darray_create(size_t itemsize)
{
    darray_t* array = new(darray_t);
    if (array) {
        darray_init(array, itemsize);
    }
    return array;
}

