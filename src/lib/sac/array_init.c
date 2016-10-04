
#include "_sac.h"

void array_init(array_t* array, size_t isize)
{
    array->count = 0;
    array->isize = isize;
    array->items = nullptr;
}

