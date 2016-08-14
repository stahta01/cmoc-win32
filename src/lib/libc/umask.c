/*---------------------------------------------------------------------------*/
/* umask() - set default file permission mask                                */
/*---------------------------------------------------------------------------*/

#include <crt.h>

int _crt_umask = 0;

int umask(int pmode)
{
    int ppmode;
    ppmode = _crt_umask;
    _crt_umask = pmode;
    return ppmode;
}

