
// This is an example of using alloca() to allocate memory on the stack.
// alloca() is not fool proof. It fails if you call alloca() within
// other function calls. eg: strcpy(_alloca(10), "blabla");

// So, check you code and email me if you find an issue.

// Note, a possible non-standard feature is to store the size of the
// memory on the stack as well. This is handy for other functions which
// use _msize(). Its an extra 2 bytes per allocation, but I like the idea.

// Note: Unlike the standard alloca(), its safe to call free() with stack
// memory. This is due to the way libheap is written. There is no fancy
// heap data structure. freeing stack memory will simply negate the size,
// making _msize() return 0.

// The downside to libheap is, alloc's are slow for lots of small blocks,
// but free's are fast. But, if you have lots of small blocks, you are
// better off using memory pooling.

#include <conio.h>
#include <string.h>
#include <malloc.h>

void alloca_test(void)
{
    char* fmt = "MEMORY: $%X MSIZE: %d\nSTKSTR: '%s'\nSOURCE: '%s'\n";
    char* s1 = "FIRST STRING";
    char* s2 = "SECOND STRING";
    char* s3 = "THIRD STRING";
    char* m1 = (char*)_alloca(strlen(s1) + 1);
    char* m2 = (char*)_alloca(strlen(s2) + 1);
    char* m3 = (char*)_alloca(strlen(s3) + 1);
    int a = 10, b = 20, c = 30, d = 40;         // dummy variables
    strcpy(m1, s1);
    strcpy(m2, s2);
    strcpy(m3, s3);
    char dummy[32];                             // dummy array
    strcpy(dummy, "CMOC STACK ALLOC");
    cprintf(fmt, m1, _msize(m1), m1, s1);
    cprintf(fmt, m2, _msize(m2), m2, s2);
    cprintf(fmt, m3, _msize(m3), m3, s3);
    cprintf("DUMMY VARS: %d %d %d %d\n", a, b, c, d);
    cprintf("DUMMY ARRAY: %s\n", dummy);
}

int main(void)
{
    clrscr();
    cputs("ALLOCA TESTS\n\n");
    alloca_test();
    cputs("\nRETURN TO BASIC");
    return 0;
}

