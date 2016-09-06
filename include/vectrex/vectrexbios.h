
// This file was created by WinCMOC (CMOC 6809 C Compiler for Windows)
//
// WinCMOC:  https://sourceforge.net/projects/cmoc-win32/
// CMOC:     http://perso.b2b2c.ca/~sarrazip/dev/cmoc.html

// Translated from "vectrexbios.asm"
//
// This file is in the public domain

#ifndef _VECTREX_VECTREXBIOS_H
#define _VECTREX_VECTREXBIOS_H

// Decimal 51200 (0xC800) [Value] - Shadow of sound chip registers (15 bytes)
#ifndef _VEC_SND_SHADOW
#define _VEC_SND_SHADOW 51200
#endif

// Decimal 51215 (0xC80F) [Value] - Current state of all joystick buttons
#ifndef _VEC_BTN_STATE
#define _VEC_BTN_STATE 51215
#endif

// Decimal 51216 (0xC810) [Value] - Previous state of all joystick buttons
#ifndef _VEC_PREV_BTNS
#define _VEC_PREV_BTNS 51216
#endif

// Decimal 51217 (0xC811) [Value] - Current toggle state of all buttons
#ifndef _VEC_BUTTONS
#define _VEC_BUTTONS 51217
#endif

// Decimal 51218 (0xC812) [Value] - Current toggle state of stick 1 button 1
#ifndef _VEC_BUTTON_1_1
#define _VEC_BUTTON_1_1 51218
#endif

// Decimal 51219 (0xC813) [Value] - Current toggle state of stick 1 button 2
#ifndef _VEC_BUTTON_1_2
#define _VEC_BUTTON_1_2 51219
#endif

// Decimal 51220 (0xC814) [Value] - Current toggle state of stick 1 button 3
#ifndef _VEC_BUTTON_1_3
#define _VEC_BUTTON_1_3 51220
#endif

// Decimal 51221 (0xC815) [Value] - Current toggle state of stick 1 button 4
#ifndef _VEC_BUTTON_1_4
#define _VEC_BUTTON_1_4 51221
#endif

// Decimal 51222 (0xC816) [Value] - Current toggle state of stick 2 button 1
#ifndef _VEC_BUTTON_2_1
#define _VEC_BUTTON_2_1 51222
#endif

// Decimal 51223 (0xC817) [Value] - Current toggle state of stick 2 button 2
#ifndef _VEC_BUTTON_2_2
#define _VEC_BUTTON_2_2 51223
#endif

// Decimal 51224 (0xC818) [Value] - Current toggle state of stick 2 button 3
#ifndef _VEC_BUTTON_2_3
#define _VEC_BUTTON_2_3 51224
#endif

// Decimal 51225 (0xC819) [Value] - Current toggle state of stick 2 button 4
#ifndef _VEC_BUTTON_2_4
#define _VEC_BUTTON_2_4 51225
#endif

// Decimal 51226 (0xC81A) [Value] - Joystick A/D resolution (0x80=min 0x00=max)
#ifndef _VEC_JOY_RESLTN
#define _VEC_JOY_RESLTN 51226
#endif

// Decimal 51227 (0xC81B) [Value] - Joystick 1 left/right
#ifndef _VEC_JOY_1_X
#define _VEC_JOY_1_X 51227
#endif

// Decimal 51228 (0xC81C) [Value] - Joystick 1 up/down
#ifndef _VEC_JOY_1_Y
#define _VEC_JOY_1_Y 51228
#endif

// Decimal 51229 (0xC81D) [Value] - Joystick 2 left/right
#ifndef _VEC_JOY_2_X
#define _VEC_JOY_2_X 51229
#endif

// Decimal 51230 (0xC81E) [Value] - Joystick 2 up/down
#ifndef _VEC_JOY_2_Y
#define _VEC_JOY_2_Y 51230
#endif

// Decimal 51231 (0xC81F) [Value] - Joystick enable/mux flags (4 bytes)
#ifndef _VEC_JOY_MUX
#define _VEC_JOY_MUX 51231
#endif

// Decimal 51231 (0xC81F) [Value] - Joystick 1 X enable/mux flag (=1)
#ifndef _VEC_JOY_MUX_1_X
#define _VEC_JOY_MUX_1_X 51231
#endif

// Decimal 51232 (0xC820) [Value] - Joystick 1 Y enable/mux flag (=3)
#ifndef _VEC_JOY_MUX_1_Y
#define _VEC_JOY_MUX_1_Y 51232
#endif

// Decimal 51233 (0xC821) [Value] - Joystick 2 X enable/mux flag (=5)
#ifndef _VEC_JOY_MUX_2_X
#define _VEC_JOY_MUX_2_X 51233
#endif

// Decimal 51234 (0xC822) [Value] - Joystick 2 Y enable/mux flag (=7)
#ifndef _VEC_JOY_MUX_2_Y
#define _VEC_JOY_MUX_2_Y 51234
#endif

// Decimal 51235 (0xC823) [Value] - Misc counter/flag byte, zero when not in use
#ifndef _VEC_MISC_COUNT
#define _VEC_MISC_COUNT 51235
#endif

// Decimal 51236 (0xC824) [Value] - Check0Ref enable flag
#ifndef _VEC_0REF_ENABLE
#define _VEC_0REF_ENABLE 51236
#endif

