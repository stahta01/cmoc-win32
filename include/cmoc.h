
// cmoc.h - CMOC's standard library functions.
//
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Functions not documented here should be assumed to behave as in C.

#ifndef _CMOC_H
#define _CMOC_H

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include <peekpoke.h>

#include <motorola/types.h>

// 3 bits for the machine

#define CMOC_MAC_UNKNOWN        0
#define CMOC_MAC_COCO1          1
#define CMOC_MAC_COCO2          2
#define CMOC_MAC_COCO3          3
#define CMOC_MAC_DRAGON32       4
#define CMOC_MAC_DRAGON64       5
#define CMOC_MAC_RESERVED       6
#define CMOC_MAC_VECTREX        7

#define CMOC_FLG_EXT            8

// 3 bits for the memory size (blocks of 16K)

#define CMOC_RAM_XXK            0
#define CMOC_RAM_16K            16
#define CMOC_RAM_32K            32
#define CMOC_RAM_48K            48
#define CMOC_RAM_64K            64
#define CMOC_RAM_PAG            80

#define CMOC_FLG_DOS            128

unsigned char get_ostype(void);

// OS type collected in _main().
extern unsigned char _get_ostype;

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

#endif // _CMOC_H


