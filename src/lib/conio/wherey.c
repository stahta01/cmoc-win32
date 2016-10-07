
#include "_conio.h"

int wherey(void)
{
    return _is_coco3_mode ? (int)_h_cursy : isvidram() ? (int)((_curpos >> 5) & 15) :
           _gettextpositiony();
}

