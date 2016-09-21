
#include "_heman.h"

int heman_size(void* m)
{
    return m ? ((int*)m)[-1] - sizeof(int) : 0;
}

