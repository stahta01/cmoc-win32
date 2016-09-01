
// This file was created by WinCMOC (CMOC 6809 C Compiler for Windows)
// Created: 2/09/2016 6:13:56
// WinCMOC:  https://sourceforge.net/projects/cmoc-win32/
// CMOC:     http://perso.b2b2c.ca/~sarrazip/dev/cmoc.html

#ifndef _COCO_BASTOKEN_H
#define _COCO_BASTOKEN_H

// FILE: $RCSfile: cocotokn.txt $
// DESC: List of the Coco Extended Color Basic tokens
// REV: $Revision: 1.1 $
// DATE: 16/03/94
// AUTHOR: Graham E.Kinns
// DISCLAIMER: All information provided as is etc.
// ARCHIVE: This file is part of the DRGNINFO collection of Dragon info files
// CONTACT: Comments, bugs, revisions, suggestions to Dragon@grempc.demon.co.uk
// HISTORY: 1.0 16/03/94 - Initial version
// RCSID: $Id: cocotokn.txt 1.1 1994/05/10 16:30:57 G.E.Kinns Exp $
// XREF: basicfmt.txt - tokenised Basic format
//       bastoken.txt - Dragon Basic tokens

// Operator tokens
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
#define _BASTOK_RUN         142
#define _BASTOK_RESTORE     143
#define _BASTOK_RETURN      144
#define _BASTOK_STOP        145
#define _BASTOK_POKE        146
#define _BASTOK_CONT        147
#define _BASTOK_LIST        148
#define _BASTOK_CLEAR       149
#define _BASTOK_NEW         150
#define _BASTOK_CLOAD       151
#define _BASTOK_CSAVE       152
#define _BASTOK_OPEN        153
#define _BASTOK_CLOSE       154
#define _BASTOK_LLIST       155
#define _BASTOK_SET         156
#define _BASTOK_RESET       157
#define _BASTOK_CLS         158
#define _BASTOK_MOTOR       159
#define _BASTOK_SOUND       160
#define _BASTOK_AUDIO       161
#define _BASTOK_EXEC        162
#define _BASTOK_SKIPF       163
#define _BASTOK_TAB         164
#define _BASTOK_TO          165
#define _BASTOK_SUB         166
#define _BASTOK_THEN        167
#define _BASTOK_NOT         168
#define _BASTOK_STEP        169
#define _BASTOK_OFF         170
#define _BASTOK_OPADD       171
#define _BASTOK_OPSUB       172
#define _BASTOK_OPMUL       173
#define _BASTOK_OPDIV       174
#define _BASTOK_OPCARET     175
#define _BASTOK_AND         176
#define _BASTOK_OR          177
#define _BASTOK_OPGTH       178
#define _BASTOK_OPEQU       179
#define _BASTOK_OPLTH       180
#define _BASTOK_DEL         181
#define _BASTOK_EDIT        182
#define _BASTOK_TRON        183
#define _BASTOK_TROFF       184
#define _BASTOK_DEF         185
#define _BASTOK_LET         186
#define _BASTOK_LINE        187
#define _BASTOK_PCLS        188
#define _BASTOK_PSET        189
#define _BASTOK_PRESET      190
#define _BASTOK_SCREEN      191
#define _BASTOK_PCLEAR      192
#define _BASTOK_COLOR       193
#define _BASTOK_CIRCLE      194
#define _BASTOK_PAINT       195
#define _BASTOK_GET         196
#define _BASTOK_PUT         197
#define _BASTOK_DRAW        198
#define _BASTOK_PCOPY       199
#define _BASTOK_PMODE       200
#define _BASTOK_PLAY        201
#define _BASTOK_DLOAD       202
#define _BASTOK_RENUM       203
#define _BASTOK_FN          204
#define _BASTOK_USING       205
//  RSDOS adds these .. (from Dragon User 12/84)
#define _BASTOK_DIR         206
#define _BASTOK_DRIVE       207
#define _BASTOK_FIELD       208
#define _BASTOK_FILES       209
#define _BASTOK_KILL        210
#define _BASTOK_LOAD        211
#define _BASTOK_LSET        212
#define _BASTOK_MERGE       213
#define _BASTOK_RENAME      214
#define _BASTOK_RSET        215
#define _BASTOK_SAVE        216
#define _BASTOK_WRITE       217
#define _BASTOK_VERIFY      218
#define _BASTOK_UNLOAD      219
#define _BASTOK_DSKINI      220
#define _BASTOK_BACKUP      221
#define _BASTOK_COPY        222
#define _BASTOK_DSKI        223
#define _BASTOK_DSKO        224

// Function tokens - all proceeded by 0xff to differentiate from operators
// Token  Keyword
#define _BASTOK_SGN         128
#define _BASTOK_INT         129
#define _BASTOK_ABS         130
#define _BASTOK_USR         131
#define _BASTOK_RND         132
#define _BASTOK_SIN         133
#define _BASTOK_PEEK        134
#define _BASTOK_LEN         135
#define _BASTOK_STR         136
#define _BASTOK_VAL         137
#define _BASTOK_ASC         138
#define _BASTOK_CHR         139
#define _BASTOK_EOF         140
#define _BASTOK_JOYSTK      141
#define _BASTOK_LEFT        142
#define _BASTOK_RIGHT       143
#define _BASTOK_MID         144
#define _BASTOK_POINT       145
#define _BASTOK_INKEY       146
#define _BASTOK_MEM         147
#define _BASTOK_ATN         148
#define _BASTOK_COS         149
#define _BASTOK_TAN         150
#define _BASTOK_EXP         151
#define _BASTOK_FIX         152
#define _BASTOK_LOG         153
#define _BASTOK_POS         154
#define _BASTOK_SQR         155
#define _BASTOK_HEX         156
#define _BASTOK_VARPTR      157
#define _BASTOK_INSTR       158
#define _BASTOK_TIMER       159
#define _BASTOK_PPOINT      160
#define _BASTOK_STRING      161
//  RSDOS adds these .. (from Dragon User 12/84)
#define _BASTOK_CVN         162
#define _BASTOK_FREE        163
#define _BASTOK_LOC         164
#define _BASTOK_LOF         165
#define _BASTOK_MKN         166

#endif
