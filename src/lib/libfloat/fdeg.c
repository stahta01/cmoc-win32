
// Contributed by Brian K. Holman (me@brianholman.com)
// Based on information provided by Pierre Sarrazin <http://sarrazip.com/>
// Many thanks, Derek :-)

#include "_float.h"

float_t* _fdeg(float_t* dst, float_t* rad)
{
    return _fmul(dst, rad, (float_t*)FP_RAD_TO_DEG);
}

