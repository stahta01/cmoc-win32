
#include <stdlib.h>
#include <equates.h>

unsigned getenvuint(char* name)
{
    systemf("DEFUSR9=%s", name);
    return ((unsigned*)_usradr)[9];
}

