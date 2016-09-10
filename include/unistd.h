
/*****************************************************************************/
/*                                                                           */
/*                                 unistd.h                                  */
/*                                                                           */
/*                  Unix compatibility header file for cc65                  */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* (C) 2003-2011, Ullrich von Bassewitz                                      */
/*                Roemerstrasse 52                                           */
/*                D-70794 Filderstadt                                        */
/* EMail:         uz@cc65.org                                                */
/*                                                                           */
/*                                                                           */
/* This software is provided 'as-is', without any expressed or implied       */
/* warranty.  In no event will the authors be held liable for any damages    */
/* arising from the use of this software.                                    */
/*                                                                           */
/* Permission is granted to anyone to use this software for any purpose,     */
/* including commercial applications, and to alter it and redistribute it    */
/* freely, subject to the following restrictions:                            */
/*                                                                           */
/* 1. The origin of this software must not be misrepresented; you must not   */
/*    claim that you wrote the original software. If you use this software   */
/*    in a product, an acknowledgment in the product documentation would be  */
/*    appreciated but is not required.                                       */
/* 2. Altered source versions must be plainly marked as such, and must not   */
/*    be misrepresented as being the original software.                      */
/* 3. This notice may not be removed or altered from any source              */
/*    distribution.                                                          */
/*                                                                           */
/*****************************************************************************/

#ifndef _UNISTD_H
#define _UNISTD_H

#include <disk.h>

// Predefined file handles
#define STDIN_FILENO    0
#define STDOUT_FILENO   1
#define STDERR_FILENO   2

#include <sys/size.h>
#include <sys/types.h>

// Stuff for getopt
extern char* optarg;
extern int optind, opterr, optopt;

// Files
int write(int fd, void* buf, unsigned count);
int read(int fd, void* buf, unsigned count);
off_t lseek(int fd, off_t offset, int whence);
size_t ltell(int fd);
size_t lsize(int fd);
size_t lgets(int fd, char* s, size_t n);
int unlink(char* name);

// Directories
int chdir(char* name);
char* getcwd(char* buf, size_t size);
int mkdir(char* name, ...);                 // May take a mode argument
int rmdir(char* name);

// Others
unsigned sleep(unsigned seconds);
int getopt(int argc, char** argv, char* optstring);

// Non standard
int exec(char* progname, char* cmdline);

#endif

