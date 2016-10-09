
#include "_mob.h"

mob_t* mob_create(bob_t* src)
{
    mob_t* mob = new(mob_t);
    if (mob) {
        for (int i = 0; i < 4; i++) {
            mob->bobs[i] = bob_create(src->width, src->height);
            if (mob->bobs[i]) {
                bob_draw(mob->bobs[i], 0, 0, src);
                for (int j = i; j-- > 0;) {
                    bob_ror2(mob->bobs[i]);
                }
            } else {
                mob_free(mob);
                return nullptr;
            }
        }
    }
    return mob;
}

