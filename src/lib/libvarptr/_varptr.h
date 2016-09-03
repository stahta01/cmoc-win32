
// varptr.c - Accessing Basic program variables from a CMOC-compiled program.
//
// To be used with VARPTR.BAS, a Basic program that defined several variables
// whose values are displayed by this CMOC-compilable program.
//
// This demo requires a 32k CoCo because of the quantity of variables
// the Basic program creates.
//
// By Pierre Sarrazin <http://sarrazip.com>
// Version 2016-08-21.
// This file is in the public domain.
//
// CMOC Home Page: http://sarrazip.com/dev/cmoc.html
//
// Representation of simple (non-array) variable:
//
// Bytes 0 and 1 are the variable name. Byte 1 is 0 or 0x80 if the
// name has only one letter. Bit 7 of byte 1 is set for a string variable.
// If the variable is numeric, bytes 2..6 are a packed floating point value
// in a format similar to IEEE 754.
// If the variable is a string, byte 2 is the length and bytes 4 and 5
// are the address of the contents (if length > 0).

// Useful Color Basic addresses.
//
enum {
    TXTTAB = 0x0019,                        // beginning of Basic program
    VARTAB = 0x001B,                        // start of variables
    ARYTAB = 0x001D,                        // start of arrays
    ARYEND = 0x001F,                        // end of arrays
    FRETOP = 0x0021,                        // start of string storage
    MEMSIZ = 0x0027,                        // top of string space
};

typedef unsigned char byte;
typedef unsigned word;


