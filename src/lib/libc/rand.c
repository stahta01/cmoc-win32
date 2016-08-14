
#include <stdlib.h>

unsigned __rand_seed = 0;

void srand(unsigned seed)
{
    __rand_seed = seed;
}

int rand(void)
{
    return (__rand_seed = __rand_seed * 13709 + 13849) & RAND_MAX;
}




