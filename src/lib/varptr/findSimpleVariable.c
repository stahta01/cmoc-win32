
#include "_varptr.h"

// Returns the address of the 5-byte descriptor of the named variable,
// or a null pointer if the variable is not defined.
// name: C string designating the targeted variable, e.g., "A", "AB".
//       This string must be null-terminated.
// isString: Non-zero means to look for a string variable; zero means
//           a numerical variable.
// A null pointer is returned if the variable is not found.
// See also: getStringContents(), getWordVariableValue().
//
void* _findSimpleVariable(char* name, byte isString)
{
    char secondNameChar = name[1] | (isString ? 0x80 : 0x00);
    char* varStart = * (char**) VARTAB;
    char* arrayStart = * (char**) ARYTAB;
    for (char* p = varStart; p < arrayStart; p += 7)
        if (p[0] == name[0] && p[1] == secondNameChar) {
            return (void*)(p + 2);          // success
        }
    return 0;                               // fail
}

