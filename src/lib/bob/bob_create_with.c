
#include "_bob.h"

bob_t* bob_create_with(int width, int height, byte* data, int bytesperline, bool freememory)
{
    bob_t* bob = new(bob_t);
    bob->width = width;
    bob->height = height;
    bob->data = data;
    bob->bytesperline = bytesperline;
    bob->freememory = freememory;
    return bob;
}

