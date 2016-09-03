
// varptr.h - Accessing Basic program variables from a CMOC-compiled program.
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

#ifndef _VARPTR_H
#define _VARPTR_H

#include <sys/byte.h>

// Similar to findSimpleVariable(), but only searches the array variables.
// A null pointer is returned if the variable is not found.
// See also: getArrayNumberOfDimension(), getArrayDimensions(), getArrayElement().
//
void* findArrayVariable(char* name, byte isString);

// Returns the address of the 5-byte descriptor of the named variable,
// or a null pointer if the variable is not defined.
// name: C string designating the targeted variable, e.g., "A", "AB".
//       This string must be null-terminated.
// isString: Non-zero means to look for a string variable; zero means
//           a numerical variable.
// A null pointer is returned if the variable is not found.
// See also: getStringContents(), getWordVariableValue().
//
void* findSimpleVariable(char* name, byte isString);

// Returns size of each dimension of an array found by findArrayVariable().
// The number of dimensions should be obtained from getArrayNumberOfDimension().
//
void getArrayDimensions(void* arrayStorage, word dimArray[]);

// Returns the address of an element of an array found by findArrayVariable().
//
// Example: To get Basic array element A(3,5,7), do this:
//          void *a = findArrayVariable("A", FALSE);
//          if (a) {
//              word indices[] = { 3, 5, 7 };
//              void *elementStorage = getArrayElement(a, indices);
//          }
//
// Based on Color Basic routines at $B404 and $B4A0.
//
void* getArrayElement(void* arrayStorage, word indexArray[]);

// Returns the number of dimensions in an array found by findArrayVariable().
//
byte getArrayNumberOfDimension(void* arrayStorage);

word getSpaceReservedForStrings();
word getSpaceUsedByArrayVariables();
word getSpaceUsedByProgram();
word getSpaceUsedBySimpleVariables();

// Returns the address and the length of a string variable stored
// at the given address.
//
// CAUTION: If the string variable was initialized by a Basic READ statement,
//          then its content pointer points to a string in a DATA statement.
//          If the content is modified, the program's DATA statement is modified.
//          If the Basic is run a second time after this, it will not READ the
//          same data as the first time.
//
byte getStringContents(void* variableStorage, char** contents);

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
byte getStringVariableContents(char* name, char** contents);

// Returns the integer part of a numerical variable's value.
// If the variable exists, its ABSOLUTE value is stored in *value,
// its sign is stored in *isNegative (non-zero means negative), and
// 0 is returned.
// Returns -1 if the variable is not found.
// Returns -2 if the variable's value does not fit in 16 bits.
//
char getWordVariableValue(char* name, word* absValue, byte* isNegative);

//FIXME: doc
char setVariableValueToWord(char* name, word newAbsValue, byte isNegative);


#endif

