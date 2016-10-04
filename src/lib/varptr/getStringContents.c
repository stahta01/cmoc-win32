
#include "_varptr.h"

// Returns the address and the length of a string variable stored
// at the given address.
//
// CAUTION: If the string variable was initialized by a Basic READ statement,
//          then its content pointer points to a string in a DATA statement.
//          If the content is modified, the program's DATA statement is modified.
//          If the Basic is run a second time after this, it will not READ the
//          same data as the first time.
//
byte _getStringContents(void* variableStorage, char** contents)
{
    *contents = * (char**)(variableStorage + 2);
    return ((byte*) variableStorage)[0];
}

