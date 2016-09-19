
#include "_sac.h"

list_t* list_create(void)
{
    list_t* list = (list_t*)calloc(sizeof(list_t), 1);
    if (list) {
        list_init(list);
    }
    return list;
}