// Decimal 51237 (0xC825) [Value] - Loop counter word (incremented in Wait_Recal)
#ifndef _VEC_LOOP_COUNT
#define _VEC_LOOP_COUNT 51237
#endif

// Decimal 51239 (0xC827) [Value] - Default brightness
#ifndef _VEC_BRIGHTNESS
#define _VEC_BRIGHTNESS 51239
#endif

// Decimal 51240 (0xC828) [Value] - Dot dwell time?
#ifndef _VEC_DOT_DWELL
#define _VEC_DOT_DWELL 51240
#endif

// Decimal 51241 (0xC829) [Value] - Dot pattern (bits)
#ifndef _VEC_PATTERN
#define _VEC_PATTERN 51241
#endif

// Decimal 51242 (0xC82A) [Value] - Default text height and width
#ifndef _VEC_TEXT_HW
#define _VEC_TEXT_HW 51242
#endif

// Decimal 51242 (0xC82A) [Value] - Default text height
#ifndef _VEC_TEXT_HEIGHT
#define _VEC_TEXT_HEIGHT 51242
#endif

// Decimal 51243 (0xC82B) [Value] - Default text width
#ifndef _VEC_TEXT_WIDTH
#define _VEC_TEXT_WIDTH 51243
#endif

// Decimal 51244 (0xC82C) [Value] - Temporary string pointer for Print_Str
#ifndef _VEC_STR_PTR
#define _VEC_STR_PTR 51244
#endif

// Decimal 51246 (0xC82E) [Value] - Six bytes of counters
#ifndef _VEC_COUNTERS
#define _VEC_COUNTERS 51246
#endif

// Decimal 51246 (0xC82E) [Value] - First counter byte
#ifndef _VEC_COUNTER_1
#define _VEC_COUNTER_1 51246
#endif

// Decimal 51247 (0xC82F) [Value] - Second counter byte
#ifndef _VEC_COUNTER_2
#define _VEC_COUNTER_2 51247
#endif

// Decimal 51248 (0xC830) [Value] - Third counter byte
#ifndef _VEC_COUNTER_3
#define _VEC_COUNTER_3 51248
#endif

// Decimal 51249 (0xC831) [Value] - Fourth counter byte
#ifndef _VEC_COUNTER_4
#define _VEC_COUNTER_4 51249
#endif

// Decimal 51250 (0xC832) [Value] - Fifth counter byte
#ifndef _VEC_COUNTER_5
#define _VEC_COUNTER_5 51250
#endif

// Decimal 51251 (0xC833) [Value] - Sixth counter byte
#ifndef _VEC_COUNTER_6
#define _VEC_COUNTER_6 51251
#endif

// Decimal 51252 (0xC834) [Value] - Temp storage word for rise/run
#ifndef _VEC_RISERUN_TMP
#define _VEC_RISERUN_TMP 51252
#endif

// Decimal 51254 (0xC836) [Value] - Angle for rise/run and rotation calculations
#ifndef _VEC_ANGLE
#define _VEC_ANGLE 51254
#endif

// Decimal 51255 (0xC837) [Value] - Index pair for run
#ifndef _VEC_RUN_INDEX
#define _VEC_RUN_INDEX 51255
#endif

// Decimal 51257 (0xC839) [Value] - Index pair for rise
#ifndef _VEC_RISE_INDEX
#define _VEC_RISE_INDEX 51257
#endif

// Decimal 51259 (0xC83B) [Value] - length for rise/run
#ifndef _VEC_RISERUN_LEN
#define _VEC_RISERUN_LEN 51259
#endif

// Decimal 51261 (0xC83D) [Value] - Refresh time (divided by 1.5MHz)
#ifndef _VEC_RFRSH
#define _VEC_RFRSH 51261
#endif

// Decimal 51261 (0xC83D) [Value] - Refresh time low byte
#ifndef _VEC_RFRSH_LO
#define _VEC_RFRSH_LO 51261
#endif

// Decimal 51262 (0xC83E) [Value] - Refresh time high byte
#ifndef _VEC_RFRSH_HI
#define _VEC_RFRSH_HI 51262
#endif

// Decimal 51263 (0xC83F) [Value] - Music work buffer (14 bytes, backwards?)
#ifndef _VEC_MUSIC_WORK
#define _VEC_MUSIC_WORK 51263
#endif

// Decimal 51266 (0xC842) [Value] - register 10
#ifndef _VEC_MUSIC_WK_A
#define _VEC_MUSIC_WK_A 51266
#endif

// Decimal 51269 (0xC845) [Value] - register 7
#ifndef _VEC_MUSIC_WK_7
#define _VEC_MUSIC_WK_7 51269
#endif

// Decimal 51270 (0xC846) [Value] - register 6
#ifndef _VEC_MUSIC_WK_6
#define _VEC_MUSIC_WK_6 51270
#endif

// Decimal 51271 (0xC847) [Value] - register 5
#ifndef _VEC_MUSIC_WK_5
#define _VEC_MUSIC_WK_5 51271
#endif

// Decimal 51275 (0xC84B) [Value] - register 1
#ifndef _VEC_MUSIC_WK_1
#define _VEC_MUSIC_WK_1 51275
#endif

// Decimal 51277 (0xC84D) [Value] - Pointer to note-to-fr.EQUency table (normally 0xFC8D)
#ifndef _VEC_FREQ_TABLE
#define _VEC_FREQ_TABLE 51277
#endif

