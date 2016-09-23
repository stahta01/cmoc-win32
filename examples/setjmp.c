
// A simple test of the setjmp/longjmp functions.
// The syntax is slightly non-standard due to what looks like
// a CMOC compiler issue.

#include <stdio.h>
#include <setjmp.h>

int main(void)
{
    jmp_buf jb;
    int i = 0;
    if (i = setjmp(&jb)) {
        printf("%d ", i);

    }
    longjmp(&jb, i + 1);
    return 0;
}

