
// This file was created by the WinCMOC compiler
// Created: 1/09/2016 11:49:21
// WinCMOC:  https://sourceforge.net/projects/cmoc-win32/
// CMOC:     http://perso.b2b2c.ca/~sarrazip/dev/cmoc.html

// Translated from "vectrexbios.asm"
//
// This file is in the public domain

#ifndef _VECTREX_VECTREXBIOS_H
#define _VECTREX_VECTREXBIOS_H

// Decimal 51200 (0xC800/$C800) [Constant] - Shadow of sound chip registers (15 bytes)
#ifndef _VEC_SND_SHADOW
#define _VEC_SND_SHADOW 51200
#endif

// Decimal 51215 (0xC80F/$C80F) [Constant] - Current state of all joystick buttons
#ifndef _VEC_BTN_STATE
#define _VEC_BTN_STATE 51215
#endif

// Decimal 51216 (0xC810/$C810) [Constant] - Previous state of all joystick buttons
#ifndef _VEC_PREV_BTNS
#define _VEC_PREV_BTNS 51216
#endif

// Decimal 51217 (0xC811/$C811) [Constant] - Current toggle state of all buttons
#ifndef _VEC_BUTTONS
#define _VEC_BUTTONS 51217
#endif

// Decimal 51218 (0xC812/$C812) [Constant] - Current toggle state of stick 1 button 1
#ifndef _VEC_BUTTON_1_1
#define _VEC_BUTTON_1_1 51218
#endif

// Decimal 51219 (0xC813/$C813) [Constant] - Current toggle state of stick 1 button 2
#ifndef _VEC_BUTTON_1_2
#define _VEC_BUTTON_1_2 51219
#endif

// Decimal 51220 (0xC814/$C814) [Constant] - Current toggle state of stick 1 button 3
#ifndef _VEC_BUTTON_1_3
#define _VEC_BUTTON_1_3 51220
#endif

// Decimal 51221 (0xC815/$C815) [Constant] - Current toggle state of stick 1 button 4
#ifndef _VEC_BUTTON_1_4
#define _VEC_BUTTON_1_4 51221
#endif

// Decimal 51222 (0xC816/$C816) [Constant] - Current toggle state of stick 2 button 1
#ifndef _VEC_BUTTON_2_1
#define _VEC_BUTTON_2_1 51222
#endif

// Decimal 51223 (0xC817/$C817) [Constant] - Current toggle state of stick 2 button 2
#ifndef _VEC_BUTTON_2_2
#define _VEC_BUTTON_2_2 51223
#endif

// Decimal 51224 (0xC818/$C818) [Constant] - Current toggle state of stick 2 button 3
#ifndef _VEC_BUTTON_2_3
#define _VEC_BUTTON_2_3 51224
#endif

// Decimal 51225 (0xC819/$C819) [Constant] - Current toggle state of stick 2 button 4
#ifndef _VEC_BUTTON_2_4
#define _VEC_BUTTON_2_4 51225
#endif

// Decimal 51226 (0xC81A/$C81A) [Constant] - Joystick A/D resolution (0x80=min 0x00=max)
#ifndef _VEC_JOY_RESLTN
#define _VEC_JOY_RESLTN 51226
#endif

// Decimal 51227 (0xC81B/$C81B) [Constant] - Joystick 1 left/right
#ifndef _VEC_JOY_1_X
#define _VEC_JOY_1_X 51227
#endif

// Decimal 51228 (0xC81C/$C81C) [Constant] - Joystick 1 up/down
#ifndef _VEC_JOY_1_Y
#define _VEC_JOY_1_Y 51228
#endif

// Decimal 51229 (0xC81D/$C81D) [Constant] - Joystick 2 left/right
#ifndef _VEC_JOY_2_X
#define _VEC_JOY_2_X 51229
#endif

// Decimal 51230 (0xC81E/$C81E) [Constant] - Joystick 2 up/down
#ifndef _VEC_JOY_2_Y
#define _VEC_JOY_2_Y 51230
#endif

// Decimal 51231 (0xC81F/$C81F) [Constant] - Joystick enable/mux flags (4 bytes)
#ifndef _VEC_JOY_MUX
#define _VEC_JOY_MUX 51231
#endif

// Decimal 51231 (0xC81F/$C81F) [Constant] - Joystick 1 X enable/mux flag (=1)
#ifndef _VEC_JOY_MUX_1_X
#define _VEC_JOY_MUX_1_X 51231
#endif

// Decimal 51232 (0xC820/$C820) [Constant] - Joystick 1 Y enable/mux flag (=3)
#ifndef _VEC_JOY_MUX_1_Y
#define _VEC_JOY_MUX_1_Y 51232
#endif

// Decimal 51233 (0xC821/$C821) [Constant] - Joystick 2 X enable/mux flag (=5)
#ifndef _VEC_JOY_MUX_2_X
#define _VEC_JOY_MUX_2_X 51233
#endif

// Decimal 51234 (0xC822/$C822) [Constant] - Joystick 2 Y enable/mux flag (=7)
#ifndef _VEC_JOY_MUX_2_Y
#define _VEC_JOY_MUX_2_Y 51234
#endif

// Decimal 51235 (0xC823/$C823) [Constant] - Misc counter/flag byte, zero when not in use
#ifndef _VEC_MISC_COUNT
#define _VEC_MISC_COUNT 51235
#endif

// Decimal 51236 (0xC824/$C824) [Constant] - Check0Ref enable flag
#ifndef _VEC_0REF_ENABLE
#define _VEC_0REF_ENABLE 51236
#endif

// Decimal 51237 (0xC825/$C825) [Constant] - Loop counter word (incremented in Wait_Recal)
#ifndef _VEC_LOOP_COUNT
#define _VEC_LOOP_COUNT 51237
#endif

