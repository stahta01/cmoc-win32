
#undef NO_OLDNAMES

#include <sac.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void array_test(void)
{
    array_t* array = array_create(sizeof(int));
    if (array) {
        int i;
        for (i = 0; i < 100; i++) {
            *(int*)array_at(array_grow(array, 1), i) = i;
        }
        for (i = 0; i < array->count; i++) {
            printf("%d,", *(int*)array_at(array, i));
        }
        puts("DONE");
        array_free(array);
    }
}

typedef struct {
    node_t node;
    char* name;
} node_data_t;

int main(void)
{
    int i;
    array_test();
    return 0;
    while (!kbhit()) {
        list_t* list = list_create();
        if (list) {
            for (i = 0; i < 20; i++) {
                node_data_t* data = new(node_data_t);
                char s[20];
                sprintf(s, "NODE ADDR=$%X", data);
                data->name = strdup(s);
                list_push_head(list, &data->node);
            }
            for (node_data_t* data; data = (node_data_t*)list_pull_head(list);) {
                printf("%s\n", data->name);
                free(data->name);
                free(data);
            }
            free(list);
        }
    }
    puts("DONE");
    return 0;
}

