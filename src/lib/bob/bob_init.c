
#include "_bob.h"

void bob_init(bob_t* bob, int width, int height, void* data, int bytesperrow, bool owned)
{
    bob->bytesperrow = bytesperrow;
    bob->width = width;
    bob->height = height;
    bob->data = (byte*)data;
    bob->owned = owned;
}

