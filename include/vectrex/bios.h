
#ifndef _VECTREX_BIOS_H
#define _VECTREX_BIOS_H

#include <stdint.h>
#include <motorola/6809.h>

#include <vectrex/vectrexdefs.h>
#include <vectrex/vectrexbios.h>

// Define old asm consts from new C consts

#define Char_Table          _CHAR_TABLE
#define Char_Table_End      _CHAR_TABLE_END
#define Delay_1             _DELAY_1
#define Dot_d               _DOT_D
#define Dot_List            _DOT_LIST
#define Do_Sound            _DO_SOUND
#define DP_to_C8            _DP_TO_C8
#define DP_to_D0            _DP_TO_D0
#define Draw_Line_d         _DRAW_LINE_D
#define Draw_Pat_VL_a       _DRAW_PAT_VL_A
#define Draw_VL_a           _DRAW_VL_A
#define Init_Music_chk      _INIT_MUSIC_CHK
#define Init_OS             _INIT_OS
#define Init_OS_RAM         _INIT_OS_RAM
#define Init_VIA            _INIT_VIA
#define Intensity_a         _INTENSITY_A
#define Joy_Digital         _JOY_DIGITAL
#define Moveto_d            _MOVETO_D
#define Moveto_d_7F         _MOVETO_D_7F
#define Print_Str_d         _PRINT_STR_D
#define Random              _RANDOM
#define Read_Btns           _READ_BTNS
#define Reset0Ref           _RESET0REF
#define Rot_VL_ab           _ROT_VL_AB
#define Set_Refresh         _SET_REFRESH
#define Vec_Joy_1_X         _VEC_JOY_1_X
#define Vec_Joy_1_Y         _VEC_JOY_1_Y
#define Vec_Joy_2_X         _VEC_JOY_2_X
#define Vec_Joy_2_Y         _VEC_JOY_2_Y
#define Vec_Joy_Mux_1_X     _VEC_JOY_MUX_1_X
#define Vec_Joy_Mux_1_Y     _VEC_JOY_MUX_1_Y
#define Vec_Joy_Mux_2_X     _VEC_JOY_MUX_2_X
#define Vec_Joy_Mux_2_Y     _VEC_JOY_MUX_2_Y
#define Vec_Misc_Count      _VEC_MISC_COUNT
#define Vec_Music_Flag      _VEC_MUSIC_FLAG
#define Vec_Pattern         _VEC_PATTERN
#define Vec_Seed_Ptr        _VEC_SEED_PTR
#define Vec_Str_Ptr         _VEC_STR_PTR
#define Vec_Text_Height     _VEC_TEXT_HEIGHT
#define Vec_Text_Width      _VEC_TEXT_WIDTH
#define VIA_aux_cntl        _VIA_AUX_CNTL
#define VIA_port_a          _VIA_PORT_A
#define VIA_port_b          _VIA_PORT_B
#define VIA_shift_reg       _VIA_SHIFT_REG
#define VIA_t1_cnt_lo       _VIA_T1_CNT_LO
#define Wait_Recal          _WAIT_RECAL

// Expose Vectrex music addreses
#define vx_music_1  (char*) 0xFD0D
#define vx_music_2  (char*) 0xFD1D
#define vx_music_3  (char*) 0xFD81
#define vx_music_4  (char*) 0xFDD3
#define vx_music_5  (char*) 0xFE38
#define vx_music_6  (char*) 0xFE76
#define vx_music_7  (char*) 0xFEC6
#define vx_music_8  (char*) 0xFEF8
#define vx_music_9  (char*) 0xFF26
#define vx_music_10 (char*) 0xFF44
#define vx_music_11 (char*) 0xFF62
#define vx_music_12 (char*) 0xFF7A
#define vx_music_13 (char*) 0xFF8F

#define JOY1_BTN1 0
#define JOY1_BTN2 1
#define JOY1_BTN3 2
#define JOY1_BTN4 3

#define JOY2_BTN1 4
#define JOY2_BTN2 5
#define JOY2_BTN3 6
#define JOY2_BTN4 7

#define JOY1_BTN1_MASK (1<<JOY1_BTN1)
#define JOY1_BTN2_MASK (1<<JOY1_BTN2)
#define JOY1_BTN3_MASK (1<<JOY1_BTN3)
#define JOY1_BTN4_MASK (1<<JOY1_BTN4)

#define JOY2_BTN1_MASK (1<<JOY2_BTN1)
#define JOY2_BTN2_MASK (1<<JOY2_BTN2)
#define JOY2_BTN3_MASK (1<<JOY2_BTN3)
#define JOY2_BTN4_MASK (1<<JOY2_BTN4)

#define JOY_UP    0
#define JOY_DOWN  1
#define JOY_LEFT  2
#define JOY_RIGHT 3