// Decimal 51279 (0xC84F) [Value] - Maximum number of players for Select_Game
#ifndef _VEC_MAX_PLAYERS
#define _VEC_MAX_PLAYERS 51279
#endif

// Decimal 51280 (0xC850) [Value] - Maximum number of games for Select_Game
#ifndef _VEC_MAX_GAMES
#define _VEC_MAX_GAMES 51280
#endif

// Decimal 51279 (0xC84F) [Value] - Storage for first music header word (ADSR table)
#ifndef _VEC_ADSR_TABLE
#define _VEC_ADSR_TABLE 51279
#endif

// Decimal 51281 (0xC851) [Value] - Storage for second music header word ('twang' table)
#ifndef _VEC_TWANG_TABLE
#define _VEC_TWANG_TABLE 51281
#endif

// Decimal 51283 (0xC853) [Value] - Music data pointer
#ifndef _VEC_MUSIC_PTR
#define _VEC_MUSIC_PTR 51283
#endif

// Decimal 51283 (0xC853) [Value] - Used by Explosion_Snd - bit for first channel used?
#ifndef _VEC_EXPL_CHANA
#define _VEC_EXPL_CHANA 51283
#endif

// Decimal 51284 (0xC854) [Value] - Used by Explosion_Snd - bits for all channels used?
#ifndef _VEC_EXPL_CHANS
#define _VEC_EXPL_CHANS 51284
#endif

// Decimal 51285 (0xC855) [Value] - Current sound channel number for Init_Music
#ifndef _VEC_MUSIC_CHAN
#define _VEC_MUSIC_CHAN 51285
#endif

// Decimal 51286 (0xC856) [Value] - Music active flag (0x00=off 0x01=start 0x80=on)
#ifndef _VEC_MUSIC_FLAG
#define _VEC_MUSIC_FLAG 51286
#endif

// Decimal 51287 (0xC857) [Value] - Duration counter for Init_Music
#ifndef _VEC_DURATION
#define _VEC_DURATION 51287
#endif

// Decimal 51288 (0xC858) [Value] - 3 word 'twang' table used by Init_Music
#ifndef _VEC_MUSIC_TWANG
#define _VEC_MUSIC_TWANG 51288
#endif

// Decimal 51288 (0xC858) [Value] - Four bytes copied from Explosion_Snds U-reg parameters
#ifndef _VEC_EXPL_1
#define _VEC_EXPL_1 51288
#endif

// Decimal 51289 (0xC859) [Value]
#ifndef _VEC_EXPL_2
#define _VEC_EXPL_2 51289
#endif

// Decimal 51290 (0xC85A) [Value]
#ifndef _VEC_EXPL_3
#define _VEC_EXPL_3 51290
#endif

// Decimal 51291 (0xC85B) [Value]
#ifndef _VEC_EXPL_4
#define _VEC_EXPL_4 51291
#endif

// Decimal 51292 (0xC85C) [Value] - Used by Explosion_Snd - channel number in use?
#ifndef _VEC_EXPL_CHAN
#define _VEC_EXPL_CHAN 51292
#endif

// Decimal 51293 (0xC85D) [Value] - Used by Explosion_Snd - bit for second channel used?
#ifndef _VEC_EXPL_CHANB
#define _VEC_EXPL_CHANB 51293
#endif

// Decimal 51294 (0xC85E) [Value] - ADSR timers for each sound channel (3 bytes)
#ifndef _VEC_ADSR_TIMERS
#define _VEC_ADSR_TIMERS 51294
#endif

// Decimal 51297 (0xC861) [Value] - Storage for base fr.EQUency of each channel (3 words)
#ifndef _VEC_MUSIC_FREQ
#define _VEC_MUSIC_FREQ 51297
#endif

// Decimal 51303 (0xC867) [Value] - Explosion_Snd initialization flag?
#ifndef _VEC_EXPL_FLAG
#define _VEC_EXPL_FLAG 51303
#endif

// Decimal 51319 (0xC877) [Value] - Used by Explosion_Snd
#ifndef _VEC_EXPL_TIMER
#define _VEC_EXPL_TIMER 51319
#endif

// Decimal 51321 (0xC879) [Value] - Number of players selected in Select_Game
#ifndef _VEC_NUM_PLAYERS
#define _VEC_NUM_PLAYERS 51321
#endif

// Decimal 51322 (0xC87A) [Value] - Game number selected in Select_Game
#ifndef _VEC_NUM_GAME
#define _VEC_NUM_GAME 51322
#endif

// Decimal 51323 (0xC87B) [Value] - Pointer to 3-byte random number seed (=0xC87D)
#ifndef _VEC_SEED_PTR
#define _VEC_SEED_PTR 51323
#endif

// Decimal 51325 (0xC87D) [Value] - Default 3-byte random number seed
#ifndef _VEC_RANDOM_SEED
#define _VEC_RANDOM_SEED 51325
#endif

// Decimal 52202 (0xCBEA) [Value] - Default top-of-stack
#ifndef _VEC_DEFAULT_STK
#define _VEC_DEFAULT_STK 52202
#endif

// Decimal 52203 (0xCBEB) [Value] - High score storage (7 bytes)
#ifndef _VEC_HIGH_SCORE
#define _VEC_HIGH_SCORE 52203
#endif

