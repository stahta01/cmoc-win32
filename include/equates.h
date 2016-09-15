
#ifndef _EQUATES_H
#define _EQUATES_H

#if defined(__COCO__)

#include <coco/equates.h>
#include <coco/disk.h>

#else

#if defined(__DRAGON__)

#include <dragon/equates.h>

#else

#error unknown target

#endif
#endif

#endif


