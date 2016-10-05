
#include <basic.h>

void BITMAPFREE(BITMAP* bitmap)
{
    if (bitmap->freememory) {
        free(bitmap->data);
    }
    free(bitmap);
}


