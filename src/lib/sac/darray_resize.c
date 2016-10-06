
#include "_sac.h"

darray_t* darray_resize(darray_t* array, size_t size)
{
    array->size = size;
    if (size) {
        void* data = realloc(array->data, size * array->itemsize);
        if (data) {
            array->data = (byte*)data;
        }
    } else {
        free(array->data);
        array->data = nullptr;
    }
    return array;
}