// Decimal 51239 (0xC827/$C827) [Constant] - Default brightness
#ifndef _VEC_BRIGHTNESS
#define _VEC_BRIGHTNESS 51239
#endif

// Decimal 51240 (0xC828/$C828) [Constant] - Dot dwell time?
#ifndef _VEC_DOT_DWELL
#define _VEC_DOT_DWELL 51240
#endif

// Decimal 51241 (0xC829/$C829) [Constant] - Dot pattern (bits)
#ifndef _VEC_PATTERN
#define _VEC_PATTERN 51241
#endif

// Decimal 51242 (0xC82A/$C82A) [Constant] - Default text height and width
#ifndef _VEC_TEXT_HW
#define _VEC_TEXT_HW 51242
#endif

// Decimal 51242 (0xC82A/$C82A) [Constant] - Default text height
#ifndef _VEC_TEXT_HEIGHT
#define _VEC_TEXT_HEIGHT 51242
#endif

// Decimal 51243 (0xC82B/$C82B) [Constant] - Default text width
#ifndef _VEC_TEXT_WIDTH
#define _VEC_TEXT_WIDTH 51243
#endif

// Decimal 51244 (0xC82C/$C82C) [Constant] - Temporary string pointer for Print_Str
#ifndef _VEC_STR_PTR
#define _VEC_STR_PTR 51244
#endif

// Decimal 51246 (0xC82E/$C82E) [Constant] - Six bytes of counters
#ifndef _VEC_COUNTERS
#define _VEC_COUNTERS 51246
#endif

// Decimal 51246 (0xC82E/$C82E) [Constant] - First counter byte
#ifndef _VEC_COUNTER_1
#define _VEC_COUNTER_1 51246
#endif

// Decimal 51247 (0xC82F/$C82F) [Constant] - Second counter byte
#ifndef _VEC_COUNTER_2
#define _VEC_COUNTER_2 51247
#endif

// Decimal 51248 (0xC830/$C830) [Constant] - Third counter byte
#ifndef _VEC_COUNTER_3
#define _VEC_COUNTER_3 51248
#endif

// Decimal 51249 (0xC831/$C831) [Constant] - Fourth counter byte
#ifndef _VEC_COUNTER_4
#define _VEC_COUNTER_4 51249
#endif

// Decimal 51250 (0xC832/$C832) [Constant] - Fifth counter byte
#ifndef _VEC_COUNTER_5
#define _VEC_COUNTER_5 51250
#endif

// Decimal 51251 (0xC833/$C833) [Constant] - Sixth counter byte
#ifndef _VEC_COUNTER_6
#define _VEC_COUNTER_6 51251
#endif

// Decimal 51252 (0xC834/$C834) [Constant] - Temp storage word for rise/run
#ifndef _VEC_RISERUN_TMP
#define _VEC_RISERUN_TMP 51252
#endif

// Decimal 51254 (0xC836/$C836) [Constant] - Angle for rise/run and rotation calculations
#ifndef _VEC_ANGLE
#define _VEC_ANGLE 51254
#endif

// Decimal 51255 (0xC837/$C837) [Constant] - Index pair for run
#ifndef _VEC_RUN_INDEX
#define _VEC_RUN_INDEX 51255
#endif

// Decimal 51257 (0xC839/$C839) [Constant] - Index pair for rise
#ifndef _VEC_RISE_INDEX
#define _VEC_RISE_INDEX 51257
#endif

// Decimal 51259 (0xC83B/$C83B) [Constant] - length for rise/run
#ifndef _VEC_RISERUN_LEN
#define _VEC_RISERUN_LEN 51259
#endif

// Decimal 51261 (0xC83D/$C83D) [Constant] - Refresh time (divided by 1.5MHz)
#ifndef _VEC_RFRSH
#define _VEC_RFRSH 51261
#endif

// Decimal 51261 (0xC83D/$C83D) [Constant] - Refresh time low byte
#ifndef _VEC_RFRSH_LO
#define _VEC_RFRSH_LO 51261
#endif

// Decimal 51262 (0xC83E/$C83E) [Constant] - Refresh time high byte
#ifndef _VEC_RFRSH_HI
#define _VEC_RFRSH_HI 51262
#endif

// Decimal 51263 (0xC83F/$C83F) [Constant] - Music work buffer (14 bytes, backwards?)
#ifndef _VEC_MUSIC_WORK
#define _VEC_MUSIC_WORK 51263
#endif

// Decimal 51266 (0xC842/$C842) [Constant] - register 10
#ifndef _VEC_MUSIC_WK_A
#define _VEC_MUSIC_WK_A 51266
#endif

// Decimal 51269 (0xC845/$C845) [Constant] - register 7
#ifndef _VEC_MUSIC_WK_7
#define _VEC_MUSIC_WK_7 51269
#endif

// Decimal 51270 (0xC846/$C846) [Constant] - register 6
#ifndef _VEC_MUSIC_WK_6
#define _VEC_MUSIC_WK_6 51270
#endif

// Decimal 51271 (0xC847/$C847) [Constant] - register 5
#ifndef _VEC_MUSIC_WK_5
#define _VEC_MUSIC_WK_5 51271
#endif

// Decimal 51275 (0xC84B/$C84B) [Constant] - register 1
#ifndef _VEC_MUSIC_WK_1
#define _VEC_MUSIC_WK_1 51275
#endif

// Decimal 51277 (0xC84D/$C84D) [Constant] - Pointer to note-to-fr.EQUency table (normally 0xFC8D)
#ifndef _VEC_FREQ_TABLE
#define _VEC_FREQ_TABLE 51277
#endif

// Decimal 51279 (0xC84F/$C84F) [Constant] - Maximum number of players for Select_Game
#ifndef _VEC_MAX_PLAYERS
#define _VEC_MAX_PLAYERS 51279
#endif

