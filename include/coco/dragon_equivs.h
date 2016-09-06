
// This file was created by WinCMOC (CMOC 6809 C Compiler for Windows)
//
// WinCMOC:  https://sourceforge.net/projects/cmoc-win32/
// CMOC:     http://perso.b2b2c.ca/~sarrazip/dev/cmoc.html

// Translated from "dragon_equivs.asm"
//
// This file is in the public domain

#ifndef _COCO_DRAGON_EQUIVS_H
#define _COCO_DRAGON_EQUIVS_H

// Decimal 34037 (0x84F5) [Value] - ? EXBAS COMMAND INTERPRETATION LOOP
#ifndef _L813C
#define _L813C 34037
#endif

// Decimal 35252 (0x89B4) [Value] - ?? (use SN ERROR for now) EXBAS SECONDARY COMMAND HANDLER
#ifndef _L8168
#define _L8168 35252
#endif

// Decimal 46804 (0xB6D4) [Value] - ?? CHECK EXBAS CLOAD HANDLER, then main loop
#ifndef _L8311
#define _L8311 46804
#endif

// Decimal 46722 (0xB682) [Value] - ?? DO A CSAVE, then main loop
#ifndef _L8316
#define _L8316 46722
#endif

// Decimal 39242 (0x994A) [Value] - SYNTAX CHECK FOR COMMA - leaves value (2 bytes) on stack
#ifndef _L836C
#define _L836C 39242
#endif

// Decimal 39806 (0x9B7E) [Value] - EVALUATE A STRING EXPRESSION
#ifndef _L8748
#define _L8748 39806
#endif

// Decimal 39998 (0x9C3E) [Value] - Assign8BitB evaluates octal number -> FP
#ifndef _L880E
#define _L880E 39998
#endif

// Decimal 40262 (0x9D46) [Value] - GET REAL TIME CLOCK - into irq routine
#ifndef _L8955
#define _L8955 40262
#endif

// Decimal 41038 (0xA04E) [Value] - (or $a04c ?) GET THE CURRENT INPUT CHARACTER - DLOAD
#ifndef _L8C1B
#define _L8C1B 41038
#endif

// Decimal 41194 (0xA0EA) [Value] - wait for keypress - flash cursor
#ifndef _L8CC6
#define _L8CC6 41194
#endif

// Decimal 43207 (0xA8C7) [Value] - clear current graphics screen with B
#ifndef _L9539
#define _L9539 43207
#endif

// Decimal 43304 (0xA928) [Value] - Set colours
#ifndef _L959A
#define _L959A 43304
#endif

// Decimal 43320 (0xA938) [Value] - Select Display mode (text z=1, graphics z=0)
#ifndef _L95AA
#define _L95AA 43320
#endif

// Decimal 43322 (0xA93A) [Value] - RESET SAM - reset VDU
#ifndef _L95AC
#define _L95AC 43322
#endif

// Decimal 43401 (0xA989) [Value] - Set VDG mode from A
#ifndef _L95FB
#define _L95FB 43401
#endif

// Decimal 43421 (0xA99D) [Value] - Set VDG offset for graphics mode
#ifndef _L960F
#define _L960F 43421
#endif

// Decimal 43428 (0xA9A4) [Value] - Set VDG colour set from $00c1
#ifndef _L9616
#define _L9616 43428
#endif

// Decimal 43452 (0xA9BC) [Value] - SET START GRAPHIC PAGE, PMODE COMMAND
#ifndef _L962E
#define _L962E 43452
#endif

// Decimal 43486 (0xA9DE) [Value] - EVALUATE EXPRESSION - PMODE,x
#ifndef _L9650
#define _L9650 43486
#endif

// Decimal 43489 (0xA9E1) [Value] - Set page to B
#ifndef _L9653
#define _L9653 43489
#endif

// Decimal 43536 (0xAA10) [Value] - Select colour set 0 or 1 from B
#ifndef _L9682
#define _L9682 43536
#endif

// Decimal 43555 (0xAA23) [Value] - Reserve HiRes Graphics RAM, move Basic if necessary
#ifndef _L9695
#define _L9695 43555
#endif