// Decimal 52210 (0xCBF2) [Value] - SWI2/SWI3 interrupt vector (3 bytes)
#ifndef _VEC_SWI3_VECTOR
#define _VEC_SWI3_VECTOR 52210
#endif

// Decimal 52210 (0xCBF2) [Value] - SWI2/SWI3 interrupt vector (3 bytes)
#ifndef _VEC_SWI2_VECTOR
#define _VEC_SWI2_VECTOR 52210
#endif

// Decimal 52213 (0xCBF5) [Value] - FIRQ interrupt vector (3 bytes)
#ifndef _VEC_FIRQ_VECTOR
#define _VEC_FIRQ_VECTOR 52213
#endif

// Decimal 52216 (0xCBF8) [Value] - IRQ interrupt vector (3 bytes)
#ifndef _VEC_IRQ_VECTOR
#define _VEC_IRQ_VECTOR 52216
#endif

// Decimal 52219 (0xCBFB) [Value] - SWI/NMI interrupt vector (3 bytes)
#ifndef _VEC_SWI_VECTOR
#define _VEC_SWI_VECTOR 52219
#endif

// Decimal 52219 (0xCBFB) [Value] - SWI/NMI interrupt vector (3 bytes)
#ifndef _VEC_NMI_VECTOR
#define _VEC_NMI_VECTOR 52219
#endif

// Decimal 52222 (0xCBFE) [Value] - Cold start flag (warm start if = 0x7321)
#ifndef _VEC_COLD_FLAG
#define _VEC_COLD_FLAG 52222
#endif

// Decimal 53248 (0xD000) [Value] - VIA port B data I/O register
#ifndef _VIA_PORT_B
#define _VIA_PORT_B 53248
#endif

// Decimal 53249 (0xD001) [Value] - VIA port A data I/O register (handshaking)
#ifndef _VIA_PORT_A
#define _VIA_PORT_A 53249
#endif

// Decimal 53250 (0xD002) [Value] - VIA port B data direction register (0=input 1=output)
#ifndef _VIA_DDR_B
#define _VIA_DDR_B 53250
#endif

// Decimal 53251 (0xD003) [Value] - VIA port A data direction register (0=input 1=output)
#ifndef _VIA_DDR_A
#define _VIA_DDR_A 53251
#endif

// Decimal 53252 (0xD004) [Value] - VIA timer 1 count register lo (scale factor)
#ifndef _VIA_T1_CNT_LO
#define _VIA_T1_CNT_LO 53252
#endif

// Decimal 53253 (0xD005) [Value] - VIA timer 1 count register hi
#ifndef _VIA_T1_CNT_HI
#define _VIA_T1_CNT_HI 53253
#endif

// Decimal 53254 (0xD006) [Value] - VIA timer 1 latch register lo
#ifndef _VIA_T1_LCH_LO
#define _VIA_T1_LCH_LO 53254
#endif

// Decimal 53255 (0xD007) [Value] - VIA timer 1 latch register hi
#ifndef _VIA_T1_LCH_HI
#define _VIA_T1_LCH_HI 53255
#endif

// Decimal 53256 (0xD008) [Value] - VIA timer 2 count/latch register lo (refresh)
#ifndef _VIA_T2_LO
#define _VIA_T2_LO 53256
#endif

// Decimal 53257 (0xD009) [Value] - VIA timer 2 count/latch register hi
#ifndef _VIA_T2_HI
#define _VIA_T2_HI 53257
#endif

// Decimal 53258 (0xD00A) [Value] - VIA shift register
#ifndef _VIA_SHIFT_REG
#define _VIA_SHIFT_REG 53258
#endif

// Decimal 53259 (0xD00B) [Value] - VIA auxiliary control register
#ifndef _VIA_AUX_CNTL
#define _VIA_AUX_CNTL 53259
#endif

// Decimal 53260 (0xD00C) [Value] - VIA control register
#ifndef _VIA_CNTL
#define _VIA_CNTL 53260
#endif

// Decimal 53261 (0xD00D) [Value] - VIA interrupt flags register
#ifndef _VIA_INT_FLAGS
#define _VIA_INT_FLAGS 53261
#endif

// Decimal 53262 (0xD00E) [Value] - VIA interrupt enable register
#ifndef _VIA_INT_ENABLE
#define _VIA_INT_ENABLE 53262
#endif

// Decimal 53263 (0xD00F) [Value] - VIA port A data I/O register (no handshaking)
#ifndef _VIA_PORT_A_NOHS
#define _VIA_PORT_A_NOHS 53263
#endif

// Decimal 61440 (0xF000) [Value]
#ifndef _COLD_START
#define _COLD_START 61440
#endif

// Decimal 61548 (0xF06C) [Value]
#ifndef _WARM_START
#define _WARM_START 61548
#endif

// Decimal 61772 (0xF14C) [Value]
#ifndef _INIT_VIA
#define _INIT_VIA 61772
#endif

// Decimal 61796 (0xF164) [Value]
#ifndef _INIT_OS_RAM
#define _INIT_OS_RAM 61796
#endif

// Decimal 61835 (0xF18B) [Value]
#ifndef _INIT_OS
#define _INIT_OS 61835
#endif

// Decimal 61842 (0xF192) [Value]
#ifndef _WAIT_RECAL
#define _WAIT_RECAL 61842
#endif

