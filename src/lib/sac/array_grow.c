
#include "_sac.h"

array_t* array_grow(array_t* array, size_t n)
{
    return array_resize(array, array->count + n);
}

