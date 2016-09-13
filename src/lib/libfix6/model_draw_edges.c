
#include "_fix6.h"

void model_draw_edges(model_t* model, vector_t* pv)
{
    _allcol = -1;
    edge_t* edges = model->edges;
    for (unsigned char n = model->nedges; n > 0; n--, edges++) {
        if (pv[edges->a].z > 0 && pv[edges->b].z > 0) {
            _horbeg = pv[edges->a].x;
            _verbeg = pv[edges->a].y;
            _horend = pv[edges->b].x;
            _verend = pv[edges->b].y;
            system_line();
        }
    }
}

