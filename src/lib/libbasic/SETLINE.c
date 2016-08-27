
#include "_basic.h"

void SETLINE(int x1, int y1, int x2, int y2, byte c)
{
    x2 -= x1;
    y2 -= y1;
    byte x = (byte)_abs(x2), y = (byte)_abs(y2), length = _max(x, y);
    if (length) {
        x1 = _i2f(x1);
        y1 = _i2f(y1);
        x2 = _i2f(x2) / length;
        y2 = _i2f(y2) / length;
        if (c) {
            c = (c - 1) << 4;
            for (; length--; x1 += x2, y1 += y2) {
                x = (byte)_f2i(x1);
                y = (byte)_f2i(y1);
                byte* p = (byte*)_VIDRAM + ((word)(y & 30) << 4) + (word)((x & 63) >> 1);
                *p = _chr_set[x & 1][y & 1] | c | ((*p & 128 ? *p : 0) & 15);
            }
        } else {
            for (; length--; x1 += x2, y1 += y2) {
                x = (byte)_f2i(x1);
                y = (byte)_f2i(y1);
                byte* p = (byte*)_VIDRAM + ((word)(y & 30) << 4) + (word)((x & 63) >> 1);
                *p = _chr_clr[x & 1][y & 1] & (*p & 128 ? *p : 0x8f);
            }
        }
    }
}