// Decimal 43622 (0xAA66) [Value] - PUT CORRECT ADDRESSES IN FIRST 2 BYTES OF EACH LINE - PCLEAR
#ifndef _L96CB
#define _L96CB 43622
#endif

// Decimal 43655 (0xAA87) [Value] - CONSTANT OFFSET OF $600 - init of EXBAS graphics vars
#ifndef _L96EC
#define _L96EC 43655
#endif

// Decimal 43770 (0xAAFA) [Value] - VEC22 CHECK FOR @ SIGN - PUT
#ifndef _L975F
#define _L975F 43770
#endif

// Decimal 44698 (0xAE9A) [Value] - Play note from A
#ifndef _L9AD7
#define _L9AD7 44698
#endif

// Decimal 45137 (0xB051) [Value] - Draw token dispatch address
#ifndef _L9CB6
#define _L9CB6 45137
#endif

// Decimal 45904 (0xB350) [Value] - MULTIPLY (UNSIGNED) TWO 16 BIT NUMBERS TOGETHER
#ifndef _L9FB5
#define _L9FB5 45904
#endif

// Decimal 46004 (0xB3B4) [Value] - Reset ISR
#ifndef _LA027
#define _LA027 46004
#endif

// Decimal 46080 (0xB400) [Value] - Boot Basic
#ifndef _LA0B6
#define _LA0B6 46080
#endif

// Decimal 46153 (0xB449) [Value] - WARM START FLAG - go to basic main loop
#ifndef _LA0E2
#define _LA0E2 46153
#endif

// Decimal 46341 (0xB505) [Value] - GET A CHARACTER FROM CONSOLE IN
#ifndef _LA171
#define _LA171 46341
#endif

// Decimal 46346 (0xB50A) [Value] - HOOK INTO RAM - console in, GET A CHAR FROM INPUT BUFFER
#ifndef _LA176
#define _LA176 46346
#endif

// Decimal 48053 (0xBBB5) [Value] - Flashes cursor
#ifndef _LA199
#define _LA199 48053
#endif

// Decimal 46392 (0xB538) [Value] - GETKEY
#ifndef _LA1B1
#define _LA1B1 46392
#endif

// Decimal 48101 (0xBBE5) [Value] - %INCH% scans keyboard
#ifndef _LA1C1
#define _LA1C1 48101
#endif

// Decimal 46410 (0xB54A) [Value] - %OUTCHR% to DEVNUM
#ifndef _LA282
#define _LA282 46410
#endif

// Decimal 48299 (0xBCAB) [Value] - %OUTCH% to screen
#ifndef _LA30A
#define _LA30A 48299
#endif

// Decimal 48288 (0xBCA0) [Value] - Clear VDU line from cursor
#ifndef _LA323
#define _LA323 48288
#endif

// Decimal 46485 (0xB595) [Value] - SET PRINT PARAMETERS
#ifndef _LA35F
#define _LA35F 46485
#endif

// Decimal 46514 (0xB5B2) [Value] - SAVE THE PRINT PARAMETERS
#ifndef _LA37C
#define _LA37C 46514
#endif

// Decimal 46544 (0xB5D0) [Value] - inside routine that gets an input line for basic
#ifndef _LA39A
#define _LA39A 46544
#endif

// Decimal 48410 (0xBD1A) [Value] - Send char A to printer
#ifndef _LA2BF
#define _LA2BF 48410
#endif

// Decimal 46627 (0xB623) [Value] - VERIFY THAT THE FILE TYPE WAS 'INPUT
#ifndef _LA3ED
#define _LA3ED 46627
#endif

// Decimal 46641 (0xB631) [Value] - 'FILE NOT OPEN' ERROR
#ifndef _LA3FB
#define _LA3FB 46641
#endif

// Decimal 46652 (0xB63C) [Value] - MAKE SURE SELECTED FILE IS AN OUTPUT FILE, TEST DEVICE NUMBER
#ifndef _LA406
#define _LA406 46652
#endif

