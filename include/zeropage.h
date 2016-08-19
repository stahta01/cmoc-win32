#ifndef _ZEROPAGE_H
#define _ZEROPAGE_H

#include <equates.h>
#include <motorola/types.h>

#define zDST1   ((byte*)*(word*)0)
#define zDST2   ((byte*)*(word*)2)
#define zSRC1   ((byte*)*(word*)4)
#define zSRC2   ((byte*)*(word*)6)

#define zU      (*(int*) 8)
#define zUU     (*(int*)10)
#define zV      (*(int*)12)
#define zVV     (*(int*)14)

#define zU1     (*(int*)16)
#define zV1     (*(int*)18)
#define zU2     (*(int*)20)
#define zV2     (*(int*)22)

#define zX      (*(word*)_HORDEF)
#define zY      (*(word*)_VERDEF)

#define zX1     (*(int*)_HORBEG)
#define zY1     (*(int*)_VERBEG)
#define zX2     (*(int*)_HOREND)
#define zY2     (*(int*)_VEREND)

#endif

