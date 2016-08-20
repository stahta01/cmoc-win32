
#include <string.h>
#include <basic.h>

int main(void)
{
    unsigned t = TIMER();
    for (unsigned i = 0; i < 1000; i++) {
        memset(0x400, i, 32 * 16);
    }
    printf("%d\n", TIMER() - t);

    return 0;
}