// Decimal 61858 (0xF1A2) [Value]
#ifndef _SET_REFRESH
#define _SET_REFRESH 61858
#endif

// Decimal 61866 (0xF1AA) [Value]
#ifndef _DP_TO_D0
#define _DP_TO_D0 61866
#endif

// Decimal 61871 (0xF1AF) [Value]
#ifndef _DP_TO_C8
#define _DP_TO_C8 61871
#endif

// Decimal 61876 (0xF1B4) [Value]
#ifndef _READ_BTNS_MASK
#define _READ_BTNS_MASK 61876
#endif

// Decimal 61882 (0xF1BA) [Value]
#ifndef _READ_BTNS
#define _READ_BTNS 61882
#endif

// Decimal 61941 (0xF1F5) [Value]
#ifndef _JOY_ANALOG
#define _JOY_ANALOG 61941
#endif

// Decimal 61944 (0xF1F8) [Value]
#ifndef _JOY_DIGITAL
#define _JOY_DIGITAL 61944
#endif

// Decimal 62038 (0xF256) [Value]
#ifndef _SOUND_BYTE
#define _SOUND_BYTE 62038
#endif

// Decimal 62041 (0xF259) [Value]
#ifndef _SOUND_BYTE_X
#define _SOUND_BYTE_X 62041
#endif

// Decimal 62043 (0xF25B) [Value]
#ifndef _SOUND_BYTE_RAW
#define _SOUND_BYTE_RAW 62043
#endif

// Decimal 62066 (0xF272) [Value]
#ifndef _CLEAR_SOUND
#define _CLEAR_SOUND 62066
#endif

// Decimal 62077 (0xF27D) [Value]
#ifndef _SOUND_BYTES
#define _SOUND_BYTES 62077
#endif

// Decimal 62084 (0xF284) [Value]
#ifndef _SOUND_BYTES_X
#define _SOUND_BYTES_X 62084
#endif

// Decimal 62089 (0xF289) [Value]
#ifndef _DO_SOUND
#define _DO_SOUND 62089
#endif

// Decimal 62092 (0xF28C) [Value]
#ifndef _DO_SOUND_X
#define _DO_SOUND_X 62092
#endif

// Decimal 62109 (0xF29D) [Value]
#ifndef _INTENSITY_1F
#define _INTENSITY_1F 62109
#endif

// Decimal 62113 (0xF2A1) [Value]
#ifndef _INTENSITY_3F
#define _INTENSITY_3F 62113
#endif

// Decimal 62117 (0xF2A5) [Value]
#ifndef _INTENSITY_5F
#define _INTENSITY_5F 62117
#endif

// Decimal 62121 (0xF2A9) [Value]
#ifndef _INTENSITY_7F
#define _INTENSITY_7F 62121
#endif

// Decimal 62123 (0xF2AB) [Value]
#ifndef _INTENSITY_A
#define _INTENSITY_A 62123
#endif

// Decimal 62142 (0xF2BE) [Value]
#ifndef _DOT_IX_B
#define _DOT_IX_B 62142
#endif

// Decimal 62145 (0xF2C1) [Value]
#ifndef _DOT_IX
#define _DOT_IX 62145
#endif

// Decimal 62147 (0xF2C3) [Value]
#ifndef _DOT_D
#define _DOT_D 62147
#endif

// Decimal 62149 (0xF2C5) [Value]
#ifndef _DOT_HERE
#define _DOT_HERE 62149
#endif

// Decimal 62165 (0xF2D5) [Value]
#ifndef _DOT_LIST
#define _DOT_LIST 62165
#endif

// Decimal 62174 (0xF2DE) [Value]
#ifndef _DOT_LIST_RESET
#define _DOT_LIST_RESET 62174
#endif

// Decimal 62182 (0xF2E6) [Value]
#ifndef _RECALIBRATE
#define _RECALIBRATE 62182
#endif

// Decimal 62194 (0xF2F2) [Value]
#ifndef _MOVETO_X_7F
#define _MOVETO_X_7F 62194
#endif

// Decimal 62204 (0xF2FC) [Value]
#ifndef _MOVETO_D_7F
#define _MOVETO_D_7F 62204
#endif

// Decimal 62216 (0xF308) [Value]
#ifndef _MOVETO_IX_FF
#define _MOVETO_IX_FF 62216
#endif

// Decimal 62220 (0xF30C) [Value]
#ifndef _MOVETO_IX_7F
#define _MOVETO_IX_7F 62220
#endif

// Decimal 62222 (0xF30E) [Value] - Used to be named Moveto_ix_a but this is wrong.
#ifndef _MOVETO_IX_B
#define _MOVETO_IX_B 62222
#endif

// Decimal 62224 (0xF310) [Value]
#ifndef _MOVETO_IX
#define _MOVETO_IX 62224
#endif

// Decimal 62226 (0xF312) [Value]
#ifndef _MOVETO_D
#define _MOVETO_D 62226
#endif

// Decimal 62282 (0xF34A) [Value]
#ifndef _RESET0REF_D0
#define _RESET0REF_D0 62282
#endif

// Decimal 62287 (0xF34F) [Value]
#ifndef _CHECK0REF
#define _CHECK0REF 62287
#endif

// Decimal 62292 (0xF354) [Value]
#ifndef _RESET0REF
#define _RESET0REF 62292
#endif

