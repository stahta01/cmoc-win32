
#include "_stdio.h"

size_t ftell(FILE* fp)
{
    fcb_t* fcb = fcb_get(fp->dev - 1);
    return (fcb->rec << 8) + fcb->cpt - 257;
}

