
// This file was created by WinCMOC (CMOC 6809 C Compiler for Windows)
// Created: 2/09/2016 6:13:56
// WinCMOC:  https://sourceforge.net/projects/cmoc-win32/
// CMOC:     http://perso.b2b2c.ca/~sarrazip/dev/cmoc.html

#ifndef _DRAGON_BASTOKEN_H
#define _DRAGON_BASTOKEN_H

// FILE: $RCSfile: bastoken.txt $
// DESC: List of the Dragon Color Basic tokens
// REV: $Revision: 1.1 $
// DATE: 16/03/94
// AUTHOR: Graham E.Kinns
// DISCLAIMER: All information provided as is etc.
// ARCHIVE: This file is part of the DRGNINFO collection of Dragon info files
// CONTACT: Comments, bugs, revisions, suggestions to Dragon@grempc.demon.co.uk
// HISTORY: 1.0 27/01/94 - Initial version
//          1.1 16/03/94 - Added RCS control, Token lists come from rom images
// RCSID: $Id: bastoken.txt 1.1 1994/03/16 22:40:30 G.E.Kinns Exp $
// XREF: basicfmt.txt - tokenised Basic format
//       dostoken.txt - Dragon DOS tokens
//       cocotokn.txt - CoCo Basic tokens
// SOURCE: Dragon Roms

// Reserved words
// Token  Keyword
#define _BASTOK_FOR         128
#define _BASTOK_GO          129
#define _BASTOK_REM         130
#define _BASTOK_OPREM       131
#define _BASTOK_ELSE        132
#define _BASTOK_IF          133
#define _BASTOK_DATA        134
#define _BASTOK_PRINT       135
#define _BASTOK_ON          136
#define _BASTOK_INPUT       137
#define _BASTOK_END         138
#define _BASTOK_NEXT        139
#define _BASTOK_DIM         140
#define _BASTOK_READ        141
#define _BASTOK_LET         142
#define _BASTOK_RUN         143
#define _BASTOK_RESTORE     144
#define _BASTOK_RETURN      145
#define _BASTOK_STOP        146
#define _BASTOK_POKE        147
#define _BASTOK_CONT        148
#define _BASTOK_LIST        149
#define _BASTOK_CLEAR       150
#define _BASTOK_NEW         151
#define _BASTOK_DEF         152
#define _BASTOK_CLOAD       153
#define _BASTOK_CSAVE       154
#define _BASTOK_OPEN        155
#define _BASTOK_CLOSE       156
#define _BASTOK_LLIST       157
#define _BASTOK_SET         158
#define _BASTOK_RESET       159
#define _BASTOK_CLS         160
#define _BASTOK_MOTOR       161
#define _BASTOK_SOUND       162
#define _BASTOK_AUDIO       163
#define _BASTOK_EXEC        164
#define _BASTOK_SKIPF       165
#define _BASTOK_DEL         166
#define _BASTOK_EDIT        167
#define _BASTOK_TRON        168
#define _BASTOK_TROFF       169
#define _BASTOK_LINE        170
#define _BASTOK_PCLS        171
#define _BASTOK_PSET        172
#define _BASTOK_PRESET      173
#define _BASTOK_SCREEN      174
#define _BASTOK_PCLEAR      175
#define _BASTOK_COLOR       176
#define _BASTOK_CIRCLE      177
#define _BASTOK_PAINT       178
#define _BASTOK_GET         179
#define _BASTOK_PUT         180
#define _BASTOK_DRAW        181
#define _BASTOK_PCOPY       182
#define _BASTOK_PMODE       183
#define _BASTOK_PLAY        184
#define _BASTOK_DLOAD       185
#define _BASTOK_RENUM       186
#define _BASTOK_TAB         187
#define _BASTOK_TO          188
#define _BASTOK_SUB         189
#define _BASTOK_FN          190
#define _BASTOK_THEN        191
#define _BASTOK_NOT         192
#define _BASTOK_STEP        193
#define _BASTOK_OFF         194
#define _BASTOK_OPADD       195
#define _BASTOK_OPSUB       196
#define _BASTOK_OPMUL       197
#define _BASTOK_OPDIV       198
#define _BASTOK_OPCARET     199
#define _BASTOK_AND         200
#define _BASTOK_OR          201
#define _BASTOK_OPGTH       202
#define _BASTOK_OPEQU       203
#define _BASTOK_OPLTH       204
#define _BASTOK_USING       205

// Function tokens - all proceeded by 0xff to differentiate from operators
// Token  Function
#define _BASTOK_SGN         128
#define _BASTOK_INT         129
#define _BASTOK_ABS         130
#define _BASTOK_POS         131
#define _BASTOK_RND         132
#define _BASTOK_SQR         133
#define _BASTOK_LOG         134
#define _BASTOK_EXP         135
#define _BASTOK_SIN         136
#define _BASTOK_COS         137
#define _BASTOK_TAN         138
#define _BASTOK_ATN         139
#define _BASTOK_PEEK        140
#define _BASTOK_LEN         141
#define _BASTOK_STR         142
#define _BASTOK_VAL         143
#define _BASTOK_ASC         144
#define _BASTOK_CHR         145
#define _BASTOK_EOF         146
#define _BASTOK_JOYSTK      147
#define _BASTOK_FIX         148
#define _BASTOK_HEX         149
#define _BASTOK_LEFT        150
#define _BASTOK_RIGHT       151
#define _BASTOK_MID         152
#define _BASTOK_POINT       153
#define _BASTOK_INKEY       154
#define _BASTOK_MEM         155
#define _BASTOK_VARPTR      156
#define _BASTOK_INSTR       157
#define _BASTOK_TIMER       158
#define _BASTOK_PPOINT      159
#define _BASTOK_STRING      160
#define _BASTOK_USR         161

#endif
