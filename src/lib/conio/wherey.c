
#include "_conio.h"

int wherey(void)
{
    return _is_coco3_mode ? coco3_wherey() : isvidram() ? (int)((_curpos >> 5) & 15) :
           _gettextpositiony();
}

