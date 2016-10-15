
#include "_rect.h"

rect_t* rect_init(rect_t* rect, int x1, int y1, int x2, int y2)
{
    rect->x1 = x1;
    rect->y1 = y1;
    rect->x2 = x2;
    rect->y2 = y2;
    return rect;
}

