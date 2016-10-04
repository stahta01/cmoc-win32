
#include "_sac.h"

dlist_t* dlist_create(void)
{
    dlist_t* list = new(dlist_t);
    if (list) {
        dlist_init(list);
    }
    return list;
}

