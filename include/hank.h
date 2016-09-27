
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

#ifndef _HANK_H
#define _HANK_H

#include <heap.h>
#include <bank.h>

typedef struct {
    heap_t* heap;
    bank_t bank;
} hank_t;

hank_t* hank_create_clear(bank_t bank, heap_t* heap, size_t size);
hank_t* hank_malloc(void** data, size_t size);

// Low level hank functions. These should only be used if you have read the
// hank library code. I split these off in the even that you want to add
// pre-existing heaps. eg: You may have a number of heaps in 32K ram,
// which you want to include in your far allocations. This would allow
// a system to use existing ram, before using banked ram, but it might also
// take ram away from the default malloc/free functions. So, you need
// to understand how to manage heaps within heaps.

hank_t* hank_init(hank_t* hank, bank_t bank, heap_t* heap);
hank_t* hank_clear(hank_t* hank, size_t size);
hank_t* hank_create(bank_t bank, heap_t* heap);

#endif

