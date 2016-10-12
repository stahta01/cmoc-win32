
#include "_conio.h"

void screenmove(int dir)
{
    if (_is_coco3_mode) {
        word bytesperline = _h_column << 1;
        size_t lastline = bytesperline * (_h_row - 1);
        bank_t bank = bank_set(13);
        memcpy(_H_VIDRAM, (void*)(_H_VIDRAM + bytesperline), lastline);
        memset_w((void*)(_H_VIDRAM + lastline), _h_crsatt, _h_column);
        bank_set(bank);
    } else if (isvidram()) {
        memcpy(_VIDRAM, _VIDRAM + 32, 480);
        memset_w(_VIDRAM + 480, 0x6060, 16);
    } else if (_conio.scrolltextwindow) {
        _conio.scrolltextwindow(_GSCROLLUP);
    }
}

