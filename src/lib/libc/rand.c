
#include <stdlib.h>

unsigned __rand_seed = 0;

void srand(unsigned seed)
{
    __rand_seed = seed;
}

int rand(void)
{
// Note: Taken from here
// http://forth.sourceforge.net/mirror/comus/index.html#random

// Im unsure where these numbers originally came from.

    return (__rand_seed = __rand_seed * 31421 + 6927) & RAND_MAX;
}




