
#include <sac.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void darray_test(void)
{
    darray_t* array = darray_create(sizeof(int));
    if (array) {
        int i;
        for (i = 0; i < 30; i++) {
            *(int*)darray_at(darray_grow(array, 1), i) = i;
        }
        for (i = 0; i < array->size; i++) {
            printf("%d,", *(int*)darray_at(array, i));
        }
        darray_free(array);
        cputc('\n');
    }
}

typedef struct {
    snode_t node;
    char* name;
} snode_data_t;

void slist_test(void)
{
    slist_t* slist = new(slist_t);
    if (slist) {
        char str[20];
        for (int i = 0; i < 5; i++) {
            snode_data_t* data = new(snode_data_t);
            sprintf(str, "[NAME#%d]", i);
            data->name = strdup(str);
            slist_push_head(slist, &data->node);
        }
        for (snode_data_t* data; data = (snode_data_t*)slist_pull_head(slist);) {
            cputs(data->name);
            free(data->name);
            free(data);
        }
        free(slist);
        cputc('\n');
    }
}

typedef struct {
    dnode_t node;
    char* name;
} dnode_data_t;

void dlist_test(void)
{
    int i;
    dlist_t* list = dlist_create();
    if (list) {
        for (i = 0; i < 10; i++) {
            dnode_data_t* data = new(dnode_data_t);
            char s[20];
            sprintf(s, "[$%X]", data);
            data->name = strdup(s);
            dlist_push_head(list, &data->node);
        }
        for (dnode_data_t* data; data = (dnode_data_t*)dlist_pull_head(list);) {
            printf("%s", data->name);
            free(data->name);
            free(data);
        }
        free(list);
        cputc('\n');
    }
}

int main(void)
{
    clrscr();
    cputs("SOME SAC EXAMPLES\n\n");
    slist_test();
    darray_test();
    dlist_test();
    cputs("\nBACK TO BASIC\n");
    return 0;
}

