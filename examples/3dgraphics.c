
#include <stdio.h>
#include <stdlib.h>
#include <fixpt.h>

#define f2i(A) ((A)>>8)
#define i2f(A) ((A)<<8)
#define fxmul(A,B) f2i((A)*(B))
#define fxdiv(A,B) (((A)<<8)/(B))

int main(void)
{
    printf("%d\n", fxsin(-20));
    return 0;
}