// Decimal 62299 (0xF35B) [Value]
#ifndef _RESET_PEN
#define _RESET_PEN 62299
#endif

// Decimal 62315 (0xF36B) [Value]
#ifndef _RESET0INT
#define _RESET0INT 62315
#endif

// Decimal 62323 (0xF373) [Value]
#ifndef _PRINT_STR_HWYX
#define _PRINT_STR_HWYX 62323
#endif

// Decimal 62328 (0xF378) [Value]
#ifndef _PRINT_STR_YX
#define _PRINT_STR_YX 62328
#endif

// Decimal 62330 (0xF37A) [Value]
#ifndef _PRINT_STR_D
#define _PRINT_STR_D 62330
#endif

// Decimal 62341 (0xF385) [Value]
#ifndef _PRINT_LIST_HW
#define _PRINT_LIST_HW 62341
#endif

// Decimal 62346 (0xF38A) [Value]
#ifndef _PRINT_LIST
#define _PRINT_LIST 62346
#endif

// Decimal 62348 (0xF38C) [Value]
#ifndef _PRINT_LIST_CHK
#define _PRINT_LIST_CHK 62348
#endif

// Decimal 62353 (0xF391) [Value]
#ifndef _PRINT_SHIPS_X
#define _PRINT_SHIPS_X 62353
#endif

// Decimal 62355 (0xF393) [Value]
#ifndef _PRINT_SHIPS
#define _PRINT_SHIPS 62355
#endif

// Decimal 62381 (0xF3AD) [Value] - count y x y x ...
#ifndef _MOV_DRAW_VLC_A
#define _MOV_DRAW_VLC_A 62381
#endif

// Decimal 62385 (0xF3B1) [Value] - y x y x ...
#ifndef _MOV_DRAW_VL_B
#define _MOV_DRAW_VL_B 62385
#endif

// Decimal 62389 (0xF3B5) [Value] - count scale y x y x ...
#ifndef _MOV_DRAW_VLCS
#define _MOV_DRAW_VLCS 62389
#endif

// Decimal 62391 (0xF3B7) [Value] - y x y x ...
#ifndef _MOV_DRAW_VL_AB
#define _MOV_DRAW_VL_AB 62391
#endif

// Decimal 62393 (0xF3B9) [Value] - y x y x ...
#ifndef _MOV_DRAW_VL_A
#define _MOV_DRAW_VL_A 62393
#endif

// Decimal 62396 (0xF3BC) [Value] - y x y x ...
#ifndef _MOV_DRAW_VL
#define _MOV_DRAW_VL 62396
#endif

// Decimal 62398 (0xF3BE) [Value] - y x y x ...
#ifndef _MOV_DRAW_VL_D
#define _MOV_DRAW_VL_D 62398
#endif

// Decimal 62414 (0xF3CE) [Value] - count y x y x ...
#ifndef _DRAW_VLC
#define _DRAW_VLC 62414
#endif

// Decimal 62418 (0xF3D2) [Value] - y x y x ...
#ifndef _DRAW_VL_B
#define _DRAW_VL_B 62418
#endif

// Decimal 62422 (0xF3D6) [Value] - count scale y x y x ...
#ifndef _DRAW_VLCS
#define _DRAW_VLCS 62422
#endif

// Decimal 62424 (0xF3D8) [Value] - y x y x ...
#ifndef _DRAW_VL_AB
#define _DRAW_VL_AB 62424
#endif

// Decimal 62426 (0xF3DA) [Value] - y x y x ...
#ifndef _DRAW_VL_A
#define _DRAW_VL_A 62426
#endif

// Decimal 62429 (0xF3DD) [Value] - y x y x ...
#ifndef _DRAW_VL
#define _DRAW_VL 62429
#endif

// Decimal 62431 (0xF3DF) [Value] - y x y x ...
#ifndef _DRAW_LINE_D
#define _DRAW_LINE_D 62431
#endif

// Decimal 62468 (0xF404) [Value] - pattern y x pattern y x ... 0x01
#ifndef _DRAW_VLP_FF
#define _DRAW_VLP_FF 62468
#endif

// Decimal 62472 (0xF408) [Value] - pattern y x pattern y x ... 0x01
#ifndef _DRAW_VLP_7F
#define _DRAW_VLP_7F 62472
#endif

// Decimal 62476 (0xF40C) [Value] - scale pattern y x pattern y x ... 0x01
#ifndef _DRAW_VLP_SCALE
#define _DRAW_VLP_SCALE 62476
#endif

// Decimal 62478 (0xF40E) [Value] - pattern y x pattern y x ... 0x01
#ifndef _DRAW_VLP_B
#define _DRAW_VLP_B 62478
#endif

// Decimal 62480 (0xF410) [Value] - pattern y x pattern y x ... 0x01
#ifndef _DRAW_VLP
#define _DRAW_VLP 62480
#endif

// Decimal 62516 (0xF434) [Value] - y x y x ...
#ifndef _DRAW_PAT_VL_A
#define _DRAW_PAT_VL_A 62516
#endif

// Decimal 62519 (0xF437) [Value] - y x y x ...
#ifndef _DRAW_PAT_VL
#define _DRAW_PAT_VL 62519
#endif

// Decimal 62521 (0xF439) [Value] - y x y x ...
#ifndef _DRAW_PAT_VL_D
#define _DRAW_PAT_VL_D 62521
#endif

