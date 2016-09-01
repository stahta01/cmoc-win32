
// This file was created by the WinCMOC compiler
// Created: 1/09/2016 10:53:13
// WinCMOC:  https://sourceforge.net/projects/cmoc-win32/
// CMOC:     http://perso.b2b2c.ca/~sarrazip/dev/cmoc.html

// Translated from "vectrexbios.asm"
//
// This file is in the public domain

#ifndef _VECTREX_VECTREXBIOS_H
#define _VECTREX_VECTREXBIOS_H

// Shadow of sound chip registers (15 bytes)
#ifndef _VEC_SND_SHADOW
#define _VEC_SND_SHADOW 51200
#endif

// Current state of all joystick buttons
#ifndef _VEC_BTN_STATE
#define _VEC_BTN_STATE 51215
#endif

// Previous state of all joystick buttons
#ifndef _VEC_PREV_BTNS
#define _VEC_PREV_BTNS 51216
#endif

// Current toggle state of all buttons
#ifndef _VEC_BUTTONS
#define _VEC_BUTTONS 51217
#endif

// Current toggle state of stick 1 button 1
#ifndef _VEC_BUTTON_1_1
#define _VEC_BUTTON_1_1 51218
#endif

// Current toggle state of stick 1 button 2
#ifndef _VEC_BUTTON_1_2
#define _VEC_BUTTON_1_2 51219
#endif

// Current toggle state of stick 1 button 3
#ifndef _VEC_BUTTON_1_3
#define _VEC_BUTTON_1_3 51220
#endif

// Current toggle state of stick 1 button 4
#ifndef _VEC_BUTTON_1_4
#define _VEC_BUTTON_1_4 51221
#endif

// Current toggle state of stick 2 button 1
#ifndef _VEC_BUTTON_2_1
#define _VEC_BUTTON_2_1 51222
#endif

// Current toggle state of stick 2 button 2
#ifndef _VEC_BUTTON_2_2
#define _VEC_BUTTON_2_2 51223
#endif

// Current toggle state of stick 2 button 3
#ifndef _VEC_BUTTON_2_3
#define _VEC_BUTTON_2_3 51224
#endif

// Current toggle state of stick 2 button 4
#ifndef _VEC_BUTTON_2_4
#define _VEC_BUTTON_2_4 51225
#endif

// Joystick A/D resolution (0x80=min 0x00=max)
#ifndef _VEC_JOY_RESLTN
#define _VEC_JOY_RESLTN 51226
#endif

// Joystick 1 left/right
#ifndef _VEC_JOY_1_X
#define _VEC_JOY_1_X 51227
#endif

// Joystick 1 up/down
#ifndef _VEC_JOY_1_Y
#define _VEC_JOY_1_Y 51228
#endif

// Joystick 2 left/right
#ifndef _VEC_JOY_2_X
#define _VEC_JOY_2_X 51229
#endif

// Joystick 2 up/down
#ifndef _VEC_JOY_2_Y
#define _VEC_JOY_2_Y 51230
#endif

// Joystick enable/mux flags (4 bytes)
#ifndef _VEC_JOY_MUX
#define _VEC_JOY_MUX 51231
#endif

// Joystick 1 X enable/mux flag (=1)
#ifndef _VEC_JOY_MUX_1_X
#define _VEC_JOY_MUX_1_X 51231
#endif

// Joystick 1 Y enable/mux flag (=3)
#ifndef _VEC_JOY_MUX_1_Y
#define _VEC_JOY_MUX_1_Y 51232
#endif

// Joystick 2 X enable/mux flag (=5)
#ifndef _VEC_JOY_MUX_2_X
#define _VEC_JOY_MUX_2_X 51233
#endif

// Joystick 2 Y enable/mux flag (=7)
#ifndef _VEC_JOY_MUX_2_Y
#define _VEC_JOY_MUX_2_Y 51234
#endif

// Misc counter/flag byte, zero when not in use
#ifndef _VEC_MISC_COUNT
#define _VEC_MISC_COUNT 51235
#endif

// Check0Ref enable flag
#ifndef _VEC_0REF_ENABLE
#define _VEC_0REF_ENABLE 51236
#endif

// Loop counter word (incremented in Wait_Recal)
#ifndef _VEC_LOOP_COUNT
#define _VEC_LOOP_COUNT 51237
#endif

