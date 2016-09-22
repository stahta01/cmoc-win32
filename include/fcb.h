
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
    byte typ;                                   //  0 FILE TYPE: $40=RANDOM/DIRECT, 0=CLOSED
    byte drv;                                   //  1 DRIVE NUMBER
    byte fgr;                                   //  2 FIRST GRANULE IN FILE
    byte cgr;                                   //  3 CURRENT GRANULE BEING USED
    byte sec;                                   //  4 CURRENT SECTOR BEING USED (1-9)
    byte cpt;                                   //  5 (INP) CHARACTER POINTER - POINTS TO NEXT CHARACTER IN FILE TO BE PROCESSED
    byte pos;                                   //  6 CURRENT PRINT POSITION - ALWAYS ZERO IN RANDOM FILES
    byte rec;                                   //  7 CURRENT RECORD NUMBER
    // RANDOM FILE
    byte nop8;                                  //  8 UNKNOWN
    byte rln;                                   //  9 RANDOM FILE RECORD LENGTH
    byte nop10;                                 // 10 UNKNOWN
    byte buf;                                   // 11 POINTER TO START OF THIS FILE'S RANDOM ACCESS BUFFER
    byte nop12;                                 // 12 UNKNOWN
    byte sof;                                   // 13 SECTOR OFFSET TO CURRENT POSITION IN RECORD
    byte nop14;                                 // 14 UNKNOWN
    byte flg;                                   // 15 GET/PUT FLAG: 0=PUT, 1=PUT
    // SEQ
    byte fcl;                                   // 16 (SEQ) CACHE FLAG: 00=CACHE EMPTY, $FF=CACHE FULL
    byte cdt;                                   // 17 (SEQ) CACHE DATA BYTE
    // COMMON
    byte dir;                                   // 18 DIRECTORY ENTRY NUMBER (0-71)
    byte lst;                                   // 19 NUMBER OF BYTES IN LAST SECTOR OF FILE
    byte nop20;                                 // 20 UNKNOWN
    byte get;                                   // 21 'GET' RECORD COUNTER: HOW MANY CHARACTERS HAVE BEEN PULLED OUT OF THE CURRENT RECORD
    byte nop22;                                 // 22 UNKNOWN
    union {
        byte dfl;                               // 23 (SEQ) INPUT FILE ONLY: DATA LEFT FLAG: 0=DATA LEFT, $FF=NO DATA (EMPTY)
        byte put;                               // 23 (RND) 'PUT' RECORD COUNTER: POINTER TO WHERE IN THE RECORD THE NEXT BYTE WILL BE 'PUT'
    } dflput;
    byte lft;                                   // 24 (SEQ) NUMBER OF CHARACTERS LEFT IN BUFFER (INPUT FILE)
    byte con;                                   // 25 OFFSET TO START OF FCB DATA BUFFER (256 BYTES)
    byte buf[256];                              // A SECTOR LONG (256 BYTES) DATA BUFFER
} fcb_t;

int fcb_act(void);
fcb_t* fcb_get(int index);
int fcb_aval(void);

#endif

