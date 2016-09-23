
/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

I dedicate any and all copyright interest in this software to the
public domain. I make this dedication for the benefit of the public at
large and to the detriment of my heirs and successors. I intend this
dedication to be an overt act of relinquishment in perpetuity of all
present and future rights to this software under copyright law.

Derek John Evans <https://sourceforge.net/u/buzzphp/profile/>
*/

#ifndef _FCB_H
#define _FCB_H

#ifdef __COCO__

// FILE CONTROL BLOCK FORMAT
//
// THE FILE STRUCTURE OF COLOR TRS DOS IS CONTROLLED BY A FILE CONTROL BLOCK (FCB)
// THE FCB CONTAINS 26 CONTROL BYTES AND A SECTOR LONG (256 BYTES) DATA BUFFER.
// THE CONTROL BYTES CONTROL THE ORDERLY FLOW OF DATA FROM THE COMPUTER'S RAM TO
// THE DISKETTE AND VICE VERSA. THE OPEN COMMAND INITIALIZES THE FCB; THE INPUT,
// OUTPUT, WRITE, PRINT, GET AND PUT COMMANDS TRANSFER DATA THROUGH THE FCB AND
// THE CLOSE COMMAND TURNS OFF THE FCB.
// TABLES OF OFFSETS TO FCB CONTROL BYTES

typedef struct fcb_t {
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

#endif

