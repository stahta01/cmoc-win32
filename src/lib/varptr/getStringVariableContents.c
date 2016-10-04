
#include "_varptr.h"

// Returns the address and length of the named string variable,
// or a null pointer and zero length if the variable is not defined.
// Example:
//   char *contents;
//   byte length = getStringVariableContents("A", &contents);  // A$
//   if (contents) {  // if A$ is defined
//       putstr(contents, length);  // print A$
//       memset(contents, '*', length);  // fill A$ with asterisks
//   }
//
byte _getStringVariableContents(char* name, char** contents)
{
    byte* desc = (byte*) _findSimpleVariable(name, true);
    if (!desc) {
        *contents = 0;
        return 0;
    }
    return _getStringContents(desc, contents);
}

