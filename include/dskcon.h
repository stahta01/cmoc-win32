
#ifndef _DSKCON_H
#define _DSKCON_H

#define DCOPC_RESTORE   0
#define DCOPC_NOOP      1
#define DCOPC_READ      2
#define DCOPC_WRITE     3

typedef struct {
    unsigned char opc;                          // DSKCON OPERATION CODE 0-3
    unsigned char drv;                          // DSKCON DRIVE NUMBER 0-3
    unsigned char trk;                          // DSKCON TRACK NUMBER 0-34
    unsigned char sec;                          // DSKCON SECTOR NUMBER 1-18
    void* bpt;                                  // DSKCON DATA POINTER
    unsigned char sta;                          // DSKCON STATUS BYTE
} dskcon_t;

typedef struct {
    char name[8];
    char ext[3];
    unsigned char type, flag, granule, lastsize;
    char reserved[17];
} dskcon_dirent_t;

int dskcon(int opc, int drv, int trk, int sec, void* bpt);

#endif