// Default brightness
#ifndef _VEC_BRIGHTNESS
#define _VEC_BRIGHTNESS 51239
#endif

// Dot dwell time?
#ifndef _VEC_DOT_DWELL
#define _VEC_DOT_DWELL 51240
#endif

// Dot pattern (bits)
#ifndef _VEC_PATTERN
#define _VEC_PATTERN 51241
#endif

// Default text height and width
#ifndef _VEC_TEXT_HW
#define _VEC_TEXT_HW 51242
#endif

// Default text height
#ifndef _VEC_TEXT_HEIGHT
#define _VEC_TEXT_HEIGHT 51242
#endif

// Default text width
#ifndef _VEC_TEXT_WIDTH
#define _VEC_TEXT_WIDTH 51243
#endif

// Temporary string pointer for Print_Str
#ifndef _VEC_STR_PTR
#define _VEC_STR_PTR 51244
#endif

// Six bytes of counters
#ifndef _VEC_COUNTERS
#define _VEC_COUNTERS 51246
#endif

// First  counter byte
#ifndef _VEC_COUNTER_1
#define _VEC_COUNTER_1 51246
#endif

// Second counter byte
#ifndef _VEC_COUNTER_2
#define _VEC_COUNTER_2 51247
#endif

// Third  counter byte
#ifndef _VEC_COUNTER_3
#define _VEC_COUNTER_3 51248
#endif

// Fourth counter byte
#ifndef _VEC_COUNTER_4
#define _VEC_COUNTER_4 51249
#endif

// Fifth  counter byte
#ifndef _VEC_COUNTER_5
#define _VEC_COUNTER_5 51250
#endif

// Sixth  counter byte
#ifndef _VEC_COUNTER_6
#define _VEC_COUNTER_6 51251
#endif

// Temp storage word for rise/run
#ifndef _VEC_RISERUN_TMP
#define _VEC_RISERUN_TMP 51252
#endif

// Angle for rise/run and rotation calculations
#ifndef _VEC_ANGLE
#define _VEC_ANGLE 51254
#endif

// Index pair for run
#ifndef _VEC_RUN_INDEX
#define _VEC_RUN_INDEX 51255
#endif

// Index pair for rise
#ifndef _VEC_RISE_INDEX
#define _VEC_RISE_INDEX 51257
#endif

// length for rise/run
#ifndef _VEC_RISERUN_LEN
#define _VEC_RISERUN_LEN 51259
#endif

// Refresh time (divided by 1.5MHz)
#ifndef _VEC_RFRSH
#define _VEC_RFRSH 51261
#endif

// Refresh time low byte
#ifndef _VEC_RFRSH_LO
#define _VEC_RFRSH_LO 51261
#endif

// Refresh time high byte
#ifndef _VEC_RFRSH_HI
#define _VEC_RFRSH_HI 51262
#endif

// Music work buffer (14 bytes, backwards?)
#ifndef _VEC_MUSIC_WORK
#define _VEC_MUSIC_WORK 51263
#endif

// register 10
#ifndef _VEC_MUSIC_WK_A
#define _VEC_MUSIC_WK_A 51266
#endif

// register 7
#ifndef _VEC_MUSIC_WK_7
#define _VEC_MUSIC_WK_7 51269
#endif

// register 6
#ifndef _VEC_MUSIC_WK_6
#define _VEC_MUSIC_WK_6 51270
#endif

// register 5
#ifndef _VEC_MUSIC_WK_5
#define _VEC_MUSIC_WK_5 51271
#endif

// register 1
#ifndef _VEC_MUSIC_WK_1
#define _VEC_MUSIC_WK_1 51275
#endif

// Pointer to note-to-fr.EQUency table (normally 0xFC8D)
#ifndef _VEC_FREQ_TABLE
#define _VEC_FREQ_TABLE 51277
#endif

// Maximum number of players for Select_Game
#ifndef _VEC_MAX_PLAYERS
#define _VEC_MAX_PLAYERS 51279
#endif

// Maximum number of games for Select_Game
#ifndef _VEC_MAX_GAMES
#define _VEC_MAX_GAMES 51280
#endif

// Storage for first music header word (ADSR table)
#ifndef _VEC_ADSR_TABLE
#define _VEC_ADSR_TABLE 51279
#endif