// Decimal 51280 (0xC850/$C850) [Constant] - Maximum number of games for Select_Game
#ifndef _VEC_MAX_GAMES
#define _VEC_MAX_GAMES 51280
#endif

// Decimal 51279 (0xC84F/$C84F) [Constant] - Storage for first music header word (ADSR table)
#ifndef _VEC_ADSR_TABLE
#define _VEC_ADSR_TABLE 51279
#endif

// Decimal 51281 (0xC851/$C851) [Constant] - Storage for second music header word ('twang' table)
#ifndef _VEC_TWANG_TABLE
#define _VEC_TWANG_TABLE 51281
#endif

// Decimal 51283 (0xC853/$C853) [Constant] - Music data pointer
#ifndef _VEC_MUSIC_PTR
#define _VEC_MUSIC_PTR 51283
#endif

// Decimal 51283 (0xC853/$C853) [Constant] - Used by Explosion_Snd - bit for first channel used?
#ifndef _VEC_EXPL_CHANA
#define _VEC_EXPL_CHANA 51283
#endif

// Decimal 51284 (0xC854/$C854) [Constant] - Used by Explosion_Snd - bits for all channels used?
#ifndef _VEC_EXPL_CHANS
#define _VEC_EXPL_CHANS 51284
#endif

// Decimal 51285 (0xC855/$C855) [Constant] - Current sound channel number for Init_Music
#ifndef _VEC_MUSIC_CHAN
#define _VEC_MUSIC_CHAN 51285
#endif

// Decimal 51286 (0xC856/$C856) [Constant] - Music active flag (0x00=off 0x01=start 0x80=on)
#ifndef _VEC_MUSIC_FLAG
#define _VEC_MUSIC_FLAG 51286
#endif

// Decimal 51287 (0xC857/$C857) [Constant] - Duration counter for Init_Music
#ifndef _VEC_DURATION
#define _VEC_DURATION 51287
#endif

// Decimal 51288 (0xC858/$C858) [Constant] - 3 word 'twang' table used by Init_Music
#ifndef _VEC_MUSIC_TWANG
#define _VEC_MUSIC_TWANG 51288
#endif

// Decimal 51288 (0xC858/$C858) [Constant] - Four bytes copied from Explosion_Snds U-reg parameters
#ifndef _VEC_EXPL_1
#define _VEC_EXPL_1 51288
#endif

// Decimal 51289 (0xC859/$C859) [Constant]
#ifndef _VEC_EXPL_2
#define _VEC_EXPL_2 51289
#endif

// Decimal 51290 (0xC85A/$C85A) [Constant]
#ifndef _VEC_EXPL_3
#define _VEC_EXPL_3 51290
#endif

// Decimal 51291 (0xC85B/$C85B) [Constant]
#ifndef _VEC_EXPL_4
#define _VEC_EXPL_4 51291
#endif

// Decimal 51292 (0xC85C/$C85C) [Constant] - Used by Explosion_Snd - channel number in use?
#ifndef _VEC_EXPL_CHAN
#define _VEC_EXPL_CHAN 51292
#endif

// Decimal 51293 (0xC85D/$C85D) [Constant] - Used by Explosion_Snd - bit for second channel used?
#ifndef _VEC_EXPL_CHANB
#define _VEC_EXPL_CHANB 51293
#endif

// Decimal 51294 (0xC85E/$C85E) [Constant] - ADSR timers for each sound channel (3 bytes)
#ifndef _VEC_ADSR_TIMERS
#define _VEC_ADSR_TIMERS 51294
#endif

// Decimal 51297 (0xC861/$C861) [Constant] - Storage for base fr.EQUency of each channel (3 words)
#ifndef _VEC_MUSIC_FREQ
#define _VEC_MUSIC_FREQ 51297
#endif

// Decimal 51303 (0xC867/$C867) [Constant] - Explosion_Snd initialization flag?
#ifndef _VEC_EXPL_FLAG
#define _VEC_EXPL_FLAG 51303
#endif

// Decimal 51319 (0xC877/$C877) [Constant] - Used by Explosion_Snd
#ifndef _VEC_EXPL_TIMER
#define _VEC_EXPL_TIMER 51319
#endif

// Decimal 51321 (0xC879/$C879) [Constant] - Number of players selected in Select_Game
#ifndef _VEC_NUM_PLAYERS
#define _VEC_NUM_PLAYERS 51321
#endif

// Decimal 51322 (0xC87A/$C87A) [Constant] - Game number selected in Select_Game
#ifndef _VEC_NUM_GAME
#define _VEC_NUM_GAME 51322
#endif

// Decimal 51323 (0xC87B/$C87B) [Constant] - Pointer to 3-byte random number seed (=0xC87D)
#ifndef _VEC_SEED_PTR
#define _VEC_SEED_PTR 51323
#endif

// Decimal 51325 (0xC87D/$C87D) [Constant] - Default 3-byte random number seed
#ifndef _VEC_RANDOM_SEED
#define _VEC_RANDOM_SEED 51325
#endif

// Decimal 52202 (0xCBEA/$CBEA) [Constant] - Default top-of-stack
#ifndef _VEC_DEFAULT_STK
#define _VEC_DEFAULT_STK 52202
#endif

// Decimal 52203 (0xCBEB/$CBEB) [Constant] - High score storage (7 bytes)
#ifndef _VEC_HIGH_SCORE
#define _VEC_HIGH_SCORE 52203
#endif

// Decimal 52210 (0xCBF2/$CBF2) [Constant] - SWI2/SWI3 interrupt vector (3 bytes)
#ifndef _VEC_SWI3_VECTOR
#define _VEC_SWI3_VECTOR 52210
#endif