// Decimal 46684 (0xB65C) [Value] - CLOSE ALL FILES on cassette
#ifndef _LA426
#define _LA426 46684
#endif

// Decimal 46687 (0xB65F) [Value] - CLOSE ALL FILES (skip ram vector)
#ifndef _LA429
#define _LA429 46687
#endif

// Decimal 46691 (0xB663) [Value] - Close file (on devnum)
#ifndef _LA42D
#define _LA42D 46691
#endif

// Decimal 46920 (0xB748) [Value] - Read binary file from tape
#ifndef _LA511
#define _LA511 46920
#endif

// Decimal 46757 (0xB6A5) [Value] - Write Basic program to cassette
#ifndef _LA469
#define _LA469 46757
#endif

// Decimal 46967 (0xB777) [Value] - ...EXEC
#ifndef _LA545
#define _LA545 46967
#endif

// Decimal 46971 (0xB77B) [Value] - GO DO A BREAK CHECK
#ifndef _LA549
#define _LA549 46971
#endif

// Decimal 47052 (0xB7CC) [Value] - (or $bb97) MOVE (B) BYTES FROM (X) TO (U)
#ifndef _LA59A
#define _LA59A 47052
#endif

// Decimal 47060 (0xB7D4) [Value] - GET DEVICE NUMBER
#ifndef _LA5A2
#define _LA5A2 47060
#endif

// Decimal 47063 (0xB7D7) [Value] - EVALUATE AN EXPRESSION (# then DEVICE NUMBER)
#ifndef _LA5A5
#define _LA5A5 47063
#endif

// Decimal 47072 (0xB7E0) [Value] - EVALUATE DEVICE NUMBER
#ifndef _LA5AE
#define _LA5AE 47072
#endif

// Decimal 47097 (0xB7F9) [Value] - SYNTAX ERROR IF ANY MORE CHARS ON THIS LINE
#ifndef _LA5C7
#define _LA5C7 47097
#endif

// Decimal 47116 (0xB80C) [Value] - BRANCH BACK TO BASIC'S EOF
#ifndef _LA5DA
#define _LA5DA 47116
#endif

// Decimal 47126 (0xB816) [Value] - LINK BACK TO BASIC'S EOF STATEMENT
#ifndef _LA5E4
#define _LA5E4 47126
#endif

// Decimal 47157 (0xB835) [Value] - get file name (open)
#ifndef _LA603
#define _LA603 47157
#endif

// Decimal 47176 (0xB848) [Value] - BAD FILE MODE ERROR
#ifndef _LA616
#define _LA616 47176
#endif

// Decimal 47182 (0xB84E) [Value] - 'FILE ALREADY OPEN' ERROR
#ifndef _LA61C
#define _LA61C 47182
#endif

// Decimal 47185 (0xB851) [Value] - DEVICE NUMBER ERROR
#ifndef _LA61F
#define _LA61F 47185
#endif

// Decimal 47283 (0xB8B3) [Value] - Find File, search tape for matching filename
#ifndef _LA681
#define _LA681 47283
#endif

// Decimal 47411 (0xB933) [Value] - Read first (filename) block from tape to buffer
#ifndef _LA701
#define _LA701 47411
#endif

// Decimal 47422 (0xB93E) [Value] - %BLKIN% from tape to buffer
#ifndef _LA70B
#define _LA70B 47422
#endif

// Decimal 48557 (0xBDAD) [Value] - %CBIN% input byte from tape to A
#ifndef _LA749
#define _LA749 48557
#endif

// Decimal 48549 (0xBDA5) [Value] - %BITIN% from tape to c
#ifndef _LA755
#define _LA755 48549
#endif

// Decimal 48615 (0xBDE7) [Value] - %CSRDON% read leader
#ifndef _LA77C
#define _LA77C 48615
#endif

// Decimal 48591 (0xBDCF) [Value] - %CASON%
#ifndef _LA7CA
#define _LA7CA 48591
#endif

// Decimal 48599 (0xBDD7) [Value] - (not 100% compatible) In %CASON% WAIT A WHILE
#ifndef _LA7D1
#define _LA7D1 48599
#endif