// Storage for second music header word ('twang' table)
#ifndef _VEC_TWANG_TABLE
#define _VEC_TWANG_TABLE 51281
#endif

// Music data pointer
#ifndef _VEC_MUSIC_PTR
#define _VEC_MUSIC_PTR 51283
#endif

// Used by Explosion_Snd - bit for first channel used?
#ifndef _VEC_EXPL_CHANA
#define _VEC_EXPL_CHANA 51283
#endif

// Used by Explosion_Snd - bits for all channels used?
#ifndef _VEC_EXPL_CHANS
#define _VEC_EXPL_CHANS 51284
#endif

// Current sound channel number for Init_Music
#ifndef _VEC_MUSIC_CHAN
#define _VEC_MUSIC_CHAN 51285
#endif

// Music active flag (0x00=off 0x01=start 0x80=on)
#ifndef _VEC_MUSIC_FLAG
#define _VEC_MUSIC_FLAG 51286
#endif

// Duration counter for Init_Music
#ifndef _VEC_DURATION
#define _VEC_DURATION 51287
#endif

// 3 word 'twang' table used by Init_Music
#ifndef _VEC_MUSIC_TWANG
#define _VEC_MUSIC_TWANG 51288
#endif

// Four bytes copied from Explosion_Snds U-reg parameters
#ifndef _VEC_EXPL_1
#define _VEC_EXPL_1 51288
#endif

#ifndef _VEC_EXPL_2
#define _VEC_EXPL_2 51289
#endif

#ifndef _VEC_EXPL_3
#define _VEC_EXPL_3 51290
#endif

#ifndef _VEC_EXPL_4
#define _VEC_EXPL_4 51291
#endif

// Used by Explosion_Snd - channel number in use?
#ifndef _VEC_EXPL_CHAN
#define _VEC_EXPL_CHAN 51292
#endif

// Used by Explosion_Snd - bit for second channel used?
#ifndef _VEC_EXPL_CHANB
#define _VEC_EXPL_CHANB 51293
#endif

// ADSR timers for each sound channel (3 bytes)
#ifndef _VEC_ADSR_TIMERS
#define _VEC_ADSR_TIMERS 51294
#endif

// Storage for base fr.EQUency of each channel (3 words)
#ifndef _VEC_MUSIC_FREQ
#define _VEC_MUSIC_FREQ 51297
#endif

// Explosion_Snd initialization flag?
#ifndef _VEC_EXPL_FLAG
#define _VEC_EXPL_FLAG 51303
#endif

// Used by Explosion_Snd
#ifndef _VEC_EXPL_TIMER
#define _VEC_EXPL_TIMER 51319
#endif

// Number of players selected in Select_Game
#ifndef _VEC_NUM_PLAYERS
#define _VEC_NUM_PLAYERS 51321
#endif

// Game number selected in Select_Game
#ifndef _VEC_NUM_GAME
#define _VEC_NUM_GAME 51322
#endif

// Pointer to 3-byte random number seed (=0xC87D)
#ifndef _VEC_SEED_PTR
#define _VEC_SEED_PTR 51323
#endif

// Default 3-byte random number seed
#ifndef _VEC_RANDOM_SEED
#define _VEC_RANDOM_SEED 51325
#endif

// Default top-of-stack
#ifndef _VEC_DEFAULT_STK
#define _VEC_DEFAULT_STK 52202
#endif

// High score storage (7 bytes)
#ifndef _VEC_HIGH_SCORE
#define _VEC_HIGH_SCORE 52203
#endif

// SWI2/SWI3 interrupt vector (3 bytes)
#ifndef _VEC_SWI3_VECTOR
#define _VEC_SWI3_VECTOR 52210
#endif

// SWI2/SWI3 interrupt vector (3 bytes)
#ifndef _VEC_SWI2_VECTOR
#define _VEC_SWI2_VECTOR 52210
#endif

// FIRQ interrupt vector (3 bytes)
#ifndef _VEC_FIRQ_VECTOR
#define _VEC_FIRQ_VECTOR 52213
#endif

// IRQ interrupt vector (3 bytes)
#ifndef _VEC_IRQ_VECTOR
#define _VEC_IRQ_VECTOR 52216
#endif

// SWI/NMI interrupt vector (3 bytes)
#ifndef _VEC_SWI_VECTOR
#define _VEC_SWI_VECTOR 52219
#endif

