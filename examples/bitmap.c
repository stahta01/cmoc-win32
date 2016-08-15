
#pragma target coco

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#include <basic.h>

#include <windef.h>

typedef struct {
    BOOL freememory;
    INT width, height;
    BYTE* bytes;
} BITMAP;

BITMAP* BitmapCreate(INT width, INT height, BYTE* bytes, BOOL freememory)
{
    BITMAP* bytemap = (BITMAP*) malloc(sizeof(BITMAP));
    bytemap->width = width;
    bytemap->height = height;
    bytemap->bytes = bytes;
    bytemap->freememory = freememory;
    return bytemap;
}

BITMAP* BitmapCreate2(INT width, INT height)
{
    return BitmapCreate(width, height, (BYTE*) calloc(width, height), true);;
}

VOID BitmapFree(BITMAP* bytemap)
{
    free(bytemap->bytes);
    free(bytemap);
}

VOID BitmapCopyRect(BITMAP* dstmap, INT x1, INT y1, INT x2, INT y2, BITMAP* srcmap,
                    INT u1, INT v1, INT u2, INT v2)
{
    INT w = x2 - x1, h = y2 - y1;
    if (w > 0 && h > 0) {
        INT uu = u2 - u1, vv = v2 - v1;
        HIBYTE(uu) = LOBYTE(uu);
        HIBYTE(vv) = LOBYTE(vv);
        LOBYTE(uu) = LOBYTE(vv) = 0;
        uu /= w;
        vv /= h;

        u1 = HIBYTE(u1);
        v1 = HIBYTE(v1);

        if (x1 < 0) {
            u1 += (0 - x1) * uu;
            x1 = 0;
        }
        if (y1 < 0) {
            v1 += (0 - y1) * vv;
            y1 = 0;
        }
        if (x2 > dstmap->width) {
            x2 = dstmap->width;
        }
        if (y2 > dstmap->height) {
            y2 = dstmap->height;
        }
        if ((w = x2 - x1) > 0 && (y2 - y1) > 0) {
            BYTE* dst = dstmap->bytes + y1 * dstmap->width + x1;
            BYTE* end = dst + w;
            w = dstmap->width - w;
            for (; y1 < y2; y1++, v1 += vv, dst += w, end += dstmap->width) {
                BYTE* src = &srcmap->bytes[HIBYTE(v1) * srcmap->width];
                for (INT u = u1; dst < end; u += uu) {
                    *dst++ = src[HIBYTE(u)];
                }
            }
        }
    }
}

VOID BitmapStretch(BITMAP* dstmap, INT x1, INT y1, INT x2, INT y2, BITMAP* srcmap)
{
    BitmapCopyRect(dstmap, x1, y1, x2, y2, srcmap, 0, 0, srcmap->width, srcmap->height);
}

CHAR* image =
    "                              "
    "   XXX   XX   XX  XXX   XXX   "
    "  X   X  X X X X X   X X   X  "
    "  X      X  X  X X   X X      "
    "  X   X  X     X X   X X   X  "
    "   XXX   X     X  XXX   XXX   "
    "                              ";

BITMAP* screen;
BITMAP* test;

INT main(VOID)
{
    INT i, y;

    for (CHAR* p = image; *p; p++) {
        *p = *p == ' ' ? 128 : 200;
    }

    screen = BitmapCreate(32, 16, 0x400, false);
    test = BitmapCreate(30, 7, (BYTE*)image, false);

    CLS(0);

    y = 16;

    for (;;) {
        for (i = 0; i < 25; i++) {
            BitmapStretch(screen, 16 - i, y, 16 + i, y + 10, test);
        }
        for (i = 25; i > 0; i--) {
            BitmapStretch(screen, 16 - i, y, 16 + i, y + 10, test);
        }
        y -= 1;
        if (y < -10) y = 16;
    }
    return 0;
}






















