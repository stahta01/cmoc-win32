
// FILE CONTROL BLOCK FORMAT

#ifndef _FCB_H
#define _FCB_H

// THE FILE STRUCTURE OF COLOR TRS DOS IS CONTROLLED BY A FILE CONTROL BLOCK (FCB)
// THE FCB CONTAINS 26 CONTROL BYTES AND A SECTOR LONG (256 BYTES) DATA BUFFER.
// THE CONTROL BYTES CONTROL THE ORDERLY FLOW OF DATA FROM THE COMPUTER'S RAM TO
// THE DISKETTE AND VICE VERSA. THE OPEN COMMAND INITIALIZES THE FCB; THE INPUT,
// OUTPUT, WRITE, PRINT, GET AND PUT COMMANDS TRANSFER DATA THROUGH THE FCB AND
// THE CLOSE COMMAND TURNS OFF THE FCB.
// TABLES OF OFFSETS TO FCB CONTROL BYTES

typedef struct fcb_t {
    // COMMON
    byte typ;                                   // FILE TYPE: $40=RANDOM/DIRECT, 0=CLOSED
    byte drv;                                   // DRIVE NUMBER
    byte fgr;                                   // FIRST GRANULE IN FILE
    byte cgr;                                   // CURRENT GRANULE BEING USED
    byte sec;                                   // CURRENT SECTOR BEING USED (1-9)
    byte cpt;                                   // (INP) CHARACTER POINTER - POINTS TO NEXT CHARACTER IN FILE TO BE PROCESSED
    byte pos;                                   // CURRENT PRINT POSITION - ALWAYS ZERO IN RANDOM FILES
    word rec;                                   // CURRENT RECORD NUMBER
    // RANDOM FILE
    word rln;                                   // RANDOM FILE RECORD LENGTH
    byte* buf;                                  // POINTER TO START OF THIS FILE'S RANDOM ACCESS BUFFER
    word sof;                                   // SECTOR OFFSET TO CURRENT POSITION IN RECORD
    byte flg;                                   // GET/PUT FLAG: 0=PUT, 1=PUT
    // SEQ
    byte fcl;                                   // (SEQ) CACHE FLAG: 00=CACHE EMPTY, $FF=CACHE FULL
    byte cdt;                                   // (SEQ) CACHE DATA BYTE
    // COMMON
    byte dir;                                   // DIRECTORY ENTRY NUMBER (0-71)
    word lst;                                   // NUMBER OF BYTES IN LAST SECTOR OF FILE
    word get;                                   // 'GET' RECORD COUNTER: HOW MANY CHARACTERS HAVE BEEN PULLED OUT OF THE CURRENT RECORD
    union {
        word put;                               // (RND) 'PUT' RECORD COUNTER: POINTER TO WHERE IN THE RECORD THE NEXT BYTE WILL BE 'PUT'
        struct {
            // INPUT FILE ONLY: DATA LEFT FLAG: 0=DATA LEFT, $FF=NO DATA (EMPTY)
            byte dfl;
            // NUMBER OF CHARACTERS LEFT IN BUFFER (INPUT FILE)
            // NUMBER OF CHARS STORED IN BUFFER (OUTPUT FILE)
            byte lft;
        } seq;
    } cnt;
    byte buf[256];                              // A SECTOR LONG (256 BYTES) DATA BUFFER
} fcb_t;

int fcb_act(void);
fcb_t* fcb_get(int index);
int fcb_aval(void);

#endif