// SWI/NMI interrupt vector (3 bytes)
#ifndef _VEC_NMI_VECTOR
#define _VEC_NMI_VECTOR 52219
#endif

// Cold start flag (warm start if = 0x7321)
#ifndef _VEC_COLD_FLAG
#define _VEC_COLD_FLAG 52222
#endif

// VIA port B data I/O register
#ifndef _VIA_PORT_B
#define _VIA_PORT_B 53248
#endif

// VIA port A data I/O register (handshaking)
#ifndef _VIA_PORT_A
#define _VIA_PORT_A 53249
#endif

// VIA port B data direction register (0=input 1=output)
#ifndef _VIA_DDR_B
#define _VIA_DDR_B 53250
#endif

// VIA port A data direction register (0=input 1=output)
#ifndef _VIA_DDR_A
#define _VIA_DDR_A 53251
#endif

// VIA timer 1 count register lo (scale factor)
#ifndef _VIA_T1_CNT_LO
#define _VIA_T1_CNT_LO 53252
#endif

// VIA timer 1 count register hi
#ifndef _VIA_T1_CNT_HI
#define _VIA_T1_CNT_HI 53253
#endif

// VIA timer 1 latch register lo
#ifndef _VIA_T1_LCH_LO
#define _VIA_T1_LCH_LO 53254
#endif

// VIA timer 1 latch register hi
#ifndef _VIA_T1_LCH_HI
#define _VIA_T1_LCH_HI 53255
#endif

// VIA timer 2 count/latch register lo (refresh)
#ifndef _VIA_T2_LO
#define _VIA_T2_LO 53256
#endif

// VIA timer 2 count/latch register hi
#ifndef _VIA_T2_HI
#define _VIA_T2_HI 53257
#endif

// VIA shift register
#ifndef _VIA_SHIFT_REG
#define _VIA_SHIFT_REG 53258
#endif

// VIA auxiliary control register
#ifndef _VIA_AUX_CNTL
#define _VIA_AUX_CNTL 53259
#endif

// VIA control register
#ifndef _VIA_CNTL
#define _VIA_CNTL 53260
#endif

// VIA interrupt flags register
#ifndef _VIA_INT_FLAGS
#define _VIA_INT_FLAGS 53261
#endif

// VIA interrupt enable register
#ifndef _VIA_INT_ENABLE
#define _VIA_INT_ENABLE 53262
#endif

// VIA port A data I/O register (no handshaking)
#ifndef _VIA_PORT_A_NOHS
#define _VIA_PORT_A_NOHS 53263
#endif

#ifndef _COLD_START
#define _COLD_START 61440
#endif

#ifndef _WARM_START
#define _WARM_START 61548
#endif

#ifndef _INIT_VIA
#define _INIT_VIA 61772
#endif

#ifndef _INIT_OS_RAM
#define _INIT_OS_RAM 61796
#endif

#ifndef _INIT_OS
#define _INIT_OS 61835
#endif

#ifndef _WAIT_RECAL
#define _WAIT_RECAL 61842
#endif

#ifndef _SET_REFRESH
#define _SET_REFRESH 61858
#endif

#ifndef _DP_TO_D0
#define _DP_TO_D0 61866
#endif

#ifndef _DP_TO_C8
#define _DP_TO_C8 61871
#endif

#ifndef _READ_BTNS_MASK
#define _READ_BTNS_MASK 61876
#endif

#ifndef _READ_BTNS
#define _READ_BTNS 61882
#endif

#ifndef _JOY_ANALOG
#define _JOY_ANALOG 61941
#endif

#ifndef _JOY_DIGITAL
#define _JOY_DIGITAL 61944
#endif

#ifndef _SOUND_BYTE
#define _SOUND_BYTE 62038
#endif

#ifndef _SOUND_BYTE_X
#define _SOUND_BYTE_X 62041
#endif

#ifndef _SOUND_BYTE_RAW
#define _SOUND_BYTE_RAW 62043
#endif

#ifndef _CLEAR_SOUND
#define _CLEAR_SOUND 62066
#endif

#ifndef _SOUND_BYTES
#define _SOUND_BYTES 62077
#endif

#ifndef _SOUND_BYTES_X
#define _SOUND_BYTES_X 62084
#endif