// Decimal 52210 (0xCBF2/$CBF2) [Constant] - SWI2/SWI3 interrupt vector (3 bytes)
#ifndef _VEC_SWI2_VECTOR
#define _VEC_SWI2_VECTOR 52210
#endif

// Decimal 52213 (0xCBF5/$CBF5) [Constant] - FIRQ interrupt vector (3 bytes)
#ifndef _VEC_FIRQ_VECTOR
#define _VEC_FIRQ_VECTOR 52213
#endif

// Decimal 52216 (0xCBF8/$CBF8) [Constant] - IRQ interrupt vector (3 bytes)
#ifndef _VEC_IRQ_VECTOR
#define _VEC_IRQ_VECTOR 52216
#endif

// Decimal 52219 (0xCBFB/$CBFB) [Constant] - SWI/NMI interrupt vector (3 bytes)
#ifndef _VEC_SWI_VECTOR
#define _VEC_SWI_VECTOR 52219
#endif

// Decimal 52219 (0xCBFB/$CBFB) [Constant] - SWI/NMI interrupt vector (3 bytes)
#ifndef _VEC_NMI_VECTOR
#define _VEC_NMI_VECTOR 52219
#endif

// Decimal 52222 (0xCBFE/$CBFE) [Constant] - Cold start flag (warm start if = 0x7321)
#ifndef _VEC_COLD_FLAG
#define _VEC_COLD_FLAG 52222
#endif

// Decimal 53248 (0xD000/$D000) [Constant] - VIA port B data I/O register
#ifndef _VIA_PORT_B
#define _VIA_PORT_B 53248
#endif

// Decimal 53249 (0xD001/$D001) [Constant] - VIA port A data I/O register (handshaking)
#ifndef _VIA_PORT_A
#define _VIA_PORT_A 53249
#endif

// Decimal 53250 (0xD002/$D002) [Constant] - VIA port B data direction register (0=input 1=output)
#ifndef _VIA_DDR_B
#define _VIA_DDR_B 53250
#endif

// Decimal 53251 (0xD003/$D003) [Constant] - VIA port A data direction register (0=input 1=output)
#ifndef _VIA_DDR_A
#define _VIA_DDR_A 53251
#endif

// Decimal 53252 (0xD004/$D004) [Constant] - VIA timer 1 count register lo (scale factor)
#ifndef _VIA_T1_CNT_LO
#define _VIA_T1_CNT_LO 53252
#endif

// Decimal 53253 (0xD005/$D005) [Constant] - VIA timer 1 count register hi
#ifndef _VIA_T1_CNT_HI
#define _VIA_T1_CNT_HI 53253
#endif

// Decimal 53254 (0xD006/$D006) [Constant] - VIA timer 1 latch register lo
#ifndef _VIA_T1_LCH_LO
#define _VIA_T1_LCH_LO 53254
#endif

// Decimal 53255 (0xD007/$D007) [Constant] - VIA timer 1 latch register hi
#ifndef _VIA_T1_LCH_HI
#define _VIA_T1_LCH_HI 53255
#endif

// Decimal 53256 (0xD008/$D008) [Constant] - VIA timer 2 count/latch register lo (refresh)
#ifndef _VIA_T2_LO
#define _VIA_T2_LO 53256
#endif

// Decimal 53257 (0xD009/$D009) [Constant] - VIA timer 2 count/latch register hi
#ifndef _VIA_T2_HI
#define _VIA_T2_HI 53257
#endif

// Decimal 53258 (0xD00A/$D00A) [Constant] - VIA shift register
#ifndef _VIA_SHIFT_REG
#define _VIA_SHIFT_REG 53258
#endif

// Decimal 53259 (0xD00B/$D00B) [Constant] - VIA auxiliary control register
#ifndef _VIA_AUX_CNTL
#define _VIA_AUX_CNTL 53259
#endif

// Decimal 53260 (0xD00C/$D00C) [Constant] - VIA control register
#ifndef _VIA_CNTL
#define _VIA_CNTL 53260
#endif

// Decimal 53261 (0xD00D/$D00D) [Constant] - VIA interrupt flags register
#ifndef _VIA_INT_FLAGS
#define _VIA_INT_FLAGS 53261
#endif

// Decimal 53262 (0xD00E/$D00E) [Constant] - VIA interrupt enable register
#ifndef _VIA_INT_ENABLE
#define _VIA_INT_ENABLE 53262
#endif

// Decimal 53263 (0xD00F/$D00F) [Constant] - VIA port A data I/O register (no handshaking)
#ifndef _VIA_PORT_A_NOHS
#define _VIA_PORT_A_NOHS 53263
#endif

// Decimal 61440 (0xF000/$F000) [Constant]
#ifndef _COLD_START
#define _COLD_START 61440
#endif

// Decimal 61548 (0xF06C/$F06C) [Constant]
#ifndef _WARM_START
#define _WARM_START 61548
#endif

// Decimal 61772 (0xF14C/$F14C) [Constant]
#ifndef _INIT_VIA
#define _INIT_VIA 61772
#endif

// Decimal 61796 (0xF164/$F164) [Constant]
#ifndef _INIT_OS_RAM
#define _INIT_OS_RAM 61796
#endif

// Decimal 61835 (0xF18B/$F18B) [Constant]
#ifndef _INIT_OS
#define _INIT_OS 61835
#endif

// Decimal 61842 (0xF192/$F192) [Constant]
#ifndef _WAIT_RECAL
#define _WAIT_RECAL 61842
#endif

// Decimal 61858 (0xF1A2/$F1A2) [Constant]
#ifndef _SET_REFRESH
#define _SET_REFRESH 61858
#endif

// Decimal 61866 (0xF1AA/$F1AA) [Constant]
#ifndef _DP_TO_D0
#define _DP_TO_D0 61866
#endif