// Decimal 47505 (0xB991) [Value] - Write first block
#ifndef _LA7E5
#define _LA7E5 47505
#endif

// Decimal 48604 (0xBDDC) [Value] - CASOFF TURN OFF THE CASSETTE MOTOR (Graham: LA7EB)
#ifndef _LA7E9
#define _LA7E9 48604
#endif

// Decimal 47513 (0xB999) [Value] - %BLKOUT% to tape
#ifndef _LA7F4
#define _LA7F4 47513
#endif

// Decimal 48658 (0xBE12) [Value] - %CBOUT% output byte to tape
#ifndef _LA82A
#define _LA82A 48658
#endif

// Decimal 47583 (0xB9DF) [Value] - Set LoRes Pixel
#ifndef _LA88D
#define _LA88D 47583
#endif

// Decimal 47623 (0xBA07) [Value] - Reset LoRes Pixel
#ifndef _LA8B5
#define _LA8B5 47623
#endif

// Decimal 47656 (0xBA28) [Value] - Calc LoRes Pixel Pos
#ifndef _LA8D9
#define _LA8D9 47656
#endif

// Decimal 47735 (0xBA77) [Value] - Clear text screen
#ifndef _LA928
#define _LA928 47735
#endif

// Decimal 47737 (0xBA79) [Value] - Clear text screen with B
#ifndef _LA92A
#define _LA92A 47737
#endif

// Decimal 47776 (0xBAA0) [Value] - JUMP TO 'SOUND' - DO A BEEP
#ifndef _LA951
#define _LA951 47776
#endif

// Decimal 47811 (0xBAC3) [Value] - Audio off
#ifndef _LA974
#define _LA974 47811
#endif

// Decimal 47813 (0xBAC5) [Value] - Audio on
#ifndef _LA976
#define _LA976 47813
#endif

// Decimal 47828 (0xBAD4) [Value] - Reset DAC
#ifndef _LA985
#define _LA985 47828
#endif

// Decimal 47830 (0xBAD6) [Value] - Writes A to DAC
#ifndef _LA987
#define _LA987 47830
#endif

// Decimal 47852 (0xBAEC) [Value] - Audio on (B=0)
#ifndef _LA99D
#define _LA99D 47852
#endif

// Decimal 48449 (0xBD41) [Value] - %SNDSEL%
#ifndef _LA9A2
#define _LA9A2 48449
#endif

// Decimal 48466 (0xBD52) [Value] - %JOYIN%
#ifndef _LA9DE
#define _LA9DE 48466
#endif

// Decimal 33589 (0x8335) [Value] - SEE IF ENOUGH ROOM IN RAM
#ifndef _LAC37
#define _LAC37 33589
#endif

// Decimal 33602 (0x8342) [Value] - OM ERROR
#ifndef _LAC44
#define _LAC44 33602
#endif

// Decimal 33604 (0x8344) [Value] - System error
#ifndef _LAC46
#define _LAC46 33604
#endif

// Decimal 33630 (0x835E) [Value] - JUMP TO BASIC'S ERROR HANDLER
#ifndef _LAC60
#define _LAC60 33630
#endif

// Decimal 33649 (0x8371) [Value] - OK prompt
#ifndef _LAC73
#define _LAC73 33649
#endif

// Decimal 33658 (0x837A) [Value] - GO TO BASIC'S MAIN LOOP, IT WILL LOAD PROGRAM
#ifndef _LAC7C
#define _LAC7C 33658
#endif

// Decimal 33773 (0x83ED) [Value] - BasVect2
#ifndef _LACEF
#define _LACEF 33773
#endif

// Decimal 33815 (0x8417) [Value] - Erases program
#ifndef _LAD19
#define _LAD19 33815
#endif

// Decimal 33823 (0x841F) [Value] - BasVect1
#ifndef _LAD21
#define _LAD21 33823
#endif

// Decimal 33844 (0x8434) [Value] - Resets stack
#ifndef _LAD33
#define _LAD33 33844
#endif

