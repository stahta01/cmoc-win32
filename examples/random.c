
#include <basic.h>

int main(void)
{
    byte count = 0;

    while (!INKEY()) {
        SET((byte)rand(), (byte)rand(), (byte)rand());

        if (!(count += 4)) {
        memmove(0x400, 0x401, 511);
        }
    }
    return 0;
}

