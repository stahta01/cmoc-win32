
// Contributed by Brian K. Holman (me@brianholman.com)
// Based on information provided by Pierre Sarrazin <http://sarrazip.com/>
// Many thanks, Derek :-)

#include "_float.h"

float_t* _flogbase(float_t* dst, float_t* src, float_t* base)
{
    float_t temp1, temp2;
    return _fdiv(dst, _flog10(&temp1, src), _flog10(&temp2, base));
}