#ifndef _DO_SOUND
#define _DO_SOUND 62089
#endif

#ifndef _DO_SOUND_X
#define _DO_SOUND_X 62092
#endif

#ifndef _INTENSITY_1F
#define _INTENSITY_1F 62109
#endif

#ifndef _INTENSITY_3F
#define _INTENSITY_3F 62113
#endif

#ifndef _INTENSITY_5F
#define _INTENSITY_5F 62117
#endif

#ifndef _INTENSITY_7F
#define _INTENSITY_7F 62121
#endif

#ifndef _INTENSITY_A
#define _INTENSITY_A 62123
#endif

#ifndef _DOT_IX_B
#define _DOT_IX_B 62142
#endif

#ifndef _DOT_IX
#define _DOT_IX 62145
#endif

#ifndef _DOT_D
#define _DOT_D 62147
#endif

#ifndef _DOT_HERE
#define _DOT_HERE 62149
#endif

#ifndef _DOT_LIST
#define _DOT_LIST 62165
#endif

#ifndef _DOT_LIST_RESET
#define _DOT_LIST_RESET 62174
#endif

#ifndef _RECALIBRATE
#define _RECALIBRATE 62182
#endif

#ifndef _MOVETO_X_7F
#define _MOVETO_X_7F 62194
#endif

#ifndef _MOVETO_D_7F
#define _MOVETO_D_7F 62204
#endif

#ifndef _MOVETO_IX_FF
#define _MOVETO_IX_FF 62216
#endif

#ifndef _MOVETO_IX_7F
#define _MOVETO_IX_7F 62220
#endif

// Used to be named Moveto_ix_a but this is wrong.
#ifndef _MOVETO_IX_B
#define _MOVETO_IX_B 62222
#endif

#ifndef _MOVETO_IX
#define _MOVETO_IX 62224
#endif

#ifndef _MOVETO_D
#define _MOVETO_D 62226
#endif

#ifndef _RESET0REF_D0
#define _RESET0REF_D0 62282
#endif

#ifndef _CHECK0REF
#define _CHECK0REF 62287
#endif

#ifndef _RESET0REF
#define _RESET0REF 62292
#endif

#ifndef _RESET_PEN
#define _RESET_PEN 62299
#endif

#ifndef _RESET0INT
#define _RESET0INT 62315
#endif

#ifndef _PRINT_STR_HWYX
#define _PRINT_STR_HWYX 62323
#endif

#ifndef _PRINT_STR_YX
#define _PRINT_STR_YX 62328
#endif

#ifndef _PRINT_STR_D
#define _PRINT_STR_D 62330
#endif

#ifndef _PRINT_LIST_HW
#define _PRINT_LIST_HW 62341
#endif

#ifndef _PRINT_LIST
#define _PRINT_LIST 62346
#endif

#ifndef _PRINT_LIST_CHK
#define _PRINT_LIST_CHK 62348
#endif

#ifndef _PRINT_SHIPS_X
#define _PRINT_SHIPS_X 62353
#endif

#ifndef _PRINT_SHIPS
#define _PRINT_SHIPS 62355
#endif

// count y x y x ...
#ifndef _MOV_DRAW_VLC_A
#define _MOV_DRAW_VLC_A 62381
#endif

// y x y x ...
#ifndef _MOV_DRAW_VL_B
#define _MOV_DRAW_VL_B 62385
#endif

// count scale y x y x ...
#ifndef _MOV_DRAW_VLCS
#define _MOV_DRAW_VLCS 62389
#endif

// y x y x ...
#ifndef _MOV_DRAW_VL_AB
#define _MOV_DRAW_VL_AB 62391
#endif

// y x y x ...
#ifndef _MOV_DRAW_VL_A
#define _MOV_DRAW_VL_A 62393
#endif

// y x y x ...
#ifndef _MOV_DRAW_VL
#define _MOV_DRAW_VL 62396
#endif

// y x y x ...
#ifndef _MOV_DRAW_VL_D
#define _MOV_DRAW_VL_D 62398
#endif

// count y x y x ...
#ifndef _DRAW_VLC
#define _DRAW_VLC 62414
#endif

// y x y x ...
#ifndef _DRAW_VL_B
#define _DRAW_VL_B 62418
#endif

// count scale y x y x ...
#ifndef _DRAW_VLCS
#define _DRAW_VLCS 62422
#endif

