
#include "_sac.h"

void darray_free(darray_t* array)
{
    darray_clear(array);
    free(array);
}

