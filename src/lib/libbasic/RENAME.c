
#include <basic.h>

int RENAME(char* f1, char* f2)
{
    return systemf("RENAME \"%s\" TO \"%s\"", f1, f2);
}

