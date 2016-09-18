
#include "_varptr.h"

//FIXME: doc
char _setVariableValueToWord(char* name, word newAbsValue, byte isNegative)
{
    byte* desc = (byte*) _findSimpleVariable(name, FALSE);
    //printf("SET(%s, %u, %u): %p\n", name, newAbsValue, isNegative, desc);
    if (!desc) {
        return -1;
    }

    if (newAbsValue == 0) {
        desc[0] = 0;
        * (word*)(desc + 1) = 0;
        * (word*)(desc + 3) = 0;
    } else {
        // Bring highest set bit of newAbsValue to bit 15.
        byte exponent = 0x80 + 8 * sizeof(word);
        while ((newAbsValue & 0x8000) == 0) {
            newAbsValue <<= 1;
            --exponent;
        }
        newAbsValue &= 0x7FFF;              // bit 15 will be the sign bit in the IEEE 754 format
        if (isNegative) {
            newAbsValue |= 0x8000;
        }

        desc[0] = exponent;
        * (word*)(desc + 1) = newAbsValue;
        * (word*)(desc + 3) = 0;
    }

    //printf("%02x %02x %02x %02x %02x\n", desc[0], desc[1], desc[2], desc[3], desc[4]);
    return 0;
}

