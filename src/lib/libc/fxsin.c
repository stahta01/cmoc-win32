
#include <fixpt.h>
#include <motorola.h>

byte table[] = {
    0,6,13,19,25,31,37,44,50,56,62,68,74,80,86,92,98,103,109,115,120,126,131,136,142,147,152,
    157,162,167,171,176,180,185,189,193,197,201,205,208,212,215,219,222,225,228,231,233,236,
    238,240,242,244,246,247,249,250,251,252,253,254,254,255,255,255,255,255,254,254,253,252,
    251,250,249,247,246,244,242,240,238,236,233,231,228,225,222,219,215,212,208,205,201,197,
    193,189,185,180,176,171,167,162,157,152,147,142,136,131,126,120,115,109,103,98,92,86,80,
    74,68,62,56,50,44,37,31,25,19,13,6,0
};

int fxsin(int x)
{
    return _LOBYTE(x) >= 128 ? -(int)table[_LOBYTE(x) - 128] : (int)table[_LOBYTE(x)];
}

int fxcos(int x)
{
    _LOBYTE(x) += 64;
    return _LOBYTE(x) >= 128 ? -(int)table[_LOBYTE(x) - 128] : (int)table[_LOBYTE(x)];
}












