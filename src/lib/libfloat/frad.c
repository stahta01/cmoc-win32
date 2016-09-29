
// Contributed by Brian K. Holman (me@brianholman.com)
// Based on information provided by Pierre Sarrazin <http://sarrazip.com/>
// Many thanks, Derek :-)

#include "_float.h"

float_t* _frad(float_t* dst, float_t* deg)
{
    _fdiv(dst, deg, (float_t*)FP_RAD_TO_DEG);
    return (dst);
}