// Decimal 62574 (0xF46E) [Value] - mode y x mode y x ... 0x01
#ifndef _DRAW_VL_MODE
#define _DRAW_VL_MODE 62574
#endif

// Decimal 62613 (0xF495) [Value]
#ifndef _PRINT_STR
#define _PRINT_STR 62613
#endif

// Decimal 62737 (0xF511) [Value]
#ifndef _RANDOM_3
#define _RANDOM_3 62737
#endif

// Decimal 62743 (0xF517) [Value]
#ifndef _RANDOM
#define _RANDOM 62743
#endif

// Decimal 62771 (0xF533) [Value]
#ifndef _INIT_MUSIC_BUF
#define _INIT_MUSIC_BUF 62771
#endif

// Decimal 62783 (0xF53F) [Value]
#ifndef _CLEAR_X_B
#define _CLEAR_X_B 62783
#endif

// Decimal 62786 (0xF542) [Value] - never used by GCE carts?
#ifndef _CLEAR_C8_RAM
#define _CLEAR_C8_RAM 62786
#endif

// Decimal 62789 (0xF545) [Value]
#ifndef _CLEAR_X_256
#define _CLEAR_X_256 62789
#endif

// Decimal 62792 (0xF548) [Value]
#ifndef _CLEAR_X_D
#define _CLEAR_X_D 62792
#endif

// Decimal 62800 (0xF550) [Value]
#ifndef _CLEAR_X_B_80
#define _CLEAR_X_B_80 62800
#endif

// Decimal 62802 (0xF552) [Value]
#ifndef _CLEAR_X_B_A
#define _CLEAR_X_B_A 62802
#endif

// Decimal 62810 (0xF55A) [Value]
#ifndef _DEC_3_COUNTERS
#define _DEC_3_COUNTERS 62810
#endif

// Decimal 62814 (0xF55E) [Value]
#ifndef _DEC_6_COUNTERS
#define _DEC_6_COUNTERS 62814
#endif

// Decimal 62819 (0xF563) [Value]
#ifndef _DEC_COUNTERS
#define _DEC_COUNTERS 62819
#endif

// Decimal 62829 (0xF56D) [Value] - 30 cycles
#ifndef _DELAY_3
#define _DELAY_3 62829
#endif

// Decimal 62833 (0xF571) [Value] - 25 cycles
#ifndef _DELAY_2
#define _DELAY_2 62833
#endif

// Decimal 62837 (0xF575) [Value] - 20 cycles
#ifndef _DELAY_1
#define _DELAY_1 62837
#endif

// Decimal 62841 (0xF579) [Value] - 12 cycles
#ifndef _DELAY_0
#define _DELAY_0 62841
#endif

// Decimal 62842 (0xF57A) [Value] - 5*B + 10 cycles
#ifndef _DELAY_B
#define _DELAY_B 62842
#endif

// Decimal 62845 (0xF57D) [Value] - 5 cycles
#ifndef _DELAY_RTS
#define _DELAY_RTS 62845
#endif

// Decimal 62846 (0xF57E) [Value]
#ifndef _BITMASK_A
#define _BITMASK_A 62846
#endif

// Decimal 62852 (0xF584) [Value]
#ifndef _ABS_A_B
#define _ABS_A_B 62852
#endif

// Decimal 62859 (0xF58B) [Value]
#ifndef _ABS_B
#define _ABS_B 62859
#endif

// Decimal 62867 (0xF593) [Value]
#ifndef _RISE_RUN_ANGLE
#define _RISE_RUN_ANGLE 62867
#endif

// Decimal 62937 (0xF5D9) [Value]
#ifndef _GET_RISE_IDX
#define _GET_RISE_IDX 62937
#endif

// Decimal 62939 (0xF5DB) [Value]
#ifndef _GET_RUN_IDX
#define _GET_RUN_IDX 62939
#endif

// Decimal 62959 (0xF5EF) [Value]
#ifndef _GET_RISE_RUN
#define _GET_RISE_RUN 62959
#endif

// Decimal 62975 (0xF5FF) [Value]
#ifndef _RISE_RUN_X
#define _RISE_RUN_X 62975
#endif

// Decimal 62977 (0xF601) [Value]
#ifndef _RISE_RUN_Y
#define _RISE_RUN_Y 62977
#endif

// Decimal 62979 (0xF603) [Value]
#ifndef _RISE_RUN_LEN
#define _RISE_RUN_LEN 62979
#endif

// Decimal 62992 (0xF610) [Value]
#ifndef _ROT_VL_AB
#define _ROT_VL_AB 62992
#endif

// Decimal 62998 (0xF616) [Value]
#ifndef _ROT_VL
#define _ROT_VL 62998
#endif

// Decimal 63007 (0xF61F) [Value]
#ifndef _ROT_VL_MODE_A
#define _ROT_VL_MODE_A 63007
#endif

// Decimal 63019 (0xF62B) [Value]
#ifndef _ROT_VL_MODE
#define _ROT_VL_MODE 63019
#endif

// Decimal 63031 (0xF637) [Value]
#ifndef _ROT_VL_DFT
#define _ROT_VL_DFT 63031
#endif

// Decimal 63067 (0xF65B) [Value]
#ifndef _XFORM_RUN_A
#define _XFORM_RUN_A 63067
#endif

// Decimal 63069 (0xF65D) [Value]
#ifndef _XFORM_RUN
#define _XFORM_RUN 63069
#endif

