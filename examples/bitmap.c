
#pragma target coco

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#include <basic.h>

#include <windef.h>

typedef struct {
    BYTE* Data;
    INT BytesPerLine, Width, Height;
    BOOL FreeMemory;
} BITMAP;

#define Create(A) ((A*)calloc(sizeof(A), 1))

BITMAP* BitmapCreate(INT Width, INT Height, BYTE* Data, INT BytesPerLine, BOOL FreeMemory)
{
    BITMAP* Bitmap = Create(BITMAP);
    Bitmap->Width = Width;
    Bitmap->Height = Height;
    Bitmap->Data = Data;
    Bitmap->BytesPerLine = BytesPerLine;
    Bitmap->FreeMemory = FreeMemory;
    return Bitmap;
}

BITMAP* BitmapCreate2(INT Width, INT Height)
{
    return BitmapCreate(Width, Height, (BYTE*) calloc(Width, Height), Width, true);
}

VOID BitmapFree(BITMAP* bitmap)
{
    assert(bitmap);
    if (bitmap->FreeMemory) {
        free(bitmap->Data);
    }
    free(bitmap);
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
        if (x2 > dstmap->Width) {
            x2 = dstmap->Width;
        }
        if (y2 > dstmap->Height) {
            y2 = dstmap->Height;
        }
        if ((w = x2 - x1) > 0 && (y2 - y1) > 0) {
            BYTE* dst = dstmap->Data + y1 * dstmap->Width + x1;
            BYTE* end = dst + w;
            w = dstmap->Width - w;
            for (; y1 < y2; y1++, v1 += vv, dst += w, end += dstmap->Width) {
                BYTE* src = &srcmap->Data[HIBYTE(v1) * srcmap->Width];
                for (INT u = u1; dst < end; u += uu) {
                    *dst++ = src[HIBYTE(u)];
                }
            }
        }
    }
}

VOID BitmapStretch(BITMAP* dstmap, INT x1, INT y1, INT x2, INT y2, BITMAP* srcmap)
{
    BitmapCopyRect(dstmap, x1, y1, x2, y2, srcmap, 0, 0, srcmap->Width, srcmap->Height);
}

VOID BitmapDraw(BITMAP* dstmap, INT x, INT y, BITMAP* srcmap)
{
    BitmapCopyRect(dstmap, x, y, srcmap->Width, srcmap->Height, srcmap, 0, 0, srcmap->Width,
                   srcmap->Height);
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

    screen = BitmapCreate(32, 16, 0x400, 32, false);
    test = BitmapCreate(30, 7, (BYTE*)image, 30, false);

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
        if (y < -10) {
            y = 16;
        }
    }
    return 0;
}

