#define JOY_UP_MASK    (1<<JOY_UP)
#define JOY_DOWN_MASK  (1<<JOY_DOWN)
#define JOY_LEFT_MASK  (1<<JOY_RIGHT)
#define JOY_RIGHT_MASK (1<<JOY_LEFT)

#define JOY_UP_MASK_ASM    1
#define JOY_DOWN_MASK_ASM  2
#define JOY_LEFT_MASK_ASM  4
#define JOY_RIGHT_MASK_ASM 8

// Wrappers around the vectrex BIOS calls

// Read the joystick buttons.
// uint8_t buttons = read_buttons();
// if (buttons & JOY1_BTN1_MASK) {
//   do stuff when joystick one button one is pressed
//   ...
// }
uint8_t vectrex_read_buttons();

// Read the joystick positions. This is an expensive call, as the Vectrex makes use of measring time over
// an RC network to do AD conversion for the joystick positions. For the moment, only digital positions are
// measured with this routine.
// You can use this routine as follows:
// uint8_t joystick = read_joystick(1);
// if ( joystick & JOY_UP_MASK) {
//   do joystick up stuff
//   ...
// }
uint8_t vectrex_read_joystick(uint8_t joystick);

// This call waits for timer two to timeout and restarts it, it then recalibrates the vector generators to
// coordinate (0, 0) it also calls the BIOS routine behind reset_beam in the process.
void vectrex_wait_retrace();

// Set the beam intensity. The value 0x7f is often used and is rather bright.
void vectrex_intensity(uint8_t i);

// Reset the beam to the middle of the screen.
// This is necassary from time to time as there is drift on the Vectrex integrators.
// Caling this makes coordinate (0,0) the middle of the screen.
void vectrex_reset_beam();


// Set the text width and height. Negative values are needed for the y coordinate. Otherwise text will be upside down.
void vectrex_set_text_size(int8_t height, int8_t width);

// Print a string to the screen. The string must end with 0x80
void vectrex_print_str(int8_t y, int8_t x, char* string);

// Print a C string (ends with 0).
void vectrex_print_str_c(int8_t y, int8_t x, char* string);

// Draw one dot at the relative y and x coordinate from the last beam position.
void vectrex_dot(int8_t y, int8_t x);

// Draw a list of dots to the screen. Each dot is positioned relative to the previous one.
void vectrex_dots(uint8_t nr_dots, int8_t* list);

// Set the scale. With this you can zoom in and out objects.
void vectrex_set_scale(int8_t scale);

// Move the dot to a specific position.
void vectrex_move(uint8_t y, uint8_t x);

// Draw a line.
void vectrex_line(int8_t y, int8_t x);

// Draw lines.
// The list of lines can live in ROM.
// You provide the list of lines as follows:
// int8_t list[n] = {
//    y1, x1,
//    y2, x2,
//    ...
//    xn, yn
// };
// Make note that these are not absolute, but relative coordinates.
void vectrex_lines(uint8_t nr_lines, int8_t* list);

// Draw patterned lines, where the pattern is provided as the first parameter, for the rest
// this function behaves the same as the lines fucntion.
void vectrex_pattern_lines(uint8_t pattern, uint8_t nr_lines, int8_t* list);

// Rotate a list of points. The points array can be in ROM, but the out_points need to be in RAM.
// The list of points is given as follows:
// int8_t points[n] = {
//   y1, x1,
//   y2, x2,
//   ...
//   yn, xn
// };
void vectrex_rotate(int8_t angle, uint8_t nr_points, int8_t* points, int8_t* out_points);

// Set the music flag, which should be set to 1 to start playing music using the BIOS routine.
// The music flag has 3 states: 0, 1 and 0x80.
// State 0 means no music is playing. A 1 means we are about to start the music.
// And 0x80 means the music is currently playing.
void vectrex_music_set_flag(uint8_t flag);

// Get the music flag, which can have the states documented with the get method.
// If you want to repeat the music, you should check this flag and if it is 0 set to 1 again.
uint8_t vectrex_music_get_flag();

// Point the BIOS play routine to a piece of music.
// Info about the format: http://www.playvectrex.com/designit/chrissalo/soundplaying.htm
void vectrex_music_check(unsigned char* music);

// Call this in the main loop to play the music.
void vectrex_music_play();

// The Vectrex uses three bytes for the random seed.
void vectrex_random_seed(uint8_t seed1, uint8_t seed2, uint8_t seed3);

// Produce a random value using the BIOS Random function.
int8_t vectrex_random();

// What follows here are some low level BIOS fucntions that are not really necessary to call from your
// C program, but the are here for completeness.
void vectrex_cold_start();

void vectrex_warm_start();

void vectrex_init_via();

void vectrex_init_os_ram();

void vectrex_init_os();

void vectrex_set_refresh(uint16_t value);

#endif








