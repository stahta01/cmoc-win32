
/*****************************************************************************/
/*                                                                           */
/*                                  time.h                                   */
/*                                                                           */
/*                               Date and time                               */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* (C) 1998-2012 Ullrich von Bassewitz                                       */
/*               Roemerstrasse 52                                            */
/*               D-70794 Filderstadt                                         */
/* EMail:        uz@cc65.org                                                 */
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

#ifndef _TIME_H
#define _TIME_H

#include <sys/null.h>
#include <sys/size.h>
#include <sys/clock.h>
#include <sys/long.h>

typedef word time_t;

// Structure for broken down time

struct tm {
    int     tm_sec;
    int     tm_min;
    int     tm_hour;
    int     tm_mday;
    int     tm_mon;
    int     tm_year;
    int     tm_wday;
    int     tm_yday;
    int     tm_isdst;
};

// Timezone representation, default is UTC

extern struct _timezone {
    char    daylight;                   // True if daylight savings time active
    long    timezone;                   // Number of seconds behind UTC
    char    tzname[5];                  // Name of timezone, e.g. CET
    char    dstname[5];                 // Name when daylight true, e.g. CEST
} _tz;

#define CLOCKS_PER_SEC 60
#define CLK_TCK 60

//  Similar to time(), but:
//   - Is not ISO C
//   - Does not take the additional pointer
//   - Does not set errno when returning -1

time_t _systime(void);

// ISO C function prototypes

char* asctime(struct tm* timep);
clock_t clock(void);
char* ctime(time_t* timep);
struct tm* gmtime(time_t* timep);
struct tm* localtime(time_t* timep);
time_t mktime(struct tm* timep);
size_t strftime(char* buf, size_t bufsize, char* format, struct tm* tm);
time_t time(time_t* t);

#endif

