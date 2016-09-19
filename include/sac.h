
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

