
#include "_bob.h"

void bob_init(bob_t* bob, int width, int height, int bytesperrow, void* bytes, bool owned)
{
    bob->width = width;
    bob->height = height;
    bob->bytesperrow = bytesperrow;
    bob->bytes = (byte*)bytes;
    bob->owned = owned;
}

