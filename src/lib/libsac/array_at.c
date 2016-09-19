
#include "_sac.h"

unsigned char* array_at(array_t* array, size_t index)
{
    return &array->items[index * array->isize];
}