// Decimal 61871 (0xF1AF/$F1AF) [Constant]
#ifndef _DP_TO_C8
#define _DP_TO_C8 61871
#endif

// Decimal 61876 (0xF1B4/$F1B4) [Constant]
#ifndef _READ_BTNS_MASK
#define _READ_BTNS_MASK 61876
#endif

// Decimal 61882 (0xF1BA/$F1BA) [Constant]
#ifndef _READ_BTNS
#define _READ_BTNS 61882
#endif

// Decimal 61941 (0xF1F5/$F1F5) [Constant]
#ifndef _JOY_ANALOG
#define _JOY_ANALOG 61941
#endif

// Decimal 61944 (0xF1F8/$F1F8) [Constant]
#ifndef _JOY_DIGITAL
#define _JOY_DIGITAL 61944
#endif

// Decimal 62038 (0xF256/$F256) [Constant]
#ifndef _SOUND_BYTE
#define _SOUND_BYTE 62038
#endif

// Decimal 62041 (0xF259/$F259) [Constant]
#ifndef _SOUND_BYTE_X
#define _SOUND_BYTE_X 62041
#endif

// Decimal 62043 (0xF25B/$F25B) [Constant]
#ifndef _SOUND_BYTE_RAW
#define _SOUND_BYTE_RAW 62043
#endif

// Decimal 62066 (0xF272/$F272) [Constant]
#ifndef _CLEAR_SOUND
#define _CLEAR_SOUND 62066
#endif

// Decimal 62077 (0xF27D/$F27D) [Constant]
#ifndef _SOUND_BYTES
#define _SOUND_BYTES 62077
#endif

// Decimal 62084 (0xF284/$F284) [Constant]
#ifndef _SOUND_BYTES_X
#define _SOUND_BYTES_X 62084
#endif

// Decimal 62089 (0xF289/$F289) [Constant]
#ifndef _DO_SOUND
#define _DO_SOUND 62089
#endif

// Decimal 62092 (0xF28C/$F28C) [Constant]
#ifndef _DO_SOUND_X
#define _DO_SOUND_X 62092
#endif

// Decimal 62109 (0xF29D/$F29D) [Constant]
#ifndef _INTENSITY_1F
#define _INTENSITY_1F 62109
#endif

// Decimal 62113 (0xF2A1/$F2A1) [Constant]
#ifndef _INTENSITY_3F
#define _INTENSITY_3F 62113
#endif

// Decimal 62117 (0xF2A5/$F2A5) [Constant]
#ifndef _INTENSITY_5F
#define _INTENSITY_5F 62117
#endif

// Decimal 62121 (0xF2A9/$F2A9) [Constant]
#ifndef _INTENSITY_7F
#define _INTENSITY_7F 62121
#endif

// Decimal 62123 (0xF2AB/$F2AB) [Constant]
#ifndef _INTENSITY_A
#define _INTENSITY_A 62123
#endif

// Decimal 62142 (0xF2BE/$F2BE) [Constant]
#ifndef _DOT_IX_B
#define _DOT_IX_B 62142
#endif

// Decimal 62145 (0xF2C1/$F2C1) [Constant]
#ifndef _DOT_IX
#define _DOT_IX 62145
#endif

// Decimal 62147 (0xF2C3/$F2C3) [Constant]
#ifndef _DOT_D
#define _DOT_D 62147
#endif

// Decimal 62149 (0xF2C5/$F2C5) [Constant]
#ifndef _DOT_HERE
#define _DOT_HERE 62149
#endif

// Decimal 62165 (0xF2D5/$F2D5) [Constant]
#ifndef _DOT_LIST
#define _DOT_LIST 62165
#endif

// Decimal 62174 (0xF2DE/$F2DE) [Constant]
#ifndef _DOT_LIST_RESET
#define _DOT_LIST_RESET 62174
#endif

// Decimal 62182 (0xF2E6/$F2E6) [Constant]
#ifndef _RECALIBRATE
#define _RECALIBRATE 62182
#endif

// Decimal 62194 (0xF2F2/$F2F2) [Constant]
#ifndef _MOVETO_X_7F
#define _MOVETO_X_7F 62194
#endif

// Decimal 62204 (0xF2FC/$F2FC) [Constant]
#ifndef _MOVETO_D_7F
#define _MOVETO_D_7F 62204
#endif

// Decimal 62216 (0xF308/$F308) [Constant]
#ifndef _MOVETO_IX_FF
#define _MOVETO_IX_FF 62216
#endif

// Decimal 62220 (0xF30C/$F30C) [Constant]
#ifndef _MOVETO_IX_7F
#define _MOVETO_IX_7F 62220
#endif

// Decimal 62222 (0xF30E/$F30E) [Constant] - Used to be named Moveto_ix_a but this is wrong.
#ifndef _MOVETO_IX_B
#define _MOVETO_IX_B 62222
#endif

// Decimal 62224 (0xF310/$F310) [Constant]
#ifndef _MOVETO_IX
#define _MOVETO_IX 62224
#endif

// Decimal 62226 (0xF312/$F312) [Constant]
#ifndef _MOVETO_D
#define _MOVETO_D 62226
#endif

// Decimal 62282 (0xF34A/$F34A) [Constant]
#ifndef _RESET0REF_D0
#define _RESET0REF_D0 62282
#endif

// Decimal 62287 (0xF34F/$F34F) [Constant]
#ifndef _CHECK0REF
#define _CHECK0REF 62287
#endif

// Decimal 62292 (0xF354/$F354) [Constant]
#ifndef _RESET0REF
#define _RESET0REF 62292
#endif

// Decimal 62299 (0xF35B/$F35B) [Constant]
#ifndef _RESET_PEN
#define _RESET_PEN 62299
#endif

// Decimal 62315 (0xF36B/$F36B) [Constant]
#ifndef _RESET0INT
#define _RESET0INT 62315
#endif

