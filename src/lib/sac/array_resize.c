
#include "_sac.h"

array_t* array_resize(array_t* array, size_t n)
{
    array->items = (byte*)realloc(array->items, (array->count = n) * array->isize);
    return array;
}
