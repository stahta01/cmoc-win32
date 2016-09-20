
// This is an example of Pierre's varptr functions which can be found in his
// sample program (Demo of Basic variable access from a CMOC program) here:
// http://perso.b2b2c.ca/~sarrazip/dev/cmoc.html

// I moved all the cool functions into libvarptr and the prototypes into varptr.h

// ORIGINAL SOURCE HEADER FOLLOWS
//
// varptr.c - Accessing Basic program variables from a CMOC-compiled program.
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

// Address where this program gets loaded by default.
//

// NOTE: This isn't Pierre's example, which required a basic program to run.
// This example uses the system() command to create BASIC variables.

#include <stdio.h>
#include <varptr.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void PrintUsedSpace(void)
{
    printf("PROGRAM          %d\n", _getSpaceUsedByProgram());
    printf("SIMPLE VARIABLES %d\n", _getSpaceUsedBySimpleVariables());
    printf("ARRAY VARIABLES  %d\n", _getSpaceUsedByArrayVariables());
    printf("STRING RESERVE   %d\n", _getSpaceReservedForStrings());
    puts("PRESS ANY KEY");
    getch();
}

int main(void)
{
    PrintUsedSpace();

    system("A$=\"THIS IS A BASIC STRING\"");

    char* contents;
    byte length = _getStringVariableContents("A", &contents); // A$

    if (contents) {                             // if A$ is defined
        fwrite(contents, 1, length, stdout);    // print A$
        fputc('\n', stdout);
        memset(contents, '*', length);          // fill A$ with asterisks
        system("?\"A$=\"A$");
        PrintUsedSpace();
    }

    system("A=4321");
    system("?\"A=\"A");
    _setVariableValueToWord("A", 1234, 1);
    system("?\"A=\"A");
    PrintUsedSpace();

    unsigned value;
    unsigned char sign;
    _getWordVariableValue("A", &value, &sign);
    printf("VALUE OF A=%c%d\n", sign ? '-' : '+', value);

    _setVariableValueToWord("A", 5432, 0);
    _getWordVariableValue("A", &value, &sign);
    printf("VALUE OF A=%c%d\n", sign ? '-' : '+', value);

    puts("BACK TO BASIC");

    return 0;
}