// Decimal 62323 (0xF373/$F373) [Constant]
#ifndef _PRINT_STR_HWYX
#define _PRINT_STR_HWYX 62323
#endif

// Decimal 62328 (0xF378/$F378) [Constant]
#ifndef _PRINT_STR_YX
#define _PRINT_STR_YX 62328
#endif

// Decimal 62330 (0xF37A/$F37A) [Constant]
#ifndef _PRINT_STR_D
#define _PRINT_STR_D 62330
#endif

// Decimal 62341 (0xF385/$F385) [Constant]
#ifndef _PRINT_LIST_HW
#define _PRINT_LIST_HW 62341
#endif

// Decimal 62346 (0xF38A/$F38A) [Constant]
#ifndef _PRINT_LIST
#define _PRINT_LIST 62346
#endif

// Decimal 62348 (0xF38C/$F38C) [Constant]
#ifndef _PRINT_LIST_CHK
#define _PRINT_LIST_CHK 62348
#endif

// Decimal 62353 (0xF391/$F391) [Constant]
#ifndef _PRINT_SHIPS_X
#define _PRINT_SHIPS_X 62353
#endif

// Decimal 62355 (0xF393/$F393) [Constant]
#ifndef _PRINT_SHIPS
#define _PRINT_SHIPS 62355
#endif

// Decimal 62381 (0xF3AD/$F3AD) [Constant] - count y x y x ...
#ifndef _MOV_DRAW_VLC_A
#define _MOV_DRAW_VLC_A 62381
#endif

// Decimal 62385 (0xF3B1/$F3B1) [Constant] - y x y x ...
#ifndef _MOV_DRAW_VL_B
#define _MOV_DRAW_VL_B 62385
#endif

// Decimal 62389 (0xF3B5/$F3B5) [Constant] - count scale y x y x ...
#ifndef _MOV_DRAW_VLCS
#define _MOV_DRAW_VLCS 62389
#endif

// Decimal 62391 (0xF3B7/$F3B7) [Constant] - y x y x ...
#ifndef _MOV_DRAW_VL_AB
#define _MOV_DRAW_VL_AB 62391
#endif

// Decimal 62393 (0xF3B9/$F3B9) [Constant] - y x y x ...
#ifndef _MOV_DRAW_VL_A
#define _MOV_DRAW_VL_A 62393
#endif

// Decimal 62396 (0xF3BC/$F3BC) [Constant] - y x y x ...
#ifndef _MOV_DRAW_VL
#define _MOV_DRAW_VL 62396
#endif

// Decimal 62398 (0xF3BE/$F3BE) [Constant] - y x y x ...
#ifndef _MOV_DRAW_VL_D
#define _MOV_DRAW_VL_D 62398
#endif

// Decimal 62414 (0xF3CE/$F3CE) [Constant] - count y x y x ...
#ifndef _DRAW_VLC
#define _DRAW_VLC 62414
#endif

// Decimal 62418 (0xF3D2/$F3D2) [Constant] - y x y x ...
#ifndef _DRAW_VL_B
#define _DRAW_VL_B 62418
#endif

// Decimal 62422 (0xF3D6/$F3D6) [Constant] - count scale y x y x ...
#ifndef _DRAW_VLCS
#define _DRAW_VLCS 62422
#endif

// Decimal 62424 (0xF3D8/$F3D8) [Constant] - y x y x ...
#ifndef _DRAW_VL_AB
#define _DRAW_VL_AB 62424
#endif

// Decimal 62426 (0xF3DA/$F3DA) [Constant] - y x y x ...
#ifndef _DRAW_VL_A
#define _DRAW_VL_A 62426
#endif

// Decimal 62429 (0xF3DD/$F3DD) [Constant] - y x y x ...
#ifndef _DRAW_VL
#define _DRAW_VL 62429
#endif

// Decimal 62431 (0xF3DF/$F3DF) [Constant] - y x y x ...
#ifndef _DRAW_LINE_D
#define _DRAW_LINE_D 62431
#endif

// Decimal 62468 (0xF404/$F404) [Constant] - pattern y x pattern y x ... 0x01
#ifndef _DRAW_VLP_FF
#define _DRAW_VLP_FF 62468
#endif

// Decimal 62472 (0xF408/$F408) [Constant] - pattern y x pattern y x ... 0x01
#ifndef _DRAW_VLP_7F
#define _DRAW_VLP_7F 62472
#endif

// Decimal 62476 (0xF40C/$F40C) [Constant] - scale pattern y x pattern y x ... 0x01
#ifndef _DRAW_VLP_SCALE
#define _DRAW_VLP_SCALE 62476
#endif

// Decimal 62478 (0xF40E/$F40E) [Constant] - pattern y x pattern y x ... 0x01
#ifndef _DRAW_VLP_B
#define _DRAW_VLP_B 62478
#endif

// Decimal 62480 (0xF410/$F410) [Constant] - pattern y x pattern y x ... 0x01
#ifndef _DRAW_VLP
#define _DRAW_VLP 62480
#endif

// Decimal 62516 (0xF434/$F434) [Constant] - y x y x ...
#ifndef _DRAW_PAT_VL_A
#define _DRAW_PAT_VL_A 62516
#endif

// Decimal 62519 (0xF437/$F437) [Constant] - y x y x ...
#ifndef _DRAW_PAT_VL
#define _DRAW_PAT_VL 62519
#endif

// Decimal 62521 (0xF439/$F439) [Constant] - y x y x ...
#ifndef _DRAW_PAT_VL_D
#define _DRAW_PAT_VL_D 62521
#endif

// Decimal 62574 (0xF46E/$F46E) [Constant] - mode y x mode y x ... 0x01
#ifndef _DRAW_VL_MODE
#define _DRAW_VL_MODE 62574
#endif

