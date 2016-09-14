
#include <dskcon.h>

int dskcon(int opc, int drv, int trk, int sec, void* bpt)
{
    dskcon_t* dskcon = (dskcon_t*)(*(unsigned*)0xc006);
    dskcon->opc = (char)opc;
    dskcon->drv = (char)drv;
    dskcon->trk = (char)trk;
    dskcon->sec = (char)sec;
    dskcon->bpt = bpt;
    asm {
        pshs    u
        jsr     [$c004]
        puls    u
    }
    return dskcon->sta;
}

