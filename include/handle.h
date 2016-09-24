
#ifndef _HANDLE_H
#define _HANDLE_H

typedef void* handle_t;

extern handle_t handle_vidram;
extern handle_t handle_polcat;
extern handle_t handle_chrout;
extern handle_t handle_csrdon;
extern handle_t handle_blkin;
extern handle_t handle_blkout;
extern handle_t handle_joyin;
extern handle_t handle_wrtldr;
extern handle_t handle_line;
extern handle_t handle_getchr;
extern handle_t handle_putchr;
extern handle_t handle_sound;
extern handle_t handle_crunch;
extern handle_t handle_execute;
extern handle_t handle_screen;

void handle_init_common(void);
void handle_init_coco(void);
void handle_init_dragon(void);

#endif

