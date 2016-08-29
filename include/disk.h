
/*  disk.h - Support for use of CoCo Disk Basic

    By Pierre Sarrazin <http://sarrazip.com/>.
    This file is in the public domain.
*/

#ifndef _DISK_H
#define _DISK_H

#include <motorola/types.h>
#include <coco/equates.h>

// DSKCON operation codes.
//
#define DSKCON_READ  2
#define DSKCON_WRITE 3

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

#endif

