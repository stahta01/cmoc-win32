
#include "_conio.h"

void gotoy(int y)
{
    if (_hrwidth) {
        coco3_gotoy(y);
    } else if (isvidram()) {
        _curpos = (_curpos & 0xfe1f) | (y << 5);
    } else {
        if (_conio.settextpositiony) {
            _conio.settextpositiony(y);
        }
    }
}