// Decimal 62613 (0xF495/$F495) [Constant]
#ifndef _PRINT_STR
#define _PRINT_STR 62613
#endif

// Decimal 62737 (0xF511/$F511) [Constant]
#ifndef _RANDOM_3
#define _RANDOM_3 62737
#endif

// Decimal 62743 (0xF517/$F517) [Constant]
#ifndef _RANDOM
#define _RANDOM 62743
#endif

// Decimal 62771 (0xF533/$F533) [Constant]
#ifndef _INIT_MUSIC_BUF
#define _INIT_MUSIC_BUF 62771
#endif

// Decimal 62783 (0xF53F/$F53F) [Constant]
#ifndef _CLEAR_X_B
#define _CLEAR_X_B 62783
#endif

// Decimal 62786 (0xF542/$F542) [Constant] - never used by GCE carts?
#ifndef _CLEAR_C8_RAM
#define _CLEAR_C8_RAM 62786
#endif

// Decimal 62789 (0xF545/$F545) [Constant]
#ifndef _CLEAR_X_256
#define _CLEAR_X_256 62789
#endif

// Decimal 62792 (0xF548/$F548) [Constant]
#ifndef _CLEAR_X_D
#define _CLEAR_X_D 62792
#endif

// Decimal 62800 (0xF550/$F550) [Constant]
#ifndef _CLEAR_X_B_80
#define _CLEAR_X_B_80 62800
#endif

// Decimal 62802 (0xF552/$F552) [Constant]
#ifndef _CLEAR_X_B_A
#define _CLEAR_X_B_A 62802
#endif

// Decimal 62810 (0xF55A/$F55A) [Constant]
#ifndef _DEC_3_COUNTERS
#define _DEC_3_COUNTERS 62810
#endif

// Decimal 62814 (0xF55E/$F55E) [Constant]
#ifndef _DEC_6_COUNTERS
#define _DEC_6_COUNTERS 62814
#endif

// Decimal 62819 (0xF563/$F563) [Constant]
#ifndef _DEC_COUNTERS
#define _DEC_COUNTERS 62819
#endif

// Decimal 62829 (0xF56D/$F56D) [Constant] - 30 cycles
#ifndef _DELAY_3
#define _DELAY_3 62829
#endif

// Decimal 62833 (0xF571/$F571) [Constant] - 25 cycles
#ifndef _DELAY_2
#define _DELAY_2 62833
#endif

// Decimal 62837 (0xF575/$F575) [Constant] - 20 cycles
#ifndef _DELAY_1
#define _DELAY_1 62837
#endif

// Decimal 62841 (0xF579/$F579) [Constant] - 12 cycles
#ifndef _DELAY_0
#define _DELAY_0 62841
#endif

// Decimal 62842 (0xF57A/$F57A) [Constant] - 5*B + 10 cycles
#ifndef _DELAY_B
#define _DELAY_B 62842
#endif

// Decimal 62845 (0xF57D/$F57D) [Constant] - 5 cycles
#ifndef _DELAY_RTS
#define _DELAY_RTS 62845
#endif

// Decimal 62846 (0xF57E/$F57E) [Constant]
#ifndef _BITMASK_A
#define _BITMASK_A 62846
#endif

// Decimal 62852 (0xF584/$F584) [Constant]
#ifndef _ABS_A_B
#define _ABS_A_B 62852
#endif

// Decimal 62859 (0xF58B/$F58B) [Constant]
#ifndef _ABS_B
#define _ABS_B 62859
#endif

// Decimal 62867 (0xF593/$F593) [Constant]
#ifndef _RISE_RUN_ANGLE
#define _RISE_RUN_ANGLE 62867
#endif

// Decimal 62937 (0xF5D9/$F5D9) [Constant]
#ifndef _GET_RISE_IDX
#define _GET_RISE_IDX 62937
#endif

// Decimal 62939 (0xF5DB/$F5DB) [Constant]
#ifndef _GET_RUN_IDX
#define _GET_RUN_IDX 62939
#endif

// Decimal 62959 (0xF5EF/$F5EF) [Constant]
#ifndef _GET_RISE_RUN
#define _GET_RISE_RUN 62959
#endif

// Decimal 62975 (0xF5FF/$F5FF) [Constant]
#ifndef _RISE_RUN_X
#define _RISE_RUN_X 62975
#endif

// Decimal 62977 (0xF601/$F601) [Constant]
#ifndef _RISE_RUN_Y
#define _RISE_RUN_Y 62977
#endif

// Decimal 62979 (0xF603/$F603) [Constant]
#ifndef _RISE_RUN_LEN
#define _RISE_RUN_LEN 62979
#endif

// Decimal 62992 (0xF610/$F610) [Constant]
#ifndef _ROT_VL_AB
#define _ROT_VL_AB 62992
#endif

// Decimal 62998 (0xF616/$F616) [Constant]
#ifndef _ROT_VL
#define _ROT_VL 62998
#endif

// Decimal 63007 (0xF61F/$F61F) [Constant]
#ifndef _ROT_VL_MODE_A
#define _ROT_VL_MODE_A 63007
#endif

// Decimal 63019 (0xF62B/$F62B) [Constant]
#ifndef _ROT_VL_MODE
#define _ROT_VL_MODE 63019
#endif

// Decimal 63031 (0xF637/$F637) [Constant]
#ifndef _ROT_VL_DFT
#define _ROT_VL_DFT 63031
#endif

// Decimal 63067 (0xF65B/$F65B) [Constant]
#ifndef _XFORM_RUN_A
#define _XFORM_RUN_A 63067
#endif

// Decimal 63069 (0xF65D/$F65D) [Constant]
#ifndef _XFORM_RUN
#define _XFORM_RUN 63069
#endif

