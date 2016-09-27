
// Defines a float type for the Microsoft Binary Format
//
// The CoCo uses MBF extended-precision format (40 bits, "9?-digit BASIC"):
// https://en.wikipedia.org/wiki/Microsoft_Binary_Format

#ifndef _SYS_FLOAT_H
#define _SYS_FLOAT_H

typedef struct {
    char        exp;                            // EXPONENT
    int         msb;                            // SIGN + MSB's
    unsigned    lsb;                            // LSB's
} _CRT_FLOAT, float_t;

#endif

