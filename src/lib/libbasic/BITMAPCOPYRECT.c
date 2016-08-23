
#include <basic.h>

void BITMAPCOPYRECT(BITMAP* dst, int x1, int y1, int x2, int y2, BITMAP* src,
                    int u1, int v1, int u2, int v2)
{
    int w = x2 - x1, h = y2 - y1;

    if (w > 0 && h > 0) {
        int uu = _i2f(u2 - u1) / w;
        int vv = _i2f(v2 - v1) / h;
        if (x1 < 0) {
            u1 += -x1 * uu;
            x1 = 0;
        }
        if (y1 < 0) {
            v1 += -y1 * vv;
            y1 = 0;
        }
        if (x2 > dst->width) {
            x2 = dst->width;
        }
        if (y2 > dst->height) {
            y2 = dst->height;
        }
        if ((w = x2 - x1) > 0 && (y2 - y1) > 0) {
            byte* dst1 = dst->data + y1 * dst->width + x1;
            byte* dst2 = dst1 + w;
            byte* src1;
            w = dst->width - w;
            for (; y1 < y2; y1++, v1 += vv, dst1 += w, dst2 += dst->width) {
                switch (src->width) {
                case 16:
                    src1 = src->data + _f2i(v1) << 4;
                    break;
                case 32:
                    src1 = src->data + _f2i(v1) << 5;
                    break;
                default:
                    src1 = src->data + _f2i(v1) * src->width;
                }
                for (int u = u1; dst1 < dst2; u += uu) {
                    *dst1++ = src1[_f2i(u)];
                }
            }
        }
    }
}

