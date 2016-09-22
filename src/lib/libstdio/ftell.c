
#include "_stdio.h"

// TODO: Currently disk only. Can we support cas reading?
// Not tested on seq writes.

size_t ftell(FILE* fp)
{
    fcb_t* fcb = fcb_get(fp->dev - 1);
    if (fcb) {
        return ((fcb->rec - 1) << 8) + (fcb->cnt.seq.dfl ? fcb->lst - fcb->cnt.seq.lft : (word)fcb->cpt);
    }
    return EOF;
}

