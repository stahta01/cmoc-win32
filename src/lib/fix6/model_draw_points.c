
#include "_fix6.h"

void model_draw_points(model_t* model, vector_t* pv)
{
    for (byte n = model->nvectors; n--; pv++) {
        if (pv->z > 0) {
            _setpixel(pv->x, pv->y);
        }
    }
}

