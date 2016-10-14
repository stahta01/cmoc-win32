
#include "_basic.h"

int COPY(char* f1, char* f2)
{
    return systemf("COPY \"%s\" TO \"%s\"", f1, f2);
}

