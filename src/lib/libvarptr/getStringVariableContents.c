
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
byte getStringVariableContents(char* name, char** contents)
{
    byte* desc = (byte*) findSimpleVariable(name, TRUE);
    if (!desc) {
        *contents = 0;
        return 0;
    }
    return getStringContents(desc, contents);
}
