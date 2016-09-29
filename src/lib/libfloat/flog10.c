
// Contributed by Brian K. Holman (me@brianholman.com)
// Based on information provided by Pierre Sarrazin <http://sarrazip.com/>
// Many thanks, Derek :-)

#include "_float.h"

float_t* _flog10(float_t* dst, float_t* src)
{
    // log10 (x) equals log (x) / log (10)
    float_t temp;
    _flog(&temp, src);
    _fdiv(dst, &temp, (float_t*)FP_LOGOF10);
    return (dst);
}

