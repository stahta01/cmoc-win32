
#ifndef _DIR_H
#define _DIR_H

#define WILDCARDS   0x01
#define EXTENSION   0x02
#define FILENAME    0x04
#define DIRECTORY   0x08
#define DRIVE       0x10

#define MAXPATH     256                         // path
#define MAXDRIVE    5                           // drive; includes colon (:)
#define MAXDIR      260                         // dir; includes leading and trailing backslashes (\)
#define MAXFILE     256                         // name
#define MAXEXT      5                           // ext; includes leading dot (.)

int fnsplit(char* path, char* drive, char* dir, char* name, char* ext);
void fnmerge(char* path, char* drive, char* dir, char* name, char* ext);

// A drive number < 0 indicates a non-disk system.

#define DRIVE_A     0
#define DRIVE_B     1
#define DRIVE_C     2
#define DRIVE_D     3

void setdisk(int drive);
int getdisk(void);
bool hasdisk(void);

#endif

