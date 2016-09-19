
#include "_varptr.h"

// Returns the integer part of a numerical variable's value.
// If the variable exists, its ABSOLUTE value is stored in *value,
// its sign is stored in *isNegative (non-zero means negative), and
// 0 is returned.
// Returns -1 if the variable is not found.
// Returns -2 if the variable's value does not fit in 16 bits.
//
char _getWordVariableValue(char* name, word* absValue, byte* isNegative)
{
    byte* desc = (byte*) _findSimpleVariable(name, false);
    if (!desc) {
        return -1;
    }
    if (desc[0] == 0) {
        *absValue = 0;
        *isNegative = 0;
        return 0;
    }
    byte exponent = desc[0] & 0x7F;
    if (exponent > 16) {
        return -2;
    }

    *isNegative = desc[1] & 0x80;
    *absValue = ((* (word*)(desc + 1)) | 0x8000) >> (16 - exponent);
    return 0;
}

