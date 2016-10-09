
#include "_mob.h"

void mob_free(mob_t* mob)
{
    for (int i = 0; i < 4; i++) {
        free(mob->bobs[i]);
    }
    free(mob);
}

