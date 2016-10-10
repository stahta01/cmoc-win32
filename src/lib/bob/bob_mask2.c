
#include "_bob.h"

void bob_mask2(bob_t* bob, int pen)
{
    byte* bytes = bob->bytes;
    for (int y = bob->height; y--; bytes += bob->bytesperrow) {
        for (int x = bob->width; x--;) {
            byte b = bytes[x];
            for (int i = 4; i--;) {
                b = (b & pixel2_set[i]) != pixel2_pen[pen][i] ? b & pixel2_clr[i] : b | pixel2_set[i];
            }
            bytes[x] = b;
        }
    }
}

