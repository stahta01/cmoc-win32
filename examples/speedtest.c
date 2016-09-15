
#include <string.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    clock_t t = clock();
    for (unsigned i = 0; i < 1000; i++) {
        memset(0x400, i, 32 * 16);
    }
    printf("%d\n", clock() - t);

    return 0;
}

