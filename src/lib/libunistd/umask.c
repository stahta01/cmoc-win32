
#include "_unistd.h"

int __umask = 0;

int umask(int pmode)
{
    int ppmode;
    ppmode = __umask;
    __umask = pmode;
    return ppmode;
}

