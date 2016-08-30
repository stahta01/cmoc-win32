
#include <stdlib.h>
#include <equates.h>

unsigned __rand_seed = 0;

void srand(unsigned seed)
{
    __rand_seed = seed;
}

int rand(void)
{
    return __rand_seed = __rand_seed * 30421 + 6927 ^ *(unsigned*)_TIMVAL;
}