// y x y x ...
#ifndef _DRAW_VL_AB
#define _DRAW_VL_AB 62424
#endif

// y x y x ...
#ifndef _DRAW_VL_A
#define _DRAW_VL_A 62426
#endif

// y x y x ...
#ifndef _DRAW_VL
#define _DRAW_VL 62429
#endif

// y x y x ...
#ifndef _DRAW_LINE_D
#define _DRAW_LINE_D 62431
#endif

// pattern y x pattern y x ... 0x01
#ifndef _DRAW_VLP_FF
#define _DRAW_VLP_FF 62468
#endif

// pattern y x pattern y x ... 0x01
#ifndef _DRAW_VLP_7F
#define _DRAW_VLP_7F 62472
#endif

// scale pattern y x pattern y x ... 0x01
#ifndef _DRAW_VLP_SCALE
#define _DRAW_VLP_SCALE 62476
#endif

// pattern y x pattern y x ... 0x01
#ifndef _DRAW_VLP_B
#define _DRAW_VLP_B 62478
#endif

// pattern y x pattern y x ... 0x01
#ifndef _DRAW_VLP
#define _DRAW_VLP 62480
#endif

// y x y x ...
#ifndef _DRAW_PAT_VL_A
#define _DRAW_PAT_VL_A 62516
#endif

// y x y x ...
#ifndef _DRAW_PAT_VL
#define _DRAW_PAT_VL 62519
#endif

// y x y x ...
#ifndef _DRAW_PAT_VL_D
#define _DRAW_PAT_VL_D 62521
#endif

// mode y x mode y x ... 0x01
#ifndef _DRAW_VL_MODE
#define _DRAW_VL_MODE 62574
#endif

#ifndef _PRINT_STR
#define _PRINT_STR 62613
#endif

#ifndef _RANDOM_3
#define _RANDOM_3 62737
#endif

#ifndef _RANDOM
#define _RANDOM 62743
#endif

#ifndef _INIT_MUSIC_BUF
#define _INIT_MUSIC_BUF 62771
#endif

#ifndef _CLEAR_X_B
#define _CLEAR_X_B 62783
#endif

// never used by GCE carts?
#ifndef _CLEAR_C8_RAM
#define _CLEAR_C8_RAM 62786
#endif

#ifndef _CLEAR_X_256
#define _CLEAR_X_256 62789
#endif

#ifndef _CLEAR_X_D
#define _CLEAR_X_D 62792
#endif

#ifndef _CLEAR_X_B_80
#define _CLEAR_X_B_80 62800
#endif

#ifndef _CLEAR_X_B_A
#define _CLEAR_X_B_A 62802
#endif

#ifndef _DEC_3_COUNTERS
#define _DEC_3_COUNTERS 62810
#endif

#ifndef _DEC_6_COUNTERS
#define _DEC_6_COUNTERS 62814
#endif

#ifndef _DEC_COUNTERS
#define _DEC_COUNTERS 62819
#endif

// 30 cycles
#ifndef _DELAY_3
#define _DELAY_3 62829
#endif

// 25 cycles
#ifndef _DELAY_2
#define _DELAY_2 62833
#endif

// 20 cycles
#ifndef _DELAY_1
#define _DELAY_1 62837
#endif

// 12 cycles
#ifndef _DELAY_0
#define _DELAY_0 62841
#endif

// 5*B + 10 cycles
#ifndef _DELAY_B
#define _DELAY_B 62842
#endif

// 5 cycles
#ifndef _DELAY_RTS
#define _DELAY_RTS 62845
#endif

#ifndef _BITMASK_A
#define _BITMASK_A 62846
#endif

#ifndef _ABS_A_B
#define _ABS_A_B 62852
#endif

#ifndef _ABS_B
#define _ABS_B 62859
#endif

#ifndef _RISE_RUN_ANGLE
#define _RISE_RUN_ANGLE 62867
#endif

#ifndef _GET_RISE_IDX
#define _GET_RISE_IDX 62937
#endif

#ifndef _GET_RUN_IDX
#define _GET_RUN_IDX 62939
#endif

#ifndef _GET_RISE_RUN
#define _GET_RISE_RUN 62959
#endif

#ifndef _RISE_RUN_X
#define _RISE_RUN_X 62975
#endif

