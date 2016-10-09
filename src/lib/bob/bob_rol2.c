
#include "_bob.h"

void bob_rol2(bob_t* bob)
{
    byte* bytes = bob->bytes;
    int bytesperrow = bob->bytesperrow, width = bob->width;
    for (int i = bob->height; i--; bytes += bytesperrow) {
        memrol2(bytes, *bytes, width);
    }
}

