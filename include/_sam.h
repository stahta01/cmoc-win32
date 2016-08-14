
#ifndef __SAM_H
#define __SAM_H

// TODO Write a SAM lib

#define SET_SAM_V0(x)   (((unsigned char*)0xFFC0))[x] = TRUE)
#define SET_SAM_V1(x)   (((unsigned char*)0xFFC2))[x] = TRUE)
#define SET_SAM_V2(x)   (((unsigned char*)0xFFC4))[x] = TRUE)
#define SET_SAM_F0(x)   (((unsigned char*)0xFFC6))[x] = TRUE)
#define SET_SAM_F1(x)   (((unsigned char*)0xFFC8))[x] = TRUE)
#define SET_SAM_F2(x)   (((unsigned char*)0xFFCA))[x] = TRUE)
#define SET_SAM_F3(x)   (((unsigned char*)0xFFCC))[x] = TRUE)
#define SET_SAM_F4(x)   (((unsigned char*)0xFFCE))[x] = TRUE)
#define SET_SAM_F5(x)   (((unsigned char*)0xFFD0))[x] = TRUE)
#define SET_SAM_F6(x)   (((unsigned char*)0xFFD2))[x] = TRUE)
#define SET_SAM_P1(x)   (((unsigned char*)0xFFD4))[x] = TRUE)
#define SET_SAM_R0(x)   (((unsigned char*)0xFFD6))[x] = TRUE)
#define SET_SAM_R1(x)   (((unsigned char*)0xFFD8))[x] = TRUE)
#define SET_SAM_M0(x)   (((unsigned char*)0xFFDA))[x] = TRUE)
#define SET_SAM_M1(x)   (((unsigned char*)0xFFDC))[x] = TRUE)
#define SET_SAM_TY(x)   (((unsigned char*)0xFFDE))[x] = TRUE)

#endif

