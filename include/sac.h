
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

typedef struct node_t {
    struct node_t* prev;
    struct node_t* next;
} node_t;

typedef struct {
    node_t head, tail;
} list_t;

list_t* list_create(void);
node_t* list_head(list_t* list);
void list_init(list_t* list);
bool list_is_empty(list_t* list);
node_t* list_pull_head(list_t* list);
node_t* list_pull_tail(list_t* list);
node_t* list_push_head(list_t* list, node_t* node);
node_t* list_push_tail(list_t* list, node_t* node);
node_t* list_tail(list_t* list);
node_t* node_insert(node_t* node, node_t* prev, node_t* next);
bool node_is_head(node_t* node);
bool node_is_tail(node_t* node);
void node_link(node_t* n1, node_t* n2);
node_t* node_remove(node_t* node);

typedef struct {
    size_t count, isize;
    unsigned char* items;
} array_t;

unsigned char* array_at(array_t* array, size_t index);
array_t* array_clear(array_t* array);
array_t* array_create(size_t isize);
void array_free(array_t* array);
array_t* array_grow(array_t* array, size_t n);
void array_init(array_t* array, size_t isize);
array_t* array_resize(array_t* array, size_t n);

#endif

