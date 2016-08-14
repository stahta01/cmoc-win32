
#ifndef _COCO_H
#define _COCO_H

#include <cmoc/types.h>
#include <coco/equates.h>

#define DEV_SCREEN      ( 0)
#define DEV_CASSETTE    (-1)
#define DEV_SERIAL      (-2)
#define DEV_PRINTER     DEV_SERIAL

// DSKCON operation codes.
//
#define DSKCON_READ  2
#define DSKCON_WRITE 3

//#define ASM_ENTER()     asm("PSHS", "U,Y")
//#define ASM_LEAVE()     asm("PULS", "U,Y")

#define ROM_OPEN        [$015E]
#define ROM_INPUT       $A390
#define ROM_POLCAT      [$A000]
#define ROM_CHROUT      [$A002]
#define ROM_CSRDON      [$A004]
#define ROM_BLKIN       [$A006]
#define ROM_BLKOUT      [$A008]
#define ROM_JOYIN       [$A00A]
#define ROM_WRTLDR      [$A00C]
#define ROM_INTCNV      [$B3ED]
#define ROM_GIVABF      [$B4F4]

#define ROM_DSKCON      [$C004]
#define ROM_INKEY       $A1B1
#define ROM_CLRSCN2     $A91C
#define ROM_CLRSCN      $A928
#define ROM_DISPL       $B99C

extern byte isCoCo3;
extern byte textScreenWidth;
extern byte textScreenHeight;

void newBasicProgram();
void warmStart();
void coldStart();
void setCaseFlag(byte upperCase);
byte asm inkey();
byte waitkey(byte blinkCursor);
void sound(byte tone, byte duration);
void asm setOutputDevice(sbyte deviceNum);
void setSAMRegisters(byte* samAddr, byte value, byte numBits);
void showGraphicsAddress(byte pageNum);
void showPmode4(byte colorset);
void showLowResTextAddress();
void asm showPmode0();
void initCoCoSupport();
void setHighSpeed(byte fast);
byte resetPalette(byte isRGB);
byte palette(byte slot, byte color);
void paletteRGB(byte slot, byte red, byte green, byte blue);
byte setBorderColor(byte color);
byte width(byte columns);
byte getTextMode();
void cls(byte color);
byte attr(byte foreColor, byte backColor, byte blink, byte underline);
byte locate(byte column, byte row);
byte hscreen(byte mode);
byte hset(word x, word y, byte color);
void sleep(int seconds);

// newValue: word value.
//
#define setTimer(newValue) (* (word *) 0x112 = (newValue))

// Returns a word.
//
#define getTimer() (* (word *) 0x112)


/*  disk.h - Support for use of CoCo Disk Basic

    By Pierre Sarrazin <http://sarrazip.com/>.
    This file is in the public domain.
*/

struct FileDesc {
    byte drive;
    byte firstGran;  // 0..67
    word numBytesLastSector;  // 0..256
    word length[2];  // 32-bit word giving length of file
    byte curGran;  // 0..67, 255 means at EOF
    byte curSec;  // 1..9 (relative to current granule)
    word curGranLen;  // 0..2304
    word offset[2];  // 32-bit reading/writing offset
    word secOffset;  // 0..256: index into curSector[] (256 means beyond sector)
    byte curSector[256];
    word curSectorAvailBytes;  // number valid bytes in curSector[] (0..256)
};

#define MAX_NUM_GRANULES 68
#define GRANULE_SIZE 2304

extern byte curDriveNo;
extern byte* fatBuffer;  // will point to an array of MAX_NUM_GRANULES entries
extern byte fatUpToDate;  // when TRUE, fatBuffer[] does not need to be reloaded

byte dskcon(byte operation, byte* buffer, byte drive, byte track, byte sector);
byte readDiskSector(byte* dest, byte drive, byte track, byte sector);
byte writeDiskSector(byte* src, byte drive, byte track, byte sector);
byte open(struct FileDesc* fd, char* filename);
void _rewind(struct FileDesc* fd);
byte* updateFAT();
sbyte close(struct FileDesc* fd);
word read(struct FileDesc* fd, char* buf, word numBytesRequested);
sbyte dwcompare(word* a, word* b);
sbyte seek(struct FileDesc* fd, word* newPos);
byte* getCurrentlyAvailableBytes(struct FileDesc* fd, word* numAvailBytes);
void advanceOffset(struct FileDesc* fd, word numBytes);
byte getNextSector(struct FileDesc* fd);
void granuleToTrack(byte granule, byte* track, byte* sec);
byte isLastSectorOfFile(struct FileDesc* fd);
byte getFileLength(struct FileDesc* fd, word* dwLengthInBytes);
byte computeFileLength(word* dwLength, byte firstGran, word numBytesLastSector);
word getGranuleLength(byte* fat, byte granule, word numBytesLastSector);
byte findDirEntry(char* dirEntry, char* filename);
void normalizeFilename(char* dest, char* src);
byte getLastBasicDriveNo();
byte setDefaultDriveNo(byte no);
byte getDefautlDriveNo();

#endif // _COCO_H