// Decimal 33951 (0x849F) [Value] - RUN BASIC
#ifndef _LAD9E
#define _LAD9E 33951
#endif

// Decimal 34012 (0x84DC) [Value] - LOOP THROUGH BASIC'S MAIN INTERPRETATION LOOP
#ifndef _LADC6
#define _LADC6 34012
#endif

// Decimal 34029 (0x84ED) [Value] - JUMP TO BASIC'S COMMAND HANDLER
#ifndef _LADD4
#define _LADD4 34029
#endif

// Decimal 34075 (0x851B) [Value] - GO DO A BREAK CHECK IF A KEY IS DOWN
#ifndef _LADEB
#define _LADEB 34075
#endif

// Decimal 34091 (0x852B) [Value] - wait for key press, return in A
#ifndef _LADFB
#define _LADFB 34091
#endif

// Decimal 34117 (0x8545) [Value] - GO 'STOP' THE SYSTEM
#ifndef _LAE15
#define _LAE15 34117
#endif

// Decimal 34509 (0x86CD) [Value]
#ifndef _LAF9A
#define _LAF9A 34509
#endif

// Decimal 34522 (0x86DA) [Value] - BRANCH BACK TO BASIC’S 'LET' COMMAND
#ifndef _LAFA4
#define _LAFA4 34522
#endif

// Decimal 34535 (0x86E7) [Value] - MOVE IT INTO THE STRING SPACE
#ifndef _LAFB1
#define _LAFB1 34535
#endif

// Decimal 40393 (0x9DC9) [Value] - check for ,"
#ifndef _LB00C
#define _LB00C 40393
#endif

// Decimal 40419 (0x9DE3) [Value] - ?not sure, in INPUT
#ifndef _LB01E
#define _LB01E 40419
#endif

// Decimal 34714 (0x879A) [Value]
#ifndef _LB069
#define _LB069 34714
#endif

// Decimal 34932 (0x8874) [Value] - NUMBER TYPE CHECK
#ifndef _LB143
#define _LB143 34932
#endif

// Decimal 34935 (0x8877) [Value] - 'TM' ERROR IF NUMERIC VARIABLE, Get expression
#ifndef _LB146
#define _LB146 34935
#endif

// Decimal 34937 (0x8879) [Value] - DO A 'TM' CHECK
#ifndef _LB148
#define _LB148 34937
#endif

// Decimal 34951 (0x8887) [Value] - EVALUATE AN EXPRESSION, Get string
#ifndef _LB156
#define _LB156 34951
#endif

// Decimal 34967 (0x8897) [Value] - (eqv ROM but usage?) COMING FROM THE 'LET' COMMAND
#ifndef _LB166
#define _LB166 34967
#endif

// Decimal 35189 (0x8975) [Value] - STRIP PROMPT STRING FROM BASIC AND PUT IT ON THE STRING STACK
#ifndef _LB244
#define _LB244 35189
#endif

// Decimal 35231 (0x899F) [Value] - SYNTAX CHECK FOR '(' AND EVALUATE EXPRESSION
#ifndef _LB262
#define _LB262 35231
#endif

// Decimal 35236 (0x89A4) [Value] - CkClBrak
#ifndef _LB267
#define _LB267 35236
#endif

// Decimal 35239 (0x89A7) [Value] - CkOpBrak
#ifndef _LB26A
#define _LB26A 35239
#endif

// Decimal 35242 (0x89AA) [Value] - CkComa
#ifndef _LB26D
#define _LB26D 35242
#endif

// Decimal 35244 (0x89AC) [Value] - CkChar
#ifndef _LB26F
#define _LB26F 35244
#endif

// Decimal 35252 (0x89B4) [Value] - SYNTAX ERROR
#ifndef _LB277
#define _LB277 35252
#endif

// Decimal 35339 (0x8A0B) [Value] - JUMP TO BASIC'S SECONDARY COMMAND HANDLER
#ifndef _LB2CE
#define _LB2CE 35339
#endif

// Decimal 35476 (0x8A94) [Value] - %GETVAR%
#ifndef _LB357
#define _LB357 35476
#endif

