
#include "_unistd.h"

int _static_umask = 0;

int umask(int mode)
{
    int result = _static_umask;
    _static_umask = mode;
    return result;
}

