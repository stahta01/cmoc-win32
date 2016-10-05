
#include "_conio.h"

int wherey(void)
{
    return _hrwidth ? coco3_wherey() : isvidram() ? (int)((_curpos >> 5) & 15) : _gettextpositiony();
}

