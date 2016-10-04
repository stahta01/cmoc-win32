
#include "_sac.h"

array_t* array_create(size_t isize)
{
    array_t* array = (array_t*)malloc(sizeof(array_t));
    if (array) {
        array_init(array, isize);
    }
    return array;
}

