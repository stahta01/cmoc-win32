
#include "_basic.h"

void LLINE(int x1, int y1, int x2, int y2, int c)
{
    x2 -= x1;
    y2 -= y1;
    byte x = (byte)_abs(x2), y = (byte)_abs(y2), length = _max(x, y);
    if (length) {
        x1 = (x1 << 8);
        y1 = (y1 << 8);
        x2 = (x2 << 8) / length;
        y2 = (y2 << 8) / length;
        if (c) {
            c = (c - 1) << 4;
            for (; length--; x1 += x2, y1 += y2) {
                x = (byte)(x1 >> 8);
                y = (byte)(y1 >> 8);
                byte* p = (byte*)_VIDRAM + ((word)(y & 30) << 4) + (word)((x & 63) >> 1);
                *p = _chr_set[x & 1][y & 1] | (byte)c | ((*p & 128 ? *p : 0) & 15);
            }
        } else {
            for (; length--; x1 += x2, y1 += y2) {
                x = (byte)(x1 >> 8);
                y = (byte)(y1 >> 8);
                byte* p = (byte*)_VIDRAM + ((word)(y & 30) << 4) + (word)((x & 63) >> 1);
                *p = _chr_clr[x & 1][y & 1] & (*p & 128 ? *p : 0x8f);
            }
        }
    }
}

