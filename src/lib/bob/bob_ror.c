
#include "_bob.h"

void bob_ror(bob_t* bob)
{
    byte* bytes = bob->bytes;
    int bytesperrow = bob->bytesperrow, width = bob->width;
    for (int i = bob->height; i--; bytes += bytesperrow) {
        memror(bytes, bytes[width - 1], width);
    }
}

