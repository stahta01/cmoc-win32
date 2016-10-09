
#include "_bob.h"

bob_t* bob_copyrect(
    bob_t* dst, int x1, int y1, int x2, int y2,
    bob_t* src, int u1, int v1, int u2, int v2)
{
    int w = x2 - x1, h = y2 - y1;
    if (w > 0 && h > 0) {
        int uu = _ishl6(u2 - u1) / w, vv = _ishl6(v2 - v1) / h;
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
            word dstbpr = dst->bytesperrow, srcbpr = src->bytesperrow;
            byte* dst1 = dst->bytes + (y1 * dstbpr) + x1, *dst2 = dst1 + w;
            for (w = dstbpr - w; y1 < y2; y1++, v1 += vv, dst1 += w, dst2 += dstbpr) {
                byte* src1;
                switch (srcbpr) {
                case 16:
                    src1 = src->bytes + (_ishr6(v1) << 4);
                    break;
                case 32:
                    src1 = src->bytes + (_ishr6(v1) << 5);
                    break;
                default:
                    src1 = src->bytes + (_ishr6(v1) * srcbpr);
                }
                for (int u = u1; dst1 < dst2; u += uu) {
                    *dst1++ = src1[_ishr6(u)];
                }
            }
        }
    }
    return dst;
}

