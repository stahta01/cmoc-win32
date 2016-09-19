

#include <sac.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    node_t node;
    int value;
} data_t;

int main(void)
{
    int i;
    list_t* list = list_create();
    if (list) {
        for (i = 0; i < 10; i++) {
            data_t* data = new(data_t);
            data->value = i;
            list_push_head(list, &data->node);
        }
        for (data_t* data; data = (data_t*)list_pull_head(list);) {
            printf("%d\n", data->value);
            delete(data);
        }
        delete(list);
    }

    puts("DONE");
    return 0;
}

