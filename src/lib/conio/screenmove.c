
#include "_conio.h"

void screenmove(int dir)
{
    if (_is_coco3_mode) {
        byte* vidram = 0xc000;
        word bytesperline = _h_column << 1;
        size_t lastline = bytesperline * (_h_row - 1);
        bank_t bank = bank_set(13);
        memcpy(vidram, vidram + bytesperline, lastline);
        memset_w(vidram + lastline, _h_crsatt, bytesperline >> 1);
        bank_set(bank);
    } else if (isvidram()) {
        memmove(_VIDRAM, _VIDRAM + 32, 32 * 15);
        memset(_VIDRAM + 32 * 15, 96, 32);
    } else if (_conio.scrolltextwindow) {
        _conio.scrolltextwindow(_GSCROLLUP);
    }
}

