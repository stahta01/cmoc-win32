
#include "_malloc.h"

int _msize(void* m)
{
    return m ? ((int*)m)[-1] - sizeof(int) : 0;
}

