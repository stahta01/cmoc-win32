
#include "_graph.h"

struct videoconfig* _getvideoconfig(struct videoconfig* dst)
{
    dst->mode = _pmode;
    dst->numxpixels = _horbyt << (_pmode & 1 ? 2 : 3);
    dst->numypixels = (_endgrp - _beggrp) / _horbyt;
    dst->numtextrows =  _horbyt << (fontinfo.packed ? 1 : 0);
    dst->numtextcols =  dst->numypixels >> 3;
    dst->bitsperpixel = (_pmode & 1) + 1;
    dst->numvideopages = 0;                     // todo
    dst->adapter = _UNKNOWN;                    // use or remove
    dst->monitor = dst->bitsperpixel;
    dst->memory = (_endgrp - _beggrp) / 1024;
    return dst;
}

