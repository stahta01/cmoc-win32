
#include "_fix6.h"

char _sintable[128] = {
    0,2,3,5,6,8,9,11,12,14,16,17,19,20,22,23,24,26,27,29,30,32,33,34,36,37,38,39,41,42,43,44,45,46,47,
    48,49,50,51,52,53,54,55,56,56,57,58,59,59,60,60,61,61,62,62,62,63,63,63,64,64,64,64,64,64,64,64,64,
    64,64,63,63,63,62,62,62,61,61,60,60,59,59,58,57,56,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,
    39,38,37,36,34,33,32,30,29,27,26,24,23,22,20,19,17,16,14,12,11,9,8,6,5,3,2
};

char sin6(int x)
{
    char xx = (char)x;
    return xx < 0 ? -_sintable[xx - 128] : _sintable[xx];
}

char cos6(int x)
{
    char xx = (char)x + 64;
    return xx < 0 ? -_sintable[xx - 128] : _sintable[xx];
}