// Decimal 63073 (0xF661/$F661) [Constant]
#ifndef _XFORM_RISE_A
#define _XFORM_RISE_A 63073
#endif

// Decimal 63075 (0xF663/$F663) [Constant]
#ifndef _XFORM_RISE
#define _XFORM_RISE 63075
#endif

// Decimal 63103 (0xF67F/$F67F) [Constant]
#ifndef _MOVE_MEM_A_1
#define _MOVE_MEM_A_1 63103
#endif

// Decimal 63107 (0xF683/$F683) [Constant]
#ifndef _MOVE_MEM_A
#define _MOVE_MEM_A 63107
#endif

// Decimal 63111 (0xF687/$F687) [Constant]
#ifndef _INIT_MUSIC_CHK
#define _INIT_MUSIC_CHK 63111
#endif

// Decimal 63117 (0xF68D/$F68D) [Constant]
#ifndef _INIT_MUSIC
#define _INIT_MUSIC 63117
#endif

// Decimal 63122 (0xF692/$F692) [Constant]
#ifndef _INIT_MUSIC_X
#define _INIT_MUSIC_X 63122
#endif

// Decimal 63401 (0xF7A9/$F7A9) [Constant]
#ifndef _SELECT_GAME
#define _SELECT_GAME 63401
#endif

// Decimal 63567 (0xF84F/$F84F) [Constant]
#ifndef _CLEAR_SCORE
#define _CLEAR_SCORE 63567
#endif

// Decimal 63582 (0xF85E/$F85E) [Constant]
#ifndef _ADD_SCORE_A
#define _ADD_SCORE_A 63582
#endif

// Decimal 63612 (0xF87C/$F87C) [Constant]
#ifndef _ADD_SCORE_D
#define _ADD_SCORE_D 63612
#endif

// Decimal 63671 (0xF8B7/$F8B7) [Constant]
#ifndef _STRIP_ZEROS
#define _STRIP_ZEROS 63671
#endif

// Decimal 63687 (0xF8C7/$F8C7) [Constant]
#ifndef _COMPARE_SCORE
#define _COMPARE_SCORE 63687
#endif

// Decimal 63704 (0xF8D8/$F8D8) [Constant]
#ifndef _NEW_HIGH_SCORE
#define _NEW_HIGH_SCORE 63704
#endif

// Decimal 63717 (0xF8E5/$F8E5) [Constant]
#ifndef _OBJ_WILL_HIT_U
#define _OBJ_WILL_HIT_U 63717
#endif

// Decimal 63731 (0xF8F3/$F8F3) [Constant]
#ifndef _OBJ_WILL_HIT
#define _OBJ_WILL_HIT 63731
#endif

// Decimal 63743 (0xF8FF/$F8FF) [Constant]
#ifndef _OBJ_HIT
#define _OBJ_HIT 63743
#endif

// Decimal 63790 (0xF92E/$F92E) [Constant]
#ifndef _EXPLOSION_SND
#define _EXPLOSION_SND 63790
#endif

// Decimal 65439 (0xFF9F/$FF9F) [Constant]
#ifndef _DRAW_GRID_VL
#define _DRAW_GRID_VL 65439
#endif

// Decimal 63988 (0xF9F4/$F9F4) [Constant] - Char_Table
#ifndef _CHAR_TABLE
#define _CHAR_TABLE 63988
#endif

// Decimal 64468 (0xFBD4/$FBD4) [Constant] - Char_Table_End
#ifndef _CHAR_TABLE_END
#define _CHAR_TABLE_END 64468
#endif

// Decimal 64781 (0xFD0D/$FD0D) [Constant] - Poweron music, crazy coaster and narrow escape
#ifndef _VX_MUSIC_1
#define _VX_MUSIC_1 64781
#endif

// Decimal 64797 (0xFD1D/$FD1D) [Constant] - Music for Berzerk
#ifndef _VX_MUSIC_2
#define _VX_MUSIC_2 64797
#endif

// Decimal 64897 (0xFD81/$FD81) [Constant]
#ifndef _VX_MUSIC_3
#define _VX_MUSIC_3 64897
#endif

// Decimal 64979 (0xFDD3/$FDD3) [Constant] - Music for Scramble
#ifndef _VX_MUSIC_4
#define _VX_MUSIC_4 64979
#endif

// Decimal 65080 (0xFE38/$FE38) [Constant] - Music for Solar Quest
#ifndef _VX_MUSIC_5
#define _VX_MUSIC_5 65080
#endif

// Decimal 65142 (0xFE76/$FE76) [Constant]
#ifndef _VX_MUSIC_6
#define _VX_MUSIC_6 65142
#endif

// Decimal 65222 (0xFEC6/$FEC6) [Constant]
#ifndef _VX_MUSIC_7
#define _VX_MUSIC_7 65222
#endif

// Decimal 65272 (0xFEF8/$FEF8) [Constant] - Music for Melody Master
#ifndef _VX_MUSIC_8
#define _VX_MUSIC_8 65272
#endif

// Decimal 65318 (0xFF26/$FF26) [Constant]
#ifndef _VX_MUSIC_9
#define _VX_MUSIC_9 65318
#endif

// Decimal 65348 (0xFF44/$FF44) [Constant]
#ifndef _VX_MUSIC_10
#define _VX_MUSIC_10 65348
#endif

// Decimal 65378 (0xFF62/$FF62) [Constant]
#ifndef _VX_MUSIC_11
#define _VX_MUSIC_11 65378
#endif

// Decimal 65402 (0xFF7A/$FF7A) [Constant]
#ifndef _VX_MUSIC_12
#define _VX_MUSIC_12 65402
#endif

// Decimal 65423 (0xFF8F/$FF8F) [Constant]
#ifndef _VX_MUSIC_13
#define _VX_MUSIC_13 65423
#endif


#endif
