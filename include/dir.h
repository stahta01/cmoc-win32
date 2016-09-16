
// Name: dir.h
// Desc: Defines Borland style directory functions
// Auth: Derek John Evans
//
// This file is part of the WinCMOC/CMOC Compiler
//
// https://sourceforge.net/projects/cmoc-win32/
// http://perso.b2b2c.ca/~sarrazip/dev/cmoc.html
//
// This file is in the public domain


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

void setdisk(int drive);
int getdisk(void);

#endif

