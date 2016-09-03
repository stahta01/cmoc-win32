
#include "_varptr.h"

// Similar to findSimpleVariable(), but only searches the array variables.
// A null pointer is returned if the variable is not found.
// See also: getArrayNumberOfDimension(), getArrayDimensions(), getArrayElement().
//
void* findArrayVariable(char* name, byte isString)
{
    char secondNameChar = name[1] | (isString ? 0x80 : 0x00);
    char* arrayStart = * (char**) ARYTAB;
    char* arrayEnd   = * (char**) ARYEND;
    for (char* p = arrayStart; p < arrayEnd;) {
        if (p[0] == name[0] && p[1] == secondNameChar) {
            return (void*)(p + 4);          // success: point past offset word
        }
        p += * (word*)(p + 2);              // word after 2-byte name is offset to next array
    }

    return 0;                               // fail
}