// Decimal 35619 (0x8B23) [Value] - EVALUATE EXPRESSION, RETURN VALUE IN ACCD
#ifndef _LB3E6
#define _LB3E6 35619
#endif

// Decimal 35625 (0x8B29) [Value] - %GETUSR%
#ifndef _LB3E9
#define _LB3E9 35625
#endif

// Decimal 35725 (0x8B8D) [Value] - FC ERROR
#ifndef _LB44A
#define _LB44A 35725
#endif

// Decimal 35893 (0x8C35) [Value] - Assign16Bit (skips to $8c37)
#ifndef _LB4F2
#define _LB4F2 35893
#endif

// Decimal 35894 (0x8C36) [Value] - Assign8Bit, LOAD ACCB INTO FPA0
#ifndef _LB4F3
#define _LB4F3 35894
#endif

// Decimal 35922 (0x8C52) [Value] - RESERVE ACCB BYTES IN STRING SPACE
#ifndef _LB50F
#define _LB50F 35922
#endif

// Decimal 35929 (0x8C59) [Value] - PUT ON TEMPORARY STRING STACK
#ifndef _LB516
#define _LB516 35929
#endif

// Decimal 36055 (0x8CD7) [Value] - Force string space garbage collection
#ifndef _LB591
#define _LB591 36055
#endif

// Decimal 36250 (0x8D9A) [Value] - GET LENGTH AND ADDRESS OF STRING
#ifndef _LB654
#define _LB654 36250
#endif

// Decimal 36253 (0x8D9D) [Value] - PURGE THE STRING PUT ON THE STRING STACK
#ifndef _LB657
#define _LB657 36253
#endif

// Decimal 36255 (0x8D9F) [Value] - %DELVAR%
#ifndef _LB659
#define _LB659 36255
#endif

// Decimal 36321 (0x8DE1) [Value] - SAVE STRING DESCRIPTOR ON STRING STACK
#ifndef _LB69B
#define _LB69B 36321
#endif

// Decimal 36330 (0x8DEA) [Value] - FIRST BYTE OF STRING EXPRESSION
#ifndef _LB6A4
#define _LB6A4 36330
#endif

// Decimal 36433 (0x8E51) [Value] - Get8Bit
#ifndef _LB70B
#define _LB70B 36433
#endif

// Decimal 36436 (0x8E54) [Value] - EVALUATE NUMERIC EXPRESSION AND RETURN VALUE IN ACCB
#ifndef _LB70E
#define _LB70E 36436
#endif

// Decimal 36478 (0x8E7E) [Value] - SYNTAX CHECK FOR COMMA, EVALUATE EXPRESSION
#ifndef _LB738
#define _LB738 36478
#endif

// Decimal 36483 (0x8E83) [Value] - Get16Bit
#ifndef _LB73D
#define _LB73D 36483
#endif

// Decimal 36522 (0x8EAA) [Value] - LIST token dispatch address
#ifndef _LB764
#define _LB764 36522
#endif

// Decimal 37025 (0x90A1) [Value] - Print CR
#ifndef _LB958
#define _LB958 37025
#endif

// Decimal 37029 (0x90A5) [Value] - SEND A CR TO THE SCREEN
#ifndef _LB95C
#define _LB95C 37029
#endif

// Decimal 37093 (0x90E5) [Value] - STRINOUT
#ifndef _LB99C
#define _LB99C 37093
#endif

// Decimal 37096 (0x90E8) [Value] - STRINOUT+3, PRINT STRING TO CONSOLE OUT
#ifndef _LB99F
#define _LB99F 37096
#endif

// Decimal 37099 (0x90EB) [Value] - SEND STRING TO CONSOLE OUT
#ifndef _LB9A2
#define _LB9A2 37099
#endif

// Decimal 37109 (0x90F5) [Value] - SEND BLANK TO CONSOLE OUT
#ifndef _LB9AC
#define _LB9AC 37109
#endif

// Decimal 37112 (0x90F8) [Value] - SEND A '?' TO THE SCREEN
#ifndef _LB9AF
#define _LB9AF 37112
#endif

