
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

#ifndef _HEAP_H
#define _HEAP_H

#include <sys/size.h>
#include <sys/heap.h>

// Heap blocks are 2 bytes (sizeof(int)) larger than the requested memory size.
// These two 2 bytes are the _signed_ size of the block.
// eg: If you request 10 bytes, then the heap block size is 12.
// If the size is negitive, then the block is unused. Positive means used.
// A zero value indicates the end of the heap.
// Since the smallest block size is 2, sizes of -1/1 are also invalid, and
// therefore indicate an invalid block. These are currently not checked for
// during a heap traverse. It indicates a possible buffer overflow.
// Since the size is signed, the maxium "theoretical" block size is under 32K.
// Something like 32768 - 3, but! I have set the max heap size to 0x7e00,
// incase the heap header/footer is changed. Note, the main heap
// at the end of your binary, must leave space for the stack anyway,
//
// NOTE: I now leave 512 bytes at the top of the max heap for the hardware
// interface addresses.
//
// You must take care if you split a heap block, since a split requires an
// extra two bytes for the new block size, so a block of 32 bytes, holds
// 30 bytes, you loose 2 bytes durring a split. ie: 28 bytes after a split.
// eg: split in half = 14 + 14 + 2 (size1) + 2 (size2) = a 32 byte block.
//
// The min heap size is 4, which allows no data.

#define HEAP_SIZE_MIN   4
#define HEAP_SIZE_MAX   0x7e00

heap_t* heap_init(heap_t* heap, size_t size);
size_t heap_msize(void* memory);
void* heap_malloc(heap_t* heap, size_t size);
void* heap_calloc(heap_t* heap, size_t count, size_t size);
void* heap_realloc(heap_t* heap, void* memory, size_t size);
void heap_free(void* memory);

// Heap Walkers

// These functions return the sum size of memory blocks. Therefore:
// heap_total_free + heap_total_used = heap size.
// The free value, should only be used as an indication of how much of
// the heap is unused, not how much can be allocated.

size_t heap_total_free(heap_t* heap);
size_t heap_total_used(heap_t* heap);

// The total size of the heap is not stored by the heap, because the heap can grow without
// knowing the heap start. Therefore, this function walks the heap.

size_t heap_total_size(heap_t* heap);

// A heap block is the same as a heap. I wanted heaps to be ultra simple, so, no tree's, struct's,
// or hash tables, etc. This type is here just to better document code.

typedef int heap_block_t;

// Note: The way the heaps work, you are able to split heap blocks into
// other heaps. I cant see this being required (or safe). You should always create
// your heaps at startup, and leave them be.

// Note: These functions are here mainly to document the heap structure. If you look
// at the code for these, you will see that the structure is very simple, and these
// are not required. They could even be written as macros...

size_t heap_block_size(heap_block_t* block);
heap_block_t* heap_block_next(heap_block_t* block);
bool heap_block_is_free(heap_block_t* block);
bool heap_block_is_used(heap_block_t* block);
bool heap_block_is_last(heap_block_t* block);

#endif