// Decimal 63073 (0xF661) [Value]
#ifndef _XFORM_RISE_A
#define _XFORM_RISE_A 63073
#endif

// Decimal 63075 (0xF663) [Value]
#ifndef _XFORM_RISE
#define _XFORM_RISE 63075
#endif

// Decimal 63103 (0xF67F) [Value]
#ifndef _MOVE_MEM_A_1
#define _MOVE_MEM_A_1 63103
#endif

// Decimal 63107 (0xF683) [Value]
#ifndef _MOVE_MEM_A
#define _MOVE_MEM_A 63107
#endif

// Decimal 63111 (0xF687) [Value]
#ifndef _INIT_MUSIC_CHK
#define _INIT_MUSIC_CHK 63111
#endif

// Decimal 63117 (0xF68D) [Value]
#ifndef _INIT_MUSIC
#define _INIT_MUSIC 63117
#endif

// Decimal 63122 (0xF692) [Value]
#ifndef _INIT_MUSIC_X
#define _INIT_MUSIC_X 63122
#endif

// Decimal 63401 (0xF7A9) [Value]
#ifndef _SELECT_GAME
#define _SELECT_GAME 63401
#endif

// Decimal 63567 (0xF84F) [Value]
#ifndef _CLEAR_SCORE
#define _CLEAR_SCORE 63567
#endif

// Decimal 63582 (0xF85E) [Value]
#ifndef _ADD_SCORE_A
#define _ADD_SCORE_A 63582
#endif

// Decimal 63612 (0xF87C) [Value]
#ifndef _ADD_SCORE_D
#define _ADD_SCORE_D 63612
#endif

// Decimal 63671 (0xF8B7) [Value]
#ifndef _STRIP_ZEROS
#define _STRIP_ZEROS 63671
#endif

// Decimal 63687 (0xF8C7) [Value]
#ifndef _COMPARE_SCORE
#define _COMPARE_SCORE 63687
#endif

// Decimal 63704 (0xF8D8) [Value]
#ifndef _NEW_HIGH_SCORE
#define _NEW_HIGH_SCORE 63704
#endif

// Decimal 63717 (0xF8E5) [Value]
#ifndef _OBJ_WILL_HIT_U
#define _OBJ_WILL_HIT_U 63717
#endif

// Decimal 63731 (0xF8F3) [Value]
#ifndef _OBJ_WILL_HIT
#define _OBJ_WILL_HIT 63731
#endif

// Decimal 63743 (0xF8FF) [Value]
#ifndef _OBJ_HIT
#define _OBJ_HIT 63743
#endif

// Decimal 63790 (0xF92E) [Value]
#ifndef _EXPLOSION_SND
#define _EXPLOSION_SND 63790
#endif

// Decimal 65439 (0xFF9F) [Value]
#ifndef _DRAW_GRID_VL
#define _DRAW_GRID_VL 65439
#endif

// Decimal 63988 (0xF9F4) [Value] - Char_Table
#ifndef _CHAR_TABLE
#define _CHAR_TABLE 63988
#endif

// Decimal 64468 (0xFBD4) [Value] - Char_Table_End
#ifndef _CHAR_TABLE_END
#define _CHAR_TABLE_END 64468
#endif

// Decimal 64781 (0xFD0D) [Value] - Poweron music, crazy coaster and narrow escape
#ifndef _VX_MUSIC_1
#define _VX_MUSIC_1 64781
#endif

// Decimal 64797 (0xFD1D) [Value] - Music for Berzerk
#ifndef _VX_MUSIC_2
#define _VX_MUSIC_2 64797
#endif

// Decimal 64897 (0xFD81) [Value]
#ifndef _VX_MUSIC_3
#define _VX_MUSIC_3 64897
#endif

// Decimal 64979 (0xFDD3) [Value] - Music for Scramble
#ifndef _VX_MUSIC_4
#define _VX_MUSIC_4 64979
#endif

// Decimal 65080 (0xFE38) [Value] - Music for Solar Quest
#ifndef _VX_MUSIC_5
#define _VX_MUSIC_5 65080
#endif

// Decimal 65142 (0xFE76) [Value]
#ifndef _VX_MUSIC_6
#define _VX_MUSIC_6 65142
#endif

// Decimal 65222 (0xFEC6) [Value]
#ifndef _VX_MUSIC_7
#define _VX_MUSIC_7 65222
#endif

// Decimal 65272 (0xFEF8) [Value] - Music for Melody Master
#ifndef _VX_MUSIC_8
#define _VX_MUSIC_8 65272
#endif

// Decimal 65318 (0xFF26) [Value]
#ifndef _VX_MUSIC_9
#define _VX_MUSIC_9 65318
#endif

// Decimal 65348 (0xFF44) [Value]
#ifndef _VX_MUSIC_10
#define _VX_MUSIC_10 65348
#endif

// Decimal 65378 (0xFF62) [Value]
#ifndef _VX_MUSIC_11
#define _VX_MUSIC_11 65378
#endif

// Decimal 65402 (0xFF7A) [Value]
#ifndef _VX_MUSIC_12
#define _VX_MUSIC_12 65402
#endif

// Decimal 65423 (0xFF8F) [Value]
#ifndef _VX_MUSIC_13
#define _VX_MUSIC_13 65423
#endif


#endif
