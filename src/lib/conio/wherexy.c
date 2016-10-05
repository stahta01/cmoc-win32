
#include "_conio.h"

void wherexy(point_t* point)
{
    if (_is_coco3_mode) {
        coco3_wherexy(point);
    } else if (isvidram()) {
        point->x = _curpos & 31;
        point->y = (_curpos >> 5) & 15;
    } else {
        _gettextposition(point);
    }
}

