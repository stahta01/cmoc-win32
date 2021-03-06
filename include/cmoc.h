
// cmoc.h - CMOC's standard library functions.
//
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Functions not documented here should be assumed to behave as in C.

#ifndef _CMOC_H
#define _CMOC_H

// Double-word to ASCII.
// Converts the unsigned 32-bit integer formed by hi * 65536 + lo into
// an ASCII decimal representation that gets written to 'out'.
// 'out' must point to at least 11 bytes. The string written there will
// be terminated by a null character.
// Returns the address of the first non-'0' character in the 11-byte
// buffer, or to "0" if hi and lo are both zero.
// Example: char s[11]; char *p = dwtoa(s, 1, 2);
//          s will get the string "
//
char* dwtoa(char* out, unsigned hi, unsigned lo);

// Divides an unsigned 32-bit integer by an unsigned 8-bit integer.
// The 4 bytes designated by 'dividendInQuotientOut' are the input dividend.
// The 32-bit quotient is left in those 4 bytes.
//
void div328(byte* dividendInQuotientOut, byte divisor);

// Multiply a word by a byte.
// Stores the high word of the product in *hi and returns the low word.
//
unsigned mulwb(unsigned char* hi, unsigned wordFactor, unsigned char byteFactor);

// Similar to mulwb().
unsigned mulww(unsigned* hi, unsigned factor0, unsigned factor1);

// Stores 0 in twoWords[0], twoWords[1].
//
void zerodw(unsigned* twoWords);

// Adds the 16-bit integer 'term' to the 32-bit integer designated by
// twoWords[0] and twoWords[1].
//
void adddww(unsigned* twoWords, unsigned term);

// byte sub32(word *hi, word h, word l)
// Subtracts 32-bit integer h:l from 32-bit unsigned integer
// pointed by 'hi'.
// Returns carry of the subtraction.
//
byte sub32(word* hi, word h, word l);

sbyte dwcompare(word* a, word* b);

#endif

