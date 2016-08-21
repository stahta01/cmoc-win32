
#include <basic.h>

void BYTESCOPYRECT(byte* dst, word dstw, word dsth, byte* src, word srcw)
{
    int w = zX2 - zX1, h = zY2 - zY1;

    if (w > 0 && h > 0) {
        zUU = _i2f(zU2 - zU1) / w;
        zVV = _i2f(zV2 - zV1) / h;
        if (zX1 < 0) {
            zU1 += -zX1 * zUU;
            zX1 = 0;
        }
        if (zY1 < 0) {
            zV1 += -zY1 * zVV;
            zY1 = 0;
        }
        if (zX2 > dstw) {
            zX2 = dstw;
        }
        if (zY2 > dsth) {
            zY2 = dsth;
        }
        if ((w = zX2 - zX1) > 0 && (zY2 - zY1) > 0) {
            zDST2 = (zDST1 = dst + zY1 * dstw + zX1) + w;
            w = dstw - w;
            for (; zY1 < zY2; zY1++, zV1 += zVV, zDST1 += w, zDST2 += dstw) {
                switch (srcw) {
                case 16:
                    zSRC1 = src + _f2i(zV1) << 4;
                    break;
                case 32:
                    zSRC1 = src + _f2i(zV1) << 5;
                    break;
                default:
                    zSRC1 = src + _f2i(zV1) * srcw;
                }
                for (zU = zU1; zDST1 < zDST2; zU += zUU) {
                    *zDST1++ = zSRC1[_f2i(zU)];
                }
            }
        }
    }
}

