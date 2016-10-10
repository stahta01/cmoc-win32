
/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

I dedicate any and all copyright interest in this software to the
public domain. I make this dedication for the benefit of the public at
large and to the detriment of my heirs and successors. I intend this
dedication to be an overt act of relinquishment in perpetuity of all
present and future rights to this software under copyright law.

Derek John Evans <https://sourceforge.net/u/buzzphp/profile/>
*/

#ifndef _BOB_H
#define _BOB_H

typedef struct {
    word width, height, bytesperrow;
    byte* bytes;
    bool owned;
} bob_t;

void bob_init(bob_t* bob, int width, int height, int bytesperrow, void* bytes, bool owned);
bob_t* bob_create_adapter(int width, int height, int bytesperrow, void* bytes);
bob_t* bob_create(int width, int height);

void bob_free(bob_t* bob);

void bob_rol1(bob_t* bob);
void bob_ror1(bob_t* bob);
void bob_rol2(bob_t* bob);
void bob_ror2(bob_t* bob);

bob_t* bob_copyrect(
    bob_t* dst, int x1, int y1, int x2, int y2,
    bob_t* src, int u1, int v1, int u2, int v2);

bob_t* bob_stretch(bob_t* dst, int x1, int y1, int x2, int y2, bob_t* src);
bob_t* bob_drawrect(bob_t* dst, int x, int y, bob_t* src, int u1, int v1, int u2, int v2);
bob_t* bob_draw(bob_t* dst, int x, int y, bob_t* src);

void bob_mask2(bob_t* bob, int pen);

void bob_memcpy_unpack(bob_t* dst, int x, int y, bob_t* src);

void bob_init_beggrp(bob_t* bob);

#endif

