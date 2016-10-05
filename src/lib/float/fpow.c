
// Contributed by Brian K. Holman (me@brianholman.com)
// Based on information provided by Pierre Sarrazin <http://sarrazip.com/>
// Many thanks, Derek :-)

#include "_float.h"

float_t* _fpow(float_t* dst, float_t* base, float_t* power)
{
    // base^power = exp(log(base) * power)
    float_t temp1, temp2, temp3;
    if (_fsign(base) > 0) {
        _flog(&temp1, base);
        _fmul(&temp2, &temp1, power);
        // Prevent BASIC terminating the call with an overflow of exp
        _fsub(&temp3, &temp2, (float_t*)FP_MAXEXP);
        if (_fsign(&temp3) <= 0) {
            return _fexp(dst, &temp2);
        }
    }
    return nullptr;
}

