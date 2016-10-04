
#include "_sac.h"

void array_free(array_t* array)
{
    array_clear(array);
    free(array);
}

