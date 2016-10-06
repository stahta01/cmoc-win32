
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

#ifndef _SAC_H
#define _SAC_H

#include <sys/size.h>

typedef struct snode_t {
    struct snode_t* next;
} snode_t;

typedef struct dnode_t {
    struct dnode_t* prev;
    struct dnode_t* next;
} dnode_t;

void dnode_link(dnode_t* n1, dnode_t* n2);
bool dnode_is_head(dnode_t* node);
bool dnode_is_tail(dnode_t* node);

dnode_t* dnode_insert(dnode_t* node, dnode_t* prev, dnode_t* next);
dnode_t* dnode_remove(dnode_t* node);

typedef struct {
    dnode_t head, tail;
} dlist_t;

void dlist_init(dlist_t* list);
bool dlist_is_empty(dlist_t* list);

dlist_t* dlist_create(void);
dnode_t* dlist_head(dlist_t* list);
dnode_t* dlist_pull_head(dlist_t* list);
dnode_t* dlist_pull_tail(dlist_t* list);
dnode_t* dlist_push_head(dlist_t* list, dnode_t* node);
dnode_t* dlist_push_tail(dlist_t* list, dnode_t* node);
dnode_t* dlist_tail(dlist_t* list);

typedef struct {
    size_t count, isize;
    byte* items;
} array_t;

void array_init(array_t* array, size_t isize);
void array_free(array_t* array);

array_t* array_clear(array_t* array);
array_t* array_create(size_t isize);
array_t* array_grow(array_t* array, size_t n);
array_t* array_resize(array_t* array, size_t n);

byte* array_at(array_t* array, size_t index);

#ifndef NO_OLDNAMES

#define node_t          dnode_t
#define list_t          dlist_t
#define list_create     dlist_create
#define list_head       dlist_head
#define list_tail       dlist_tail
#define list_push_head  dlist_push_head
#define list_pull_head  dlist_pull_head

#endif

#endif

