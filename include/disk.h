
/*  disk.h - Support for use of CoCo Disk Basic

    By Pierre Sarrazin <http:           //sarrazip.com/>.
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
    byte firstGran;                     // 0..67
    word numBytesLastSector;            // 0..256
    word length[2];                     // 32-bit word giving length of file
    byte curGran;                       // 0..67, 255 means at EOF
    byte curSec;                        // 1..9 (relative to current granule)
    word curGranLen;                    // 0..2304
    word offset[2];                     // 32-bit reading/writing offset
    word secOffset;                     // 0..256: index into curSector[] (256 means beyond sector)
    byte curSector[256];
    word curSectorAvailBytes;           // number valid bytes in curSector[] (0..256)
};

#define MAX_NUM_GRANULES 68
#define GRANULE_SIZE 2304

extern byte curDriveNo;
extern byte* fatBuffer;                 // will point to an array of MAX_NUM_GRANULES entries
extern byte fatUpToDate;                // when TRUE, fatBuffer[] does not need to be reloaded

byte _dskcon(byte operation, byte* buffer, byte drive, byte track, byte sector);
byte _readDiskSector(byte* dest, byte drive, byte track, byte sector);
byte _writeDiskSector(byte* src, byte drive, byte track, byte sector);
byte _open(struct FileDesc* fd, char* filename);
void _rewind(struct FileDesc* fd);
byte* _updateFAT();
sbyte _close(struct FileDesc* fd);
word _read(struct FileDesc* fd, char* buf, word numBytesRequested);
sbyte _seek(struct FileDesc* fd, word* newPos);
byte* _getCurrentlyAvailableBytes(struct FileDesc* fd, word* numAvailBytes);
void _advanceOffset(struct FileDesc* fd, word numBytes);
byte _getNextSector(struct FileDesc* fd);
void _granuleToTrack(byte granule, byte* track, byte* sec);
byte _isLastSectorOfFile(struct FileDesc* fd);
byte _getFileLength(struct FileDesc* fd, word* dwLengthInBytes);
byte _computeFileLength(word* dwLength, byte firstGran, word numBytesLastSector);
word _getGranuleLength(byte* fat, byte granule, word numBytesLastSector);
byte _findDirEntry(char* dirEntry, char* filename);
void _normalizeFilename(char* dest, char* src);
byte _getLastBasicDriveNo();
byte _setDefaultDriveNo(byte no);
byte _getDefautlDriveNo();

#endif