// Decimal 37134 (0x910E) [Value] - oper_plus_dispatch
#ifndef _LB9C5
#define _LB9C5 37134
#endif

// Decimal 37692 (0x933C) [Value] - oper_div_dispatch, DIVIDE FPA1 BY FPA0
#ifndef _LBB91
#define _LBB91 37692
#endif

// Decimal 37823 (0x93BF) [Value] - MOVFM, COPY A PACKED FP NUMBER FROM (X) TO FPA0
#ifndef _LBC14
#define _LBC14 37823
#endif

// Decimal 37854 (0x93DE) [Value] - PACK FPA0 INTO VARDES
#ifndef _LBC33
#define _LBC33 37854
#endif

// Decimal 37856 (0x93E0) [Value] - PACK FPA0 AND STORE IT IN STRING SPACE
#ifndef _LBC35
#define _LBC35 37856
#endif

// Decimal 37898 (0x940A) [Value] - SAVE NUMBER IN FPA1
#ifndef _LBC5F
#define _LBC5F 37898
#endif

// Decimal 38266 (0x957A) [Value] - Print Number, Print decimal D to screen
#ifndef _LBDCC
#define _LBDCC 38266
#endif

// Decimal 38279 (0x9587) [Value] - CONVERT FP NUMBER TO ASCII STRING
#ifndef _LBDD9
#define _LBDD9 38279
#endif

// Decimal 37093 (0x90E5) [Value] - LB99C
#ifndef _STRINOUT
#define _STRINOUT 37093
#endif

// Decimal 36433 (0x8E51) [Value] - LB70B Get8Bit, Evaluate argument
#ifndef _EVALEXPB
#define _EVALEXPB 36433
#endif

// Decimal 35242 (0x89AA) [Value] - LB26D CkComa
#ifndef _SYNCOMMA
#define _SYNCOMMA 35242
#endif

// Decimal 46159 (0xB44F) [Value] - L80C0
#ifndef _XBWMST
#define _XBWMST 46159
#endif

// Decimal 40962 (0xA002) [Value] - LA002
#ifndef _CHROUT
#define _CHROUT 40962
#endif

// Decimal 46410 (0xB54A) [Value] - LA282
#ifndef _PUTCHR
#define _PUTCHR 46410
#endif

// Decimal 47711 (0xBA5F) [Value] - LA910
#ifndef _CLS
#define _CLS 47711
#endif

// Decimal 35629 (0x8B2D) [Value] - LB3ED
#ifndef _INTCNV
#define _INTCNV 35629
#endif

// Decimal 35895 (0x8C37) [Value] - LB4F4
#ifndef _GIVABF
#define _GIVABF 35895
#endif

// Decimal 36522 (0x8EAA) [Value] - LB764
#ifndef _LIST
#define _LIST 36522
#endif

// Decimal 38041 (0x9499) [Value] - LBCEE
#ifndef _INT
#define _INT 38041
#endif

// Decimal 46667 (0xB64B) [Value] - (rts) $b54b Character output
#ifndef _XVEC3
#define _XVEC3 46667
#endif

// Decimal 46667 (0xB64B) [Value] - (rts) $b50b Character input
#ifndef _XVEC4
#define _XVEC4 46667
#endif

// Decimal 46667 (0xB64B) [Value] - (rts) $b664 Close a single device or file
#ifndef _XVEC8
#define _XVEC8 46667
#endif

// Decimal 46667 (0xB64B) [Value] - (rts) $84de ?About to deal with first char of new statement /PRINT
#ifndef _XVEC9
#define _XVEC9 46667
#endif

// Decimal 46667 (0xB64B) [Value] - (rts) $8954 Evaluate an expression
#ifndef _XVEC15
#define _XVEC15 46667
#endif

// Decimal 46667 (0xB64B) [Value] - (rts) $8347 System error
#ifndef _XVEC17
#define _XVEC17 46667
#endif

// Decimal 46667 (0xB64B) [Value] - (rts) $85a5 RUN statement
#ifndef _XVEC18
#define _XVEC18 46667
#endif


#endif