#ifndef _RISE_RUN_Y
#define _RISE_RUN_Y 62977
#endif

#ifndef _RISE_RUN_LEN
#define _RISE_RUN_LEN 62979
#endif

#ifndef _ROT_VL_AB
#define _ROT_VL_AB 62992
#endif

#ifndef _ROT_VL
#define _ROT_VL 62998
#endif

#ifndef _ROT_VL_MODE_A
#define _ROT_VL_MODE_A 63007
#endif

#ifndef _ROT_VL_MODE
#define _ROT_VL_MODE 63019
#endif

#ifndef _ROT_VL_DFT
#define _ROT_VL_DFT 63031
#endif

#ifndef _XFORM_RUN_A
#define _XFORM_RUN_A 63067
#endif

#ifndef _XFORM_RUN
#define _XFORM_RUN 63069
#endif

#ifndef _XFORM_RISE_A
#define _XFORM_RISE_A 63073
#endif

#ifndef _XFORM_RISE
#define _XFORM_RISE 63075
#endif

#ifndef _MOVE_MEM_A_1
#define _MOVE_MEM_A_1 63103
#endif

#ifndef _MOVE_MEM_A
#define _MOVE_MEM_A 63107
#endif

#ifndef _INIT_MUSIC_CHK
#define _INIT_MUSIC_CHK 63111
#endif

#ifndef _INIT_MUSIC
#define _INIT_MUSIC 63117
#endif

#ifndef _INIT_MUSIC_X
#define _INIT_MUSIC_X 63122
#endif

#ifndef _SELECT_GAME
#define _SELECT_GAME 63401
#endif

#ifndef _CLEAR_SCORE
#define _CLEAR_SCORE 63567
#endif

#ifndef _ADD_SCORE_A
#define _ADD_SCORE_A 63582
#endif

#ifndef _ADD_SCORE_D
#define _ADD_SCORE_D 63612
#endif

#ifndef _STRIP_ZEROS
#define _STRIP_ZEROS 63671
#endif

#ifndef _COMPARE_SCORE
#define _COMPARE_SCORE 63687
#endif

#ifndef _NEW_HIGH_SCORE
#define _NEW_HIGH_SCORE 63704
#endif

#ifndef _OBJ_WILL_HIT_U
#define _OBJ_WILL_HIT_U 63717
#endif

#ifndef _OBJ_WILL_HIT
#define _OBJ_WILL_HIT 63731
#endif

#ifndef _OBJ_HIT
#define _OBJ_HIT 63743
#endif

#ifndef _EXPLOSION_SND
#define _EXPLOSION_SND 63790
#endif

#ifndef _DRAW_GRID_VL
#define _DRAW_GRID_VL 65439
#endif

// Char_Table
#ifndef _CHAR_TABLE
#define _CHAR_TABLE 63988
#endif

// Char_Table_End
#ifndef _CHAR_TABLE_END
#define _CHAR_TABLE_END 64468
#endif

// Poweron music, crazy coaster and narrow escape
#ifndef _VX_MUSIC_1
#define _VX_MUSIC_1 64781
#endif

// Music for Berzerk
#ifndef _VX_MUSIC_2
#define _VX_MUSIC_2 64797
#endif

#ifndef _VX_MUSIC_3
#define _VX_MUSIC_3 64897
#endif

// Music for Scramble
#ifndef _VX_MUSIC_4
#define _VX_MUSIC_4 64979
#endif

// Music for Solar Quest
#ifndef _VX_MUSIC_5
#define _VX_MUSIC_5 65080
#endif

#ifndef _VX_MUSIC_6
#define _VX_MUSIC_6 65142
#endif

#ifndef _VX_MUSIC_7
#define _VX_MUSIC_7 65222
#endif

// Music for Melody Master
#ifndef _VX_MUSIC_8
#define _VX_MUSIC_8 65272
#endif

#ifndef _VX_MUSIC_9
#define _VX_MUSIC_9 65318
#endif

#ifndef _VX_MUSIC_10
#define _VX_MUSIC_10 65348
#endif

#ifndef _VX_MUSIC_11
#define _VX_MUSIC_11 65378
#endif

#ifndef _VX_MUSIC_12
#define _VX_MUSIC_12 65402
#endif

#ifndef _VX_MUSIC_13
#define _VX_MUSIC_13 65423
#endif


#endif
