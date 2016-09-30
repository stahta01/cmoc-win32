
// This is an example of using alloca() to allocate memory on the stack.
// alloca() is not fool proof. It fails if you call alloca() within
// other function calls. eg: strcpy(_alloca(10), "blabla");

// So, check you code and email me if you find an issue.

// Note, a possible non-standard feature is to store the size of the
// memory on the stack as well. This is handy for other functions which
// use _msize(). Its an extra 2 bytes per allocation, but I like the idea.

#include <conio.h>
#include <string.h>
#include <malloc.h>

void alloca_test(void)
{
    char* fmt = "STKMEM: $%X\nSTKSTR: '%s'\nSOURCE: '%s'\nMEMSIZ: %d\n";
    char* s1 = "FIRST STRING";
    char* s2 = "SECOND STRING";
    char* s3 = "THIRD STRING";
    char* m1 = (char*)_alloca(strlen(s1) + 1);
    char* m2 = (char*)_alloca(strlen(s2) + 1);
    char* m3 = (char*)_alloca(strlen(s3) + 1);
    int a, b, c, d;
    strcpy(m1, s1);
    strcpy(m2, s2);
    strcpy(m3, s3);
    char dummy[100];
    cprintf(fmt, m1, m1, s1, _msize(m1));
    cprintf(fmt, m2, m2, s2, _msize(m2));
    cprintf(fmt, m3, m3, s3, _msize(m3));
}

int main(void)
{
    clrscr();
    cputs("ALLOCA TESTS\n\n");
    alloca_test();
    cputs("\nRETURN TO BASIC");
    return 0;
}

