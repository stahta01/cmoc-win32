
// This file was created by WinCMOC (CMOC 6809 C Compiler for Windows)
//
// WinCMOC:  https://sourceforge.net/projects/cmoc-win32/
// CMOC:     http://perso.b2b2c.ca/~sarrazip/dev/cmoc.html

// Translated from "romdefs.asm"
//
// This file is in the public domain

#ifndef _SUPERDOS_ROMDEFS_H
#define _SUPERDOS_ROMDEFS_H

// Decimal 0 (0x0) [Value] - Offset of number of reserved words
#ifndef _STUBRESWORDSOFS
#define _STUBRESWORDSOFS 0
#endif

// Decimal 1 (0x1) [Value] - Offset of reserved word lookup table
#ifndef _STUBRESLOOKUPOFS
#define _STUBRESLOOKUPOFS 1
#endif

// Decimal 3 (0x3) [Value] - Offset of reserved word jump table
#ifndef _STUBRESJUMPOFS
#define _STUBRESJUMPOFS 3
#endif

// Decimal 5 (0x5) [Value] - Offset of nummber of functions
#ifndef _STUBFUNCSOFS
#define _STUBFUNCSOFS 5
#endif

// Decimal 6 (0x6) [Value] - Offset of function lookup table
#ifndef _STUBFUNCSLOOKUPOFS
#define _STUBFUNCSLOOKUPOFS 6
#endif

// Decimal 8 (0x8) [Value] - Offset of functions jump table
#ifndef _STUBFUNCSJUMPOFS
#define _STUBFUNCSJUMPOFS 8
#endif

// Decimal 33 (0x21) [Value] - Skip 1 byte (BRN)
#ifndef _SKIP1
#define _SKIP1 33
#endif

// Decimal 140 (0x8C) [Value] - Skip 2 bytes (CMPX)
#ifndef _SKIP2
#define _SKIP2 140
#endif

// Decimal 134 (0x86) [Value] - Skip 1 byte (LDA)
#ifndef _SKIP1LD
#define _SKIP1LD 134
#endif

// Decimal 0 (0x0) [Value] - Vector dest for 167
#ifndef _COCOVEC167
#define _COCOVEC167 0
#endif

// Decimal 0 (0x0) [Value] - Vector dest for 16A
#ifndef _COCOVECT16A
#define _COCOVECT16A 0
#endif

// Decimal 0 (0x0) [Value] - Vector dest for 176
#ifndef _COCOVECT176
#define _COCOVECT176 0
#endif

// Decimal 0 (0x0) [Value] - Vector dest for 179
#ifndef _COCOVECT179
#define _COCOVECT179 0
#endif

// Decimal 0 (0x0) [Value] - Vector dest for 18B
#ifndef _COCOVECT18B
#define _COCOVECT18B 0
#endif

// Decimal 0 (0x0) [Value] - Vector dest for 191
#ifndef _COCOVECT191
#define _COCOVECT191 0
#endif

// Decimal 0 (0x0) [Value] - Vector Dest for 194
#ifndef _COCOVECT194
#define _COCOVECT194 0
#endif

// Decimal 0 (0x0) [Value] - Vector Dest for 197
#ifndef _COCOVECT197
#define _COCOVECT197 0
#endif

// Decimal 0 (0x0) [Value] - Vector Dest for 19A
#ifndef _COCOVECT19A
#define _COCOVECT19A 0
#endif

// Decimal 0 (0x0) [Value] - Vector Dest for 1A3
#ifndef _COCOVECT1A3
#define _COCOVECT1A3 0
#endif

// Decimal 0 (0x0) [Value] - Timeourt for DLOAD, unknown for Dragon
#ifndef _SERDLTIMEOUT
#define _SERDLTIMEOUT 0
#endif

// Decimal 0 (0x0) [Value] - Baud rate for DLOAD, unknown for Dragon
#ifndef _SERDLBAUD
#define _SERDLBAUD 0
#endif

// Decimal 0 (0x0) [Value] - Break flag, +ve=stop,-ve=end
#ifndef _BASBREAKFLAG
#define _BASBREAKFLAG 0
#endif

// Decimal 1 (0x1) [Value] - First string delimiter
#ifndef _BASDELIM1
#define _BASDELIM1 1
#endif

// Decimal 2 (0x2) [Value] - Second string delimiter
#ifndef _BASDELIM2
#define _BASDELIM2 2
#endif

// Decimal 3 (0x3) [Value] - General count/scratch var
#ifndef _BASGENCOUNT
#define _BASGENCOUNT 3
#endif

// Decimal 4 (0x4) [Value] - If count - how many in a line
#ifndef _BASIFCOUNT
#define _BASIFCOUNT 4
#endif

// Decimal 5 (0x5) [Value] - Array evaluation flag, 0=eval, 1=dimensioning
#ifndef _BASARRAYEVAL
#define _BASARRAYEVAL 5
#endif

// Decimal 6 (0x6) [Value] - Variable type flag 0=numeric, $ff=string
#ifndef _BASVARTYPE
#define _BASVARTYPE 6
#endif

// Decimal 7 (0x7) [Value] - Garbage collection flag
#ifndef _BASGARBAGEFLAG
#define _BASGARBAGEFLAG 7
#endif

// Decimal 8 (0x8) [Value] - Disable array search flag, 0=allow 0<>disable
#ifndef _BASDISARRAYSEARCH
#define _BASDISARRAYSEARCH 8
#endif

// Decimal 9 (0x9) [Value] - Iinput/read flag, 0=input 0<>read
#ifndef _BASINPUTFLAG
#define _BASINPUTFLAG 9
#endif

// Decimal 10 (0xA) [Value] - Relational operator flag
#ifndef _BASRELATEFLAG
#define _BASRELATEFLAG 10
#endif

// Decimal 11 (0xB) [Value] - First free temory string space pointer
#ifndef _BASSTRFIRSTFREETEMP
#define _BASSTRFIRSTFREETEMP 11
#endif

// Decimal 13 (0xD) [Value] - Last used tempory string space pointer
#ifndef _BASSTRLASTUSEDTEMP
#define _BASSTRLASTUSEDTEMP 13
#endif

// Decimal 15 (0xF) [Value] - Tempory pointer
#ifndef _BASTEMPPTR
#define _BASTEMPPTR 15
#endif

// Decimal 17 (0x11) [Value] - Tempory discriptor pointer (stack search)
#ifndef _BASTEMPPTR1
#define _BASTEMPPTR1 17
#endif

// Decimal 19 (0x13) [Value] - Tempory FPA Mantissa for FPA2
#ifndef _BASTEMPFPA2
#define _BASTEMPFPA2 19
#endif

// Decimal 23 (0x17) [Value] - Bottom of stack at last check
#ifndef _BASBOTSTACK
#define _BASBOTSTACK 23
#endif

// Decimal 25 (0x19) [Value] - Start addr of basic program
#ifndef _BASSTARTPROG
#define _BASSTARTPROG 25
#endif

// Decimal 27 (0x1B) [Value] - Start address of simple variables
#ifndef _BASVARSIMPLEADDR
#define _BASVARSIMPLEADDR 27
#endif

// Decimal 29 (0x1D) [Value] - Start address of Array table
#ifndef _BASVARARRAYADDR
#define _BASVARARRAYADDR 29
#endif

// Decimal 31 (0x1F) [Value] - End of storage in use by basic
#ifndef _BASVAREND
#define _BASVAREND 31
#endif

// Decimal 33 (0x21) [Value] - Base address of string space (and stack)
#ifndef _BASVARSTRINGBASE
#define _BASVARSTRINGBASE 33
#endif

// Decimal 33 (0x21) [Value] - Address of top of machine stack
#ifndef _ADDRSTACK
#define _ADDRSTACK 33
#endif

// Decimal 35 (0x23) [Value] - Top of string space in use
#ifndef _BASVARSTRTOP
#define _BASVARSTRTOP 35
#endif

// Decimal 37 (0x25) [Value] - Utility string pointer
#ifndef _BASSTRUTIL
#define _BASSTRUTIL 37
#endif

// Decimal 39 (0x27) [Value] - Top of firmware RAM CLEAR xxx,yyyy set this to yyyy
#ifndef _ADDRFWARERAMTOP
#define _ADDRFWARERAMTOP 39
#endif

// Decimal 41 (0x29) [Value] - Line no used by CONT
#ifndef _BASCONTLINE
#define _BASCONTLINE 41
#endif

// Decimal 43 (0x2B) [Value] - Tempory line no
#ifndef _BASTEMPLINE
#define _BASTEMPLINE 43
#endif

// Decimal 45 (0x2D) [Value] - Pointer to saved input during a STOP
#ifndef _BASOLDINPUTPTR
#define _BASOLDINPUTPTR 45
#endif

// Decimal 47 (0x2F) [Value] - Direct mode text pointer
#ifndef _BASDIRECTTEXTPTR
#define _BASDIRECTTEXTPTR 47
#endif

// Decimal 49 (0x31) [Value] - Line number of current data statement
#ifndef _BASVARDATALINE
#define _BASVARDATALINE 49
#endif

// Decimal 51 (0x33) [Value] - Address of next item in data
#ifndef _BASVARDATAADDR
#define _BASVARDATAADDR 51
#endif

// Decimal 53 (0x35) [Value] - Address of keyboard input buffer
#ifndef _TEXTKBDBUFFADDR
#define _TEXTKBDBUFFADDR 53
#endif

// Decimal 55 (0x37) [Value] - Pointer to variable last in use
#ifndef _BASVARLASTINUSE
#define _BASVARLASTINUSE 55
#endif

// Decimal 57 (0x39) [Value] - Poiinter to VARPTR last in use
#ifndef _BASVARPTRLAST
#define _BASVARPTRLAST 57
#endif

// Decimal 59 (0x3B) [Value] - Pointer to a tempory var descriptor
#ifndef _BASTEMPVARDESC
#define _BASTEMPVARDESC 59
#endif

// Decimal 63 (0x3F) [Value] - Tempory relational operator flag
#ifndef _BASTEMPRELATEFLAG
#define _BASTEMPRELATEFLAG 63
#endif

// Decimal 64 (0x40) [Value] - Floating point accumulator 3 (packed)
#ifndef _BASVARFPACC3
#define _BASVARFPACC3 64
#endif

// Decimal 69 (0x45) [Value] - Floating point accumulator 4 (packed)
#ifndef _BASVARFPACC4
#define _BASVARFPACC4 69
#endif

// Decimal 74 (0x4A) [Value] - Floating point accumulator 5 (packed)
#ifndef _BASVARFPACC5
#define _BASVARFPACC5 74
#endif

// Decimal 79 (0x4F) [Value] - Floating point acumulator 1
#ifndef _BASVARFPACC1
#define _BASVARFPACC1 79
#endif

// Decimal 82 (0x52) [Value] - Part of FPA1, used for 16bit assigns
#ifndef _BASVARASSIGN16
#define _BASVARASSIGN16 82
#endif

// Decimal 92 (0x5C) [Value] - Floating point acumulator 2
#ifndef _BASVARFPACC2
#define _BASVARFPACC2 92
#endif

// Decimal 102 (0x66) [Value] - Current line during list
#ifndef _BASLISTLINE
#define _BASLISTLINE 102
#endif

// Decimal 104 (0x68) [Value] - Current line no $FFFF in direct mode
#ifndef _BASCURRENTLINE
#define _BASCURRENTLINE 104
#endif

// Decimal 106 (0x6A) [Value] - VDU comma width field
#ifndef _TEXTVDUCOMMAW
#define _TEXTVDUCOMMAW 106
#endif

// Decimal 107 (0x6B) [Value] - VDU last comma field, should be VDU line width - VDU comma width
#ifndef _TEXTVDULASTCOMMA
#define _TEXTVDULASTCOMMA 107
#endif

// Decimal 108 (0x6C) [Value] - Current column for VDU output
#ifndef _TEXTVDUCURRCOL
#define _TEXTVDUCURRCOL 108
#endif

// Decimal 109 (0x6D) [Value] - VDU line width, normally 32
#ifndef _TEXTVDULINEW
#define _TEXTVDULINEW 109
#endif

// Decimal 110 (0x6E) [Value] - Cassette IO Flag, set to $FF when IO in progress
#ifndef _CASIOFLAG
#define _CASIOFLAG 110
#endif

// Decimal 111 (0x6F) [Value] - Current device number
#ifndef _TEXTDEVN
#define _TEXTDEVN 111
#endif

// Decimal 112 (0x70) [Value] - Cassette IO Flag, nonzero if EOF reached
#ifndef _CASEOFFLAG
#define _CASEOFFLAG 112
#endif

// Decimal 113 (0x71) [Value] - Warm start flag $55=warm start, else cold start
#ifndef _WARMSTARTFLAG
#define _WARMSTARTFLAG 113
#endif

// Decimal 114 (0x72) [Value] - Secondary Reset vector address, must point to NOP
#ifndef _INDVECRESET
#define _INDVECRESET 114
#endif

// Decimal 116 (0x74) [Value] - Physical end of RAM (4K, 16K, 32K or 64K).
#ifndef _ADDRRAMTOP
#define _ADDRRAMTOP 116
#endif

// Decimal 118 (0x76) [Value] - 2 unused bytes
#ifndef _BASUNUSED1
#define _BASUNUSED1 118
#endif

// Decimal 120 (0x78) [Value] - Cassette status byte, 0=cassette closed, 1=open for input, 2=open for output
#ifndef _CASSTATUS
#define _CASSTATUS 120
#endif

// Decimal 121 (0x79) [Value] - Size of cassette IO buffer
#ifndef _CASIOBUFFSIZE
#define _CASIOBUFFSIZE 121
#endif

// Decimal 122 (0x7A) [Value] - Address of cassette file header
#ifndef _CASHEADBUFFADDR
#define _CASHEADBUFFADDR 122
#endif

// Decimal 124 (0x7C) [Value] - Cassete block type, 0=filename, 1=data, 255=EOF
#ifndef _CASBLOCKTYPE
#define _CASBLOCKTYPE 124
#endif

// Decimal 125 (0x7D) [Value] - Cassete block length, number of bytes read, or to be written
#ifndef _CASBLOCKLEN
#define _CASBLOCKLEN 125
#endif

// Decimal 126 (0x7E) [Value] - Cassette IO buffer address, where data will be read/written
#ifndef _CASIOBUFFADDR
#define _CASIOBUFFADDR 126
#endif

// Decimal 128 (0x80) [Value] - Used by cassette routines for calculating checksum
#ifndef _CASCKSUM
#define _CASCKSUM 128
#endif

// Decimal 129 (0x81) [Value] - Cassette IO error code 0=no error, 1=CRC, 2=attempt to load in non-ram area
#ifndef _CASIOERRORCODE
#define _CASIOERRORCODE 129
#endif

// Decimal 130 (0x82) [Value] - Cassette tempory storage
#ifndef _CASTEMP
#define _CASTEMP 130
#endif

// Decimal 131 (0x83) [Value] - Cassette bit counter
#ifndef _CASBITCOUNT
#define _CASBITCOUNT 131
#endif

// Decimal 132 (0x84) [Value] - Cassette Phase flag
#ifndef _CASPHASEFLAG
#define _CASPHASEFLAG 132
#endif

// Decimal 133 (0x85) [Value] - Casette last sine tabe entry
#ifndef _CASLASTSINE
#define _CASLASTSINE 133
#endif

// Decimal 134 (0x86) [Value] - Data for Lo-res set/reset
#ifndef _GRSETRESETDATA
#define _GRSETRESETDATA 134
#endif

// Decimal 135 (0x87) [Value] - ASCII code of last keypress, not cleard by key release
#ifndef _TEXTLASTKEY
#define _TEXTLASTKEY 135
#endif

// Decimal 136 (0x88) [Value] - Current VDU cursor address
#ifndef _TEXTVDUCURSADDR
#define _TEXTVDUCURSADDR 136
#endif

// Decimal 138 (0x8A) [Value] - Misc 16 bit scratch register (always zero ??)
#ifndef _MISC16BITSCRATCH
#define _MISC16BITSCRATCH 138
#endif

// Decimal 140 (0x8C) [Value] - Sound pitch value
#ifndef _SNDPITCH
#define _SNDPITCH 140
#endif

// Decimal 141 (0x8D) [Value] - Sound duration
#ifndef _SNDLENGTH
#define _SNDLENGTH 141
#endif

// Decimal 143 (0x8F) [Value] - Cusrsor flash counter
#ifndef _TEXTCURSFALSHCNT
#define _TEXTCURSFALSHCNT 143
#endif

// Decimal 144 (0x90) [Value] - Cassete leader count, number of $55 bytes in the leader
#ifndef _CASLEADCOUNT
#define _CASLEADCOUNT 144
#endif

// Decimal 146 (0x92) [Value] - Cassette 1200/2400 partition
#ifndef _CASPARTRT
#define _CASPARTRT 146
#endif

// Decimal 147 (0x93) [Value] - Cassette Upper limit of 1200Hz
#ifndef _CASMAX12
#define _CASMAX12 147
#endif

// Decimal 148 (0x94) [Value] - Cassette Upper limit of 2400Hz
#ifndef _CASMAX24
#define _CASMAX24 148
#endif

// Decimal 149 (0x95) [Value] - Cassette motor on delay (also inter-block gap)
#ifndef _CASMOTORDELAY
#define _CASMOTORDELAY 149
#endif

// Decimal 151 (0x97) [Value] - Keyboard scan delay constant, used to debounce
#ifndef _TEXTKBDDELAY
#define _TEXTKBDDELAY 151
#endif

// Decimal 153 (0x99) [Value] - Printer comma width
#ifndef _TEXTPRNCOMMAW
#define _TEXTPRNCOMMAW 153
#endif

// Decimal 154 (0x9A) [Value] - Printer last comma width, should be printer line width - prinnter comma width
#ifndef _TEXTPRNLASTCOMMA
#define _TEXTPRNLASTCOMMA 154
#endif

// Decimal 155 (0x9B) [Value] - Printer line width
#ifndef _TEXTPRNLINEW
#define _TEXTPRNLINEW 155
#endif

// Decimal 156 (0x9C) [Value] - Printer current column
#ifndef _TEXTPRNCURRCOL
#define _TEXTPRNCURRCOL 156
#endif

// Decimal 157 (0x9D) [Value] - Exec address, on D64, at startup points to routine to boot all ram mode
#ifndef _BASEXECADDR
#define _BASEXECADDR 157
#endif

// Decimal 159 (0x9F) [Value] - Get next basic character routine
#ifndef _BASCHRGET
#define _BASCHRGET 159
#endif

// Decimal 165 (0xA5) [Value] - Get current basic ccharacter
#ifndef _BASCHRGETCURR
#define _BASCHRGETCURR 165
#endif

// Decimal 166 (0xA6) [Value] - Address of current significant bit in command line
#ifndef _BASADDRSIGBYTE
#define _BASADDRSIGBYTE 166
#endif

// Decimal 171 (0xAB) [Value] - Used by RND
#ifndef _BASRNDDATA
#define _BASRNDDATA 171
#endif

// Decimal 175 (0xAF) [Value] - Tron flag nonzero=trace on
#ifndef _BASTRONFLAG
#define _BASTRONFLAG 175
#endif

// Decimal 176 (0xB0) [Value] - Address of USR address table
#ifndef _BASUSRTABLEADDR
#define _BASUSRTABLEADDR 176
#endif

// Decimal 178 (0xB2) [Value] - Current foreground colour
#ifndef _GRFOREGROUND
#define _GRFOREGROUND 178
#endif

// Decimal 179 (0xB3) [Value] - Current background colour
#ifndef _GRBACKGROUND
#define _GRBACKGROUND 179
#endif

// Decimal 180 (0xB4) [Value] - Tempory colour in use
#ifndef _GRCOLOURTEMP
#define _GRCOLOURTEMP 180
#endif

// Decimal 181 (0xB5) [Value] - Byte value for current colour, to set all pixels in byte to that colour
#ifndef _GRCURRCOLOUR
#define _GRCURRCOLOUR 181
#endif

// Decimal 182 (0xB6) [Value] - Current PMODE number
#ifndef _GRCURRPMODE
#define _GRCURRPMODE 182
#endif

// Decimal 183 (0xB7) [Value] - Address of last byte in current display
#ifndef _GRLASTDISPLAYADDR
#define _GRLASTDISPLAYADDR 183
#endif

// Decimal 185 (0xB9) [Value] - Number of byts/lin in current mode
#ifndef _GRBYTESPERLINE
#define _GRBYTESPERLINE 185
#endif

// Decimal 186 (0xBA) [Value] - Address of first byte in current display
#ifndef _GRDISPLAYSTARTADDR
#define _GRDISPLAYSTARTADDR 186
#endif

// Decimal 188 (0xBC) [Value] - Page number of Start of graphics pages
#ifndef _GRSTARTPAGES
#define _GRSTARTPAGES 188
#endif

// Decimal 189 (0xBD) [Value] - Current X cursor pos
#ifndef _GRCURRX
#define _GRCURRX 189
#endif

// Decimal 191 (0xBF) [Value] - Current Y cursor pos
#ifndef _GRCURRY
#define _GRCURRY 191
#endif

// Decimal 193 (0xC1) [Value] - Colour set currently in use
#ifndef _GRCOLOURSET
#define _GRCOLOURSET 193
#endif

// Decimal 194 (0xC2) [Value] - Plot/Unplot flag, 0=reset, nonzero=set
#ifndef _GRPLOTFLAG
#define _GRPLOTFLAG 194
#endif

// Decimal 195 (0xC3) [Value] - Current horizontal pixel no
#ifndef _GRPIXELNOX
#define _GRPIXELNOX 195
#endif

// Decimal 197 (0xC5) [Value] - Current vertical pixel number
#ifndef _GRPIXELNOY
#define _GRPIXELNOY 197
#endif

// Decimal 199 (0xC7) [Value] - Current Cursor X
#ifndef _GRCURRXCO
#define _GRCURRXCO 199
#endif

// Decimal 201 (0xC9) [Value] - Current Cursor Y
#ifndef _GRCURRYCO
#define _GRCURRYCO 201
#endif

// Decimal 203 (0xCB) [Value] - Circle command X
#ifndef _GRCIRCLEXCO
#define _GRCIRCLEXCO 203
#endif

// Decimal 205 (0xCD) [Value] - Circle command Y
#ifndef _GRCIRCLEYCO
#define _GRCIRCLEYCO 205
#endif

// Decimal 207 (0xCF) [Value] - Renum increment value
#ifndef _BASRENUMVAL
#define _BASRENUMVAL 207
#endif

// Decimal 208 (0xD0) [Value] - Circle radius
#ifndef _GRCIRCLERADIUS
#define _GRCIRCLERADIUS 208
#endif

// Decimal 209 (0xD1) [Value] - Renum start line no
#ifndef _BASRENUMSTART
#define _BASRENUMSTART 209
#endif

// Decimal 211 (0xD3) [Value] - 2s complement of CLOADM offset
#ifndef _BASCLOADMOFFS
#define _BASCLOADMOFFS 211
#endif

// Decimal 213 (0xD5) [Value] - Renum start line number
#ifndef _BASRENUMSTARTLINE
#define _BASRENUMSTARTLINE 213
#endif

// Decimal 215 (0xD7) [Value] - Editor line length
#ifndef _BASEDITORLINELEN
#define _BASEDITORLINELEN 215
#endif

// Decimal 219 (0xDB) [Value] - Flag to tell if graphics screen has changed
#ifndef _GRDIRTYFLAG
#define _GRDIRTYFLAG 219
#endif

// Decimal 222 (0xDE) [Value] - Sound octave value for PLAY
#ifndef _SNDOCTAVE
#define _SNDOCTAVE 222
#endif

// Decimal 223 (0xDF) [Value] - Sound volume for PLAY
#ifndef _SNDVOLUME
#define _SNDVOLUME 223
#endif

// Decimal 225 (0xE1) [Value] - Note length for PLAY
#ifndef _SNDNOTELEN
#define _SNDNOTELEN 225
#endif

// Decimal 226 (0xE2) [Value] - Tempo for PLAY
#ifndef _SNDTEMPO
#define _SNDTEMPO 226
#endif

// Decimal 227 (0xE3) [Value] - Timer for the Play command
#ifndef _SNDTIMERPLAY
#define _SNDTIMERPLAY 227
#endif

// Decimal 229 (0xE5) [Value] - Dotted note scale factor for Play
#ifndef _SNDDOTNOTESCALE
#define _SNDDOTNOTESCALE 229
#endif

// Decimal 232 (0xE8) [Value] - Current angle for DRAW command
#ifndef _GRDRAWANGLE
#define _GRDRAWANGLE 232
#endif

// Decimal 233 (0xE9) [Value] - Current scale for DRAW command
#ifndef _GRDRAWSCALE
#define _GRDRAWSCALE 233
#endif

// Decimal 256 (0x100) [Value] - Secondary SWI3 vector JMP+ address
#ifndef _SECVECSWI3
#define _SECVECSWI3 256
#endif

// Decimal 259 (0x103) [Value] - Secondary SWI2 vector JMP+ address
#ifndef _SECVECSWI2
#define _SECVECSWI2 259
#endif

// Decimal 262 (0x106) [Value] - Secondary NMI vector JMP+ address
#ifndef _SECVECSWI
#define _SECVECSWI 262
#endif

// Decimal 265 (0x109) [Value] - Secondary NMI vector JMP+ address
#ifndef _SECVECNMI
#define _SECVECNMI 265
#endif

// Decimal 268 (0x10C) [Value] - Secondary IRQ vector JMP+ address
#ifndef _SECVECIRQ
#define _SECVECIRQ 268
#endif

// Decimal 271 (0x10F) [Value] - Secondary FIRQ vector JMP+ address
#ifndef _SECVECFIRQ
#define _SECVECFIRQ 271
#endif

// Decimal 274 (0x112) [Value] - Current value of system timer
#ifndef _SYSTIMEVAL
#define _SYSTIMEVAL 274
#endif

// Decimal 277 (0x115) [Value] - Random number seed for RND function
#ifndef _BASRANDOMSEED
#define _BASRANDOMSEED 277
#endif

// Decimal 288 (0x120) [Value] - Number of basic commands
#ifndef _BASNUMCMDS
#define _BASNUMCMDS 288
#endif

// Decimal 288 (0x120) [Value] - Basic Stub 0 (All basic on Dragon, Colour basic on Tandy)
#ifndef _BASSTUB0
#define _BASSTUB0 288
#endif

// Decimal 289 (0x121) [Value] - Address of basic command list
#ifndef _BASADDRCMDLIST
#define _BASADDRCMDLIST 289
#endif

// Decimal 291 (0x123) [Value] - Address of basic command dispatch
#ifndef _BASADDRCMDDISP
#define _BASADDRCMDDISP 291
#endif

// Decimal 293 (0x125) [Value] - Number of basic functions
#ifndef _BASNUMFUNCS
#define _BASNUMFUNCS 293
#endif

// Decimal 294 (0x126) [Value] - Address of basic function list
#ifndef _BASADDRFUNCLIST
#define _BASADDRFUNCLIST 294
#endif

// Decimal 296 (0x128) [Value] - Address of basic function dispatcher
#ifndef _BASADDRFUNCDISP
#define _BASADDRFUNCDISP 296
#endif

// Decimal 298 (0x12A) [Value] - Number of disk basic commands
#ifndef _BASNUMDSKCMDS
#define _BASNUMDSKCMDS 298
#endif

// Decimal 298 (0x12A) [Value] - Basic stub 1 (Disk basic on Dragon, Extended basic on Tandy)
#ifndef _BASSTUB1
#define _BASSTUB1 298
#endif

// Decimal 299 (0x12B) [Value] - Address of disk basic command list
#ifndef _BASADDRDSKCMDLIST
#define _BASADDRDSKCMDLIST 299
#endif

// Decimal 301 (0x12D) [Value] - Address of disk basic command dispatch
#ifndef _BASADDRDSKCMDDISP
#define _BASADDRDSKCMDDISP 301
#endif

// Decimal 303 (0x12F) [Value] - Number of disk basic functions
#ifndef _BASNUMDSKFUNCS
#define _BASNUMDSKFUNCS 303
#endif

// Decimal 304 (0x130) [Value] - Address of disk basic function list
#ifndef _BASADDRDSKFUNCLIST
#define _BASADDRDSKFUNCLIST 304
#endif

// Decimal 306 (0x132) [Value] - Address of disk basic function dispatcher
#ifndef _BASADDRDSKFUNCDISP
#define _BASADDRDSKFUNCDISP 306
#endif

// Decimal 308 (0x134) [Value] - USR vector tabl when basic not installed
#ifndef _BASUSRVECNODISK
#define _BASUSRVECNODISK 308
#endif

// Decimal 308 (0x134) [Value] - Basic Stub 2 (Null on dragon, Disk basic on Tandy)
#ifndef _BASSTUB2
#define _BASSTUB2 308
#endif

// Decimal 318 (0x13E) [Value] - Basic Stub 3 (do not use on dragon, user stub on Tandy)
#ifndef _BASSTUB3
#define _BASSTUB3 318
#endif

// Decimal 328 (0x148) [Value] - Printer auto EOL flag, nonzero will send EOL sequence at end of line
#ifndef _TEXTPRNAUTOCRLF
#define _TEXTPRNAUTOCRLF 328
#endif

// Decimal 329 (0x149) [Value] - Capslock flag, nonzero=uppercase
#ifndef _TEXTCAPSLOCK
#define _TEXTCAPSLOCK 329
#endif

// Decimal 330 (0x14A) [Value] - Number of characters in EOL sequence 1..4
#ifndef _TEXTPRNEOLCNT
#define _TEXTPRNEOLCNT 330
#endif

// Decimal 331 (0x14B) [Value] - End of line characters
#ifndef _TEXTPRNEOLSEQ
#define _TEXTPRNEOLSEQ 331
#endif

// Decimal 336 (0x150) [Value] - Rollover table, to check for key releases
#ifndef _TEXTKBDROLLOVER
#define _TEXTKBDROLLOVER 336
#endif

// Decimal 346 (0x15A) [Value] - Joystick(0) value
#ifndef _BASJOYVAL0
#define _BASJOYVAL0 346
#endif

// Decimal 347 (0x15B) [Value] - Joystick(1) value
#ifndef _BASJOYVAL1
#define _BASJOYVAL1 347
#endif

// Decimal 348 (0x15C) [Value] - Joystick(2) value
#ifndef _BASJOYVAL2
#define _BASJOYVAL2 348
#endif

// Decimal 349 (0x15D) [Value] - Joystick(3) value
#ifndef _BASJOYVAL3
#define _BASJOYVAL3 349
#endif

// Decimal 350 (0x15E) [Value] - Called before a device is opened
#ifndef _VECTDEVOPEN
#define _VECTDEVOPEN 350
#endif

// Decimal 350 (0x15E) [Value] - Base address of ram hooks/vectors
#ifndef _VECTBASE
#define _VECTBASE 350
#endif

// Decimal 353 (0x161) [Value] - Called when a device number is verified
#ifndef _VECTDEVNO
#define _VECTDEVNO 353
#endif

// Decimal 356 (0x164) [Value] - Called before initialising a device
#ifndef _VECTDEVINIT
#define _VECTDEVINIT 356
#endif

// Decimal 359 (0x167) [Value] - Called before outputting char in A to a device
#ifndef _VECTOUTCHAR
#define _VECTOUTCHAR 359
#endif

// Decimal 362 (0x16A) [Value] - Called before inputting a char to A
#ifndef _VECTINCHAR
#define _VECTINCHAR 362
#endif

// Decimal 365 (0x16D) [Value] - Called before inputting from a file
#ifndef _VECTINPUTFILE
#define _VECTINPUTFILE 365
#endif

// Decimal 368 (0x170) [Value] - Called before outputting to a file
#ifndef _VECTOUTPUTFILE
#define _VECTOUTPUTFILE 368
#endif

// Decimal 371 (0x173) [Value] - Called before closing all files
#ifndef _VECTCLOSEALLFILES
#define _VECTCLOSEALLFILES 371
#endif

// Decimal 374 (0x176) [Value] - Called before closing a file
#ifndef _VECTCLOSEFILE
#define _VECTCLOSEFILE 374
#endif

// Decimal 377 (0x179) [Value] - Called before interpreting a token in A
#ifndef _VECTCMDINTERP
#define _VECTCMDINTERP 377
#endif

// Decimal 380 (0x17C) [Value] - Called before re-requesing input from keyboard
#ifndef _VECTREREQESTIN
#define _VECTREREQESTIN 380
#endif

// Decimal 383 (0x17F) [Value] - Called before keyboard is scanned for BREAK,SHIFT-@
#ifndef _VECTCHECKKEYS
#define _VECTCHECKKEYS 383
#endif

// Decimal 386 (0x182) [Value] - Called before LINE INPUT is executed
#ifndef _VECTLINEINPUTFILE
#define _VECTLINEINPUTFILE 386
#endif

// Decimal 389 (0x185) [Value] - Called before closing an ASCII file read in as basic
#ifndef _VECTCLOSEFILECMD
#define _VECTCLOSEFILECMD 389
#endif

// Decimal 392 (0x188) [Value] - called before checking for end of file
#ifndef _VECTCHECKEOF
#define _VECTCHECKEOF 392
#endif

// Decimal 395 (0x18B) [Value] - Called before evaluating expression
#ifndef _VECTEVALUATEEXPR
#define _VECTEVALUATEEXPR 395
#endif

// Decimal 398 (0x18E) [Value] - Can be patched by user to trap error messages
#ifndef _VECTUSERERROR
#define _VECTUSERERROR 398
#endif

// Decimal 401 (0x191) [Value] - Can be patched by system to trap error messages
#ifndef _VECTSYSERROR
#define _VECTSYSERROR 401
#endif

// Decimal 404 (0x194) [Value] - Called when RUN about to be executed
#ifndef _VECTRUNLINK
#define _VECTRUNLINK 404
#endif

// Decimal 407 (0x197) [Value] - Called before changing BASIC memory vectors after LOAD etc
#ifndef _VECTRESETBASMEM
#define _VECTRESETBASMEM 407
#endif

// Decimal 410 (0x19A) [Value] - Called before fetching next command to be executed by BASIC
#ifndef _VECTGETNEXTCMD
#define _VECTGETNEXTCMD 410
#endif

// Decimal 413 (0x19D) [Value] - Called before assigning string to string variable
#ifndef _VECTASSIGNSTR
#define _VECTASSIGNSTR 413
#endif

// Decimal 416 (0x1A0) [Value] - Called before CLS, GET & PUT are executed
#ifndef _VECTACCESSSCREEN
#define _VECTACCESSSCREEN 416
#endif

// Decimal 419 (0x1A3) [Value] - Called before an ASCII line is tokenized
#ifndef _VECTTOKENIZE
#define _VECTTOKENIZE 419
#endif

// Decimal 422 (0x1A6) [Value] - Called before a line is de-tokenized
#ifndef _VECTDETOKENIZE
#define _VECTDETOKENIZE 422
#endif

// Decimal 425 (0x1A9) [Value] - String descriptor stack
#ifndef _BASSTRDESCSTACK
#define _BASSTRDESCSTACK 425
#endif

// Decimal 465 (0x1D1) [Value] - Length of cassette filename can be 0 to 8
#ifndef _CASFNAMELEN
#define _CASFNAMELEN 465
#endif

// Decimal 466 (0x1D2) [Value] - Cassete filename to search for or write out
#ifndef _CASFNAME
#define _CASFNAME 466
#endif

// Decimal 474 (0x1DA) [Value] - Filename found, when reading
#ifndef _CASFNAMEFOUND
#define _CASFNAMEFOUND 474
#endif

// Decimal 474 (0x1DA) [Value] - COS default IO buffer, if this contains filename block then folloing are valid
#ifndef _CASIOBUFF
#define _CASIOBUFF 474
#endif

// Decimal 482 (0x1E2) [Value] - File type 0=tokenized basic, 1=ASCII data, 2=Binary
#ifndef _CASFTYPE
#define _CASFTYPE 482
#endif

// Decimal 483 (0x1E3) [Value] - ASCII flag byte
#ifndef _CASASCIIFLAG
#define _CASASCIIFLAG 483
#endif

// Decimal 484 (0x1E4) [Value] - Gap flag byte
#ifndef _CASGAPFLAG
#define _CASGAPFLAG 484
#endif

// Decimal 485 (0x1E5) [Value] - Entry address for MC programs
#ifndef _CASENTRYADDR
#define _CASENTRYADDR 485
#endif

// Decimal 487 (0x1E7) [Value] - Load address
#ifndef _CASLOADADDR
#define _CASLOADADDR 487
#endif

// Decimal 730 (0x2DA) [Value] - Basic line input buffer header
#ifndef _BASLININPHEAD
#define _BASLININPHEAD 730
#endif

// Decimal 732 (0x2DC) [Value] - Basic line input buffer
#ifndef _BASLININPBUFF
#define _BASLININPBUFF 732
#endif

// Decimal 983 (0x3D7) [Value] - Basic buffer space
#ifndef _BASBUFFER
#define _BASBUFFER 983
#endif

// Decimal 1021 (0x3FD) [Value] - End of line delay for serial port on Dragon 64 & CoCo
#ifndef _TEXTSEREOLDELAY
#define _TEXTSEREOLDELAY 1021
#endif

// Decimal 1023 (0x3FF) [Value] - Dragon 64 printer selection flag, 0=paralell port, nonzero=RS232
#ifndef _TEXTPRNSELFLAG
#define _TEXTPRNSELFLAG 1023
#endif

// Decimal 32768 (0x8000) [Value] - Hardware initialisation
#ifndef _BASICHWINIT
#define _BASICHWINIT 32768
#endif

// Decimal 32771 (0x8003) [Value] - Software initialisation
#ifndef _BASICSWINIT
#define _BASICSWINIT 32771
#endif

// Decimal 32774 (0x8006) [Value] - Keyboard input
#ifndef _BASICKBDIN
#define _BASICKBDIN 32774
#endif

// Decimal 32777 (0x8009) [Value] - Cursor blink
#ifndef _BASICCURSORB
#define _BASICCURSORB 32777
#endif

// Decimal 32780 (0x800C) [Value] - Screen output
#ifndef _BASICSCREENOUT
#define _BASICSCREENOUT 32780
#endif

// Decimal 32783 (0x800F) [Value] - Printer output
#ifndef _BASICPRINTOUT
#define _BASICPRINTOUT 32783
#endif

// Decimal 32786 (0x8012) [Value] - Joystick input
#ifndef _BASICJOYIN
#define _BASICJOYIN 32786
#endif

// Decimal 32789 (0x8015) [Value] - Cassette player motor on
#ifndef _BASICCASSON
#define _BASICCASSON 32789
#endif

// Decimal 32792 (0x8018) [Value] - Cassette player motor off
#ifndef _BASICCASSOFF
#define _BASICCASSOFF 32792
#endif

// Decimal 32795 (0x801B) [Value] - Cassette write leader
#ifndef _BASICWRITELEAD
#define _BASICWRITELEAD 32795
#endif

// Decimal 32795 (0x801B) [Value] - Turn on motor and write out leader
#ifndef _CASWRITELEADER
#define _CASWRITELEADER 32795
#endif

// Decimal 32798 (0x801E) [Value] - Cassette byte output
#ifndef _BASICCASSBYOUT
#define _BASICCASSBYOUT 32798
#endif

// Decimal 32801 (0x8021) [Value] - Cassette on for reading
#ifndef _BASICCASSONRD
#define _BASICCASSONRD 32801
#endif

// Decimal 32804 (0x8024) [Value] - Cassette byte input
#ifndef _BASICCASSBYIN
#define _BASICCASSBYIN 32804
#endif

// Decimal 32807 (0x8027) [Value] - Cassette bit input
#ifndef _BASICCASSBITIN
#define _BASICCASSBITIN 32807
#endif

// Decimal 32810 (0x802A) [Value] - Read a byte from serial
#ifndef _BASICSERIN
#define _BASICSERIN 32810
#endif

// Decimal 32813 (0x802D) [Value] - Write a byte to serial port
#ifndef _BASICSEROUT
#define _BASICSEROUT 32813
#endif

// Decimal 32816 (0x8030) [Value] - Set baud rate
#ifndef _BASICSETBAUD
#define _BASICSETBAUD 32816
#endif

// Decimal 33449 (0x82A9) [Value] - List of 2 byte error codes eg 'SN' 'OM' 'UL' etc
#ifndef _BASERRORCODETABLE
#define _BASERRORCODETABLE 33449
#endif

// Decimal 33564 (0x831C) [Value] - Check memory space at top of arrays + move arrays
#ifndef _BASCHKARRSPACEMV
#define _BASCHKARRSPACEMV 33564
#endif

// Decimal 33585 (0x8331) [Value] - Check B*2 bytes free above Arrays, OM error if not
#ifndef _BASCHKB2FREE
#define _BASCHKB2FREE 33585
#endif

// Decimal 33602 (0x8342) [Value] - Print ?OM Error and return to basic
#ifndef _BASOMERROR
#define _BASOMERROR 33602
#endif

// Decimal 33604 (0x8344) [Value] - Report error code in B register, cleanup and return to basic
#ifndef _SYSERR
#define _SYSERR 33604
#endif

// Decimal 33630 (0x835E) [Value] - Report error in B, do NOT hook to RAM, or turn of cas etc
#ifndef _SYSERR2
#define _SYSERR2 33630
#endif

// Decimal 33649 (0x8371) [Value] - Return to command mode
#ifndef _BASCMDMODE
#define _BASCMDMODE 33649
#endif

// Decimal 33773 (0x83ED) [Value] - Finalises setup of basic vectors (after load), should be preceeded by call to BasVect1
#ifndef _BASVECT2
#define _BASVECT2 33773
#endif

// Decimal 33791 (0x83FF) [Value] - Find a line number in basic program
#ifndef _BASFINDLINENO
#define _BASFINDLINENO 33791
#endif

// Decimal 33813 (0x8415) [Value] - Basic Command
#ifndef _CMDNEW
#define _CMDNEW 33813
#endif

// Decimal 33815 (0x8417) [Value] - Remove current basic program from meory, like NEW command
#ifndef _BASNEW
#define _BASNEW 33815
#endif

// Decimal 33823 (0x841F) [Value] - Sets up various basic vectors (after load), should be followed by call to BasVect2
#ifndef _BASVECT1
#define _BASVECT1 33823
#endif

// Decimal 33844 (0x8434) [Value] - Reset basic stack to initial position
#ifndef _BASRESETSTACK
#define _BASRESETSTACK 33844
#endif

// Decimal 33864 (0x8448) [Value] - Basic Command
#ifndef _CMDFOR
#define _CMDFOR 33864
#endif

// Decimal 33951 (0x849F) [Value] - Run basic program in memory, like RUN
#ifndef _BASRUN
#define _BASRUN 33951
#endif

// Decimal 34010 (0x84DA) [Value] - BRA to main loop, used by DOS
#ifndef _BASBRARUN
#define _BASBRARUN 34010
#endif

// Decimal 34029 (0x84ED) [Value] - Do command dispatech, X must point to dispatch table
#ifndef _BASDODIPATCH
#define _BASDODIPATCH 34029
#endif

// Decimal 34068 (0x8514) [Value] - Basic Command
#ifndef _CMDRESTORE
#define _CMDRESTORE 34068
#endif

// Decimal 34075 (0x851B) [Value] - Basic, poll keyboard and check for break
#ifndef _BASPOLLKEYBOARD
#define _BASPOLLKEYBOARD 34075
#endif

// Decimal 34091 (0x852B) [Value] - Wait for a keypress, calls TextScanKbd, also handles break
#ifndef _TEXTWAITKEY
#define _TEXTWAITKEY 34091
#endif

// Decimal 34098 (0x8532) [Value] - Basic Command
#ifndef _CMDEND
#define _CMDEND 34098
#endif

// Decimal 34105 (0x8539) [Value] - Basic Command
#ifndef _CMDSTOP
#define _CMDSTOP 34105
#endif

// Decimal 34144 (0x8560) [Value] - Basic Command
#ifndef _CMDCONT
#define _CMDCONT 34144
#endif

// Decimal 34161 (0x8571) [Value] - Basic Command
#ifndef _CMDCLEAR
#define _CMDCLEAR 34161
#endif

// Decimal 34213 (0x85A5) [Value] - Basic Command
#ifndef _CMDRUN
#define _CMDRUN 34213
#endif

// Decimal 34233 (0x85B9) [Value] - Basic Command
#ifndef _CMDGO
#define _CMDGO 34233
#endif

// Decimal 34279 (0x85E7) [Value] - Skip past line no in basic line, UL error if no line no.
#ifndef _BASSKIPLINENO
#define _BASSKIPLINENO 34279
#endif

// Decimal 34286 (0x85EE) [Value] - Sets basic program pointer to X-1
#ifndef _BASSETPROGPTRX
#define _BASSETPROGPTRX 34286
#endif

// Decimal 34291 (0x85F3) [Value] - Basic Command
#ifndef _CMDRETURN
#define _CMDRETURN 34291
#endif

// Decimal 34323 (0x8613) [Value] - Basic Command
#ifndef _CMDDATA
#define _CMDDATA 34323
#endif

// Decimal 34326 (0x8616) [Value] - Basic Command
#ifndef _CMDREM
#define _CMDREM 34326
#endif

// Decimal 34375 (0x8647) [Value] - Basic Command
#ifndef _CMDIF
#define _CMDIF 34375
#endif

// Decimal 34421 (0x8675) [Value] - Basic Command
#ifndef _CMDON
#define _CMDON 34421
#endif

// Decimal 34458 (0x869A) [Value] - Get line no and store in BasTempLine
#ifndef _BASGETLINENO
#define _BASGETLINENO 34458
#endif

// Decimal 34492 (0x86BC) [Value] - Basic Command
#ifndef _CMDLET
#define _CMDLET 34492
#endif

// Decimal 34603 (0x872B) [Value] - Basic Command
#ifndef _CMDINPUT
#define _CMDINPUT 34603
#endif

// Decimal 34679 (0x8777) [Value] - Basic Command
#ifndef _CMDREAD
#define _CMDREAD 34679
#endif

// Decimal 34682 (0x877A) [Value] - As basic READ command but ptr in X supplied by caller
#ifndef _CMDREADFROMX
#define _CMDREADFROMX 34682
#endif

// Decimal 34857 (0x8829) [Value] - Basic Command
#ifndef _CMDNEXT
#define _CMDNEXT 34857
#endif

// Decimal 34932 (0x8874) [Value] - Evaluate and put the VARPTR of experssion which follows in BasVarAssign16 (carry clear)
#ifndef _VARGETEXPRCC
#define _VARGETEXPRCC 34932
#endif

// Decimal 34935 (0x8877) [Value] - Evaluate and put the VARPTR of experssion which follows in BasVarAssign16 (carry set)
#ifndef _VARGETEXPR
#define _VARGETEXPR 34935
#endif

// Decimal 34946 (0x8882) [Value] - Print ?TM Error and return to basic
#ifndef _BASTMERROR
#define _BASTMERROR 34946
#endif

// Decimal 34951 (0x8887) [Value] - Compiles string and moves to free string space, should be followed by VarGetExpr
#ifndef _VARGETSTR
#define _VARGETSTR 34951
#endif

// Decimal 35236 (0x89A4) [Value] - Check for Close bracket ')' in command line, SNError if not
#ifndef _VARCKCLBRAC
#define _VARCKCLBRAC 35236
#endif

// Decimal 35239 (0x89A7) [Value] - Check for Open bracket '(' in command line, SNError if not
#ifndef _VARCKOPBRAC
#define _VARCKOPBRAC 35239
#endif

// Decimal 35242 (0x89AA) [Value] - Check for Comma in command line, SNError if not
#ifndef _VARCKCOMMA
#define _VARCKCOMMA 35242
#endif

// Decimal 35244 (0x89AC) [Value] - Check for char in B register in command line, SNError if not
#ifndef _VARCKCHAR
#define _VARCKCHAR 35244
#endif

// Decimal 35252 (0x89B4) [Value] - Print ?SN Error and return to basic
#ifndef _BASSNERROR
#define _BASSNERROR 35252
#endif

// Decimal 35345 (0x8A11) [Value] - Basic Command
#ifndef _CMDOR
#define _CMDOR 35345
#endif

// Decimal 35346 (0x8A12) [Value] - Basic Command
#ifndef _CMDAND
#define _CMDAND 35346
#endif

// Decimal 35467 (0x8A8B) [Value] - Basic Command
#ifndef _CMDDIM
#define _CMDDIM 35467
#endif

// Decimal 35476 (0x8A94) [Value] - Gets VARPTR address of following name and places in BasVarPtrLast
#ifndef _VARGETVAR
#define _VARGETVAR 35476
#endif

// Decimal 35625 (0x8B29) [Value] - Returns argument to USRnn as a 16bit no in D
#ifndef _VARGETUSR
#define _VARGETUSR 35625
#endif

// Decimal 35725 (0x8B8D) [Value] - Print ?FC Error and return to basic
#ifndef _BASFCERROR
#define _BASFCERROR 35725
#endif

// Decimal 35889 (0x8C31) [Value] - Basic Command
#ifndef _CMDMEM
#define _CMDMEM 35889
#endif

// Decimal 35893 (0x8C35) [Value] - Assigns value in D register to a variable, and returns to basic
#ifndef _VARASSIGN16BIT
#define _VARASSIGN16BIT 35893
#endif

// Decimal 35894 (0x8C36) [Value] - Assigns value in B register to a variable, and returns to basic
#ifndef _VARASSIGN8BIT
#define _VARASSIGN8BIT 35894
#endif

// Decimal 35895 (0x8C37) [Value] - Assigns value in D register to a variable, and returns to basic (1 less instruction!).
#ifndef _VARASSIGN16BIT2
#define _VARASSIGN16BIT2 35895
#endif

// Decimal 35904 (0x8C40) [Value] - Basic Command
#ifndef _CMDSTRS
#define _CMDSTRS 35904
#endif

// Decimal 35922 (0x8C52) [Value] - Reserve B bytes of string space return start in X, setup low mem vars
#ifndef _BASRESSTR
#define _BASRESSTR 35922
#endif

// Decimal 36019 (0x8CB3) [Value] - Reserve B bytes of string space return start in X
#ifndef _BASRESSTR2
#define _BASRESSTR2 36019
#endif

// Decimal 36055 (0x8CD7) [Value] - Forces garbage collection in string space
#ifndef _VARGARBAGECOLLECT
#define _VARGARBAGECOLLECT 36055
#endif

// Decimal 36250 (0x8D9A) [Value] - Get string len in B and address in X of string desc in FPA2
#ifndef _BASGETSTRLENADDR
#define _BASGETSTRLENADDR 36250
#endif

// Decimal 36255 (0x8D9F) [Value] - Frees up storage used by a variable
#ifndef _VARDELVAR
#define _VARDELVAR 36255
#endif

// Decimal 36295 (0x8DC7) [Value] - Basic Command
#ifndef _CMDLEN
#define _CMDLEN 36295
#endif

// Decimal 36306 (0x8DD2) [Value] - Basic Command
#ifndef _CMDCHRS
#define _CMDCHRS 36306
#endif

// Decimal 36326 (0x8DE6) [Value] - Basic Command
#ifndef _CMDASC
#define _CMDASC 36326
#endif

// Decimal 36330 (0x8DEA) [Value] - Get first character of string into B
#ifndef _BASGETSTRFIRST
#define _BASGETSTRFIRST 36330
#endif

// Decimal 36337 (0x8DF1) [Value] - Basic Command
#ifndef _CMDLEFTS
#define _CMDLEFTS 36337
#endif

// Decimal 36366 (0x8E0E) [Value] - Basic Command
#ifndef _CMDRIGHTS
#define _CMDRIGHTS 36366
#endif

// Decimal 36373 (0x8E15) [Value] - Basic Command
#ifndef _CMDMIDS
#define _CMDMIDS 36373
#endif

// Decimal 36433 (0x8E51) [Value] - Returns value of variable in B,FCError if more than 8 bits
#ifndef _VARGET8BIT
#define _VARGET8BIT 36433
#endif

// Decimal 36444 (0x8E5C) [Value] - Basic Command
#ifndef _CMDVAL
#define _CMDVAL 36444
#endif

// Decimal 36478 (0x8E7E) [Value] - Checks for comman then gets 8 bit.
#ifndef _VARGETCOMMA8
#define _VARGETCOMMA8 36478
#endif

// Decimal 36483 (0x8E83) [Value] - Returns value of variable in D,FCError if more than 16 bits
#ifndef _VARGET16BIT
#define _VARGET16BIT 36483
#endif

// Decimal 36502 (0x8E96) [Value] - Basic Command
#ifndef _CMDPEEK
#define _CMDPEEK 36502
#endif

// Decimal 36509 (0x8E9D) [Value] - Basic Command
#ifndef _CMDPOKE
#define _CMDPOKE 36509
#endif

// Decimal 36516 (0x8EA4) [Value] - Basic Command
#ifndef _CMDLLIST
#define _CMDLLIST 36516
#endif

// Decimal 36522 (0x8EAA) [Value] - Basic Command
#ifndef _CMDLIST
#define _CMDLIST 36522
#endif

// Decimal 36522 (0x8EAA) [Value] - List basic program to SysDevN A must be 0 on entry
#ifndef _BASLIST
#define _BASLIST 36522
#endif

// Decimal 36925 (0x903D) [Value] - Basic Command
#ifndef _CMDPRINT
#define _CMDPRINT 36925
#endif

// Decimal 37025 (0x90A1) [Value] - Outputs an EOL sequence to the screen
#ifndef _TEXTOUTCRLF
#define _TEXTOUTCRLF 37025
#endif

// Decimal 37093 (0x90E5) [Value] - Outputs string pointed to by X to screen, X should point to byte before first byte of string
#ifndef _TEXTOUTSTRING
#define _TEXTOUTSTRING 37093
#endif

// Decimal 37109 (0x90F5) [Value] - Outputs a space to screen
#ifndef _TEXTOUTSPACE
#define _TEXTOUTSPACE 37109
#endif

// Decimal 37112 (0x90F8) [Value] - Outputs a question mark to screen
#ifndef _TEXTOUTQUESTION
#define _TEXTOUTQUESTION 37112
#endif

// Decimal 37125 (0x9105) [Value] - Basic Command
#ifndef _CMDMINUS
#define _CMDMINUS 37125
#endif

// Decimal 37134 (0x910E) [Value] - Basic Command
#ifndef _CMDPLUS
#define _CMDPLUS 37134
#endif

// Decimal 37221 (0x9165) [Value] - Normalize FPA0
#ifndef _VARNORMFPA0
#define _VARNORMFPA0 37221
#endif

// Decimal 37436 (0x923C) [Value] - Basic Command
#ifndef _CMDLOG
#define _CMDLOG 37436
#endif

// Decimal 37493 (0x9275) [Value] - Basic Command
#ifndef _CMDMULTIPLY
#define _CMDMULTIPLY 37493
#endif

// Decimal 37692 (0x933C) [Value] - Basic Command
#ifndef _CMDDIVIDE
#define _CMDDIVIDE 37692
#endif

// Decimal 37925 (0x9425) [Value] - Basic Command
#ifndef _CMDSGN
#define _CMDSGN 37925
#endif

// Decimal 37950 (0x943E) [Value] - Basic Command
#ifndef _CMDABS
#define _CMDABS 37950
#endif

// Decimal 38041 (0x9499) [Value] - Basic Command
#ifndef _CMDINT
#define _CMDINT 38041
#endif

// Decimal 38266 (0x957A) [Value] - Outputs unsigned integer in D to the TextDevN device
#ifndef _TEXTOUTNUM16
#define _TEXTOUTNUM16 38266
#endif

// Decimal 38274 (0x9582) [Value] - Outputs number in FPA0 to screen
#ifndef _TEXTOUTNUMFPA0
#define _TEXTOUTNUMFPA0 38274
#endif

// Decimal 38551 (0x9697) [Value] - Basic Command
#ifndef _CMDSQR
#define _CMDSQR 38551
#endif

// Decimal 38560 (0x96A0) [Value] - Basic Command
#ifndef _CMDEXPONET
#define _CMDEXPONET 38560
#endif

// Decimal 38675 (0x9713) [Value] - Basic Command
#ifndef _CMDEXP
#define _CMDEXP 38675
#endif

// Decimal 38770 (0x9772) [Value] - Basic Command
#ifndef _CMDRND
#define _CMDRND 38770
#endif

// Decimal 38798 (0x978E) [Value] - Generate an 8 bit random number and place in BasRandomSeed+1
#ifndef _BASRANDOM8
#define _BASRANDOM8 38798
#endif

// Decimal 38859 (0x97CB) [Value] - Basic Command
#ifndef _CMDCOS
#define _CMDCOS 38859
#endif

// Decimal 38865 (0x97D1) [Value] - Basic Command
#ifndef _CMDSIN
#define _CMDSIN 38865
#endif

// Decimal 38934 (0x9816) [Value] - Basic Command
#ifndef _CMDTAN
#define _CMDTAN 38934
#endif

// Decimal 39031 (0x9877) [Value] - Basic Command
#ifndef _CMDATN
#define _CMDATN 39031
#endif

// Decimal 39195 (0x991B) [Value] - Write a binary file out push return address, then start,end and entry addresses and then JMP to this
#ifndef _CASWRITEBIN
#define _CASWRITEBIN 39195
#endif

// Decimal 39254 (0x9956) [Value] - Basic Command
#ifndef _CMDFIX
#define _CMDFIX 39254
#endif

// Decimal 39269 (0x9965) [Value] - Basic Command
#ifndef _CMDEDIT
#define _CMDEDIT 39269
#endif

// Decimal 39641 (0x9AD9) [Value] - Basic Command
#ifndef _CMDTRON
#define _CMDTRON 39641
#endif

// Decimal 39642 (0x9ADA) [Value] - Basic Command
#ifndef _CMDTROFF
#define _CMDTROFF 39642
#endif

// Decimal 39646 (0x9ADE) [Value] - Basic Command
#ifndef _CMDPOS
#define _CMDPOS 39646
#endif

// Decimal 39668 (0x9AF4) [Value] - Basic Command
#ifndef _CMDVARPTR
#define _CMDVARPTR 39668
#endif

// Decimal 39812 (0x9B84) [Value] - Basic Command
#ifndef _CMDSTRINGS
#define _CMDSTRINGS 39812
#endif

// Decimal 39860 (0x9BB4) [Value] - Basic Command
#ifndef _CMDINSTR
#define _CMDINSTR 39860
#endif

// Decimal 39998 (0x9C3E) [Value] - Assigns value in BasVarAssign16 to a variable, and returns to basic
#ifndef _VARASSIGN16BITB
#define _VARASSIGN16BITB 39998
#endif

// Decimal 40054 (0x9C76) [Value] - Check for direct mode, ID Error if so
#ifndef _BASCHKDIRECT
#define _BASCHKDIRECT 40054
#endif

// Decimal 40065 (0x9C81) [Value] - Basic Command
#ifndef _CMDDEF
#define _CMDDEF 40065
#endif

// Decimal 40221 (0x9D1D) [Value] - Basic Command
#ifndef _CMDUSR
#define _CMDUSR 40221
#endif

// Decimal 40253 (0x9D3D) [Value] - Basic IRQ routine, increments timer
#ifndef _BASIRQVEC
#define _BASIRQVEC 40253
#endif

// Decimal 40281 (0x9D59) [Value] - Basic Command
#ifndef _CMDTIMER
#define _CMDTIMER 40281
#endif

// Decimal 40289 (0x9D61) [Value] - Basic Command
#ifndef _CMDDELETE
#define _CMDDELETE 40289
#endif

// Decimal 40369 (0x9DB1) [Value] - Line input command
#ifndef _CMDLINEINPUT
#define _CMDLINEINPUT 40369
#endif

// Decimal 40409 (0x9DD9) [Value] - Entry into LINE INPUT routine, used by DOS
#ifndef _BASLINEINPUTENTRY
#define _BASLINEINPUTENTRY 40409
#endif

// Decimal 40442 (0x9DFA) [Value] - Basic Command
#ifndef _CMDRENUM
#define _CMDRENUM 40442
#endif

// Decimal 40960 (0xA000) [Value] - Indirect keyboard input jsr()
#ifndef _INDKEYINPUT
#define _INDKEYINPUT 40960
#endif

// Decimal 40962 (0xA002) [Value] - Indirect Character output
#ifndef _INDCHAROUTPUT
#define _INDCHAROUTPUT 40962
#endif

// Decimal 40964 (0xA004) [Value] - Indirect prepare cassette for read
#ifndef _INDCASONREAD
#define _INDCASONREAD 40964
#endif

// Decimal 40966 (0xA006) [Value] - Indirect Read cassette block
#ifndef _INDCASBLOCKIN
#define _INDCASBLOCKIN 40966
#endif

// Decimal 40968 (0xA008) [Value] - Indirect Write cassete block
#ifndef _INDCASBLOCKOUT
#define _INDCASBLOCKOUT 40968
#endif

// Decimal 40970 (0xA00A) [Value] - Indirect joystick in
#ifndef _INDJOYSTICKIN
#define _INDJOYSTICKIN 40970
#endif

// Decimal 40972 (0xA00C) [Value] - Indirect Write cassette leader
#ifndef _INDCASWRITELEAD
#define _INDCASWRITELEAD 40972
#endif

// Decimal 40974 (0xA00E) [Value] - Basic Command
#ifndef _CMDHEXS
#define _CMDHEXS 40974
#endif

// Decimal 41033 (0xA049) [Value] - Basic Command
#ifndef _CMDDLOAD
#define _CMDDLOAD 41033
#endif

// Decimal 41194 (0xA0EA) [Value] - Same as TextWaitKey, but with cursor
#ifndef _TEXTWAITKEYCURS
#define _TEXTWAITKEYCURS 41194
#endif

// Decimal 42603 (0xA66B) [Value] - Pixel mask table 2 colour mode
#ifndef _PIXMASKTABLE2COL
#define _PIXMASKTABLE2COL 42603
#endif

// Decimal 42611 (0xA673) [Value] - Pixel mask table 4 colour mode
#ifndef _PIXMASKTABLE4COL
#define _PIXMASKTABLE4COL 42611
#endif

// Decimal 42695 (0xA6C7) [Value] - Basic Command
#ifndef _CMDPPOINT
#define _CMDPPOINT 42695
#endif

// Decimal 42735 (0xA6EF) [Value] - Basic Command
#ifndef _CMDPSET
#define _CMDPSET 42735
#endif

// Decimal 42739 (0xA6F3) [Value] - Basic Command
#ifndef _CMDPRESET
#define _CMDPRESET 42739
#endif

// Decimal 42825 (0xA749) [Value] - Basic Command
#ifndef _CMDLINE
#define _CMDLINE 42825
#endif

// Decimal 43200 (0xA8C0) [Value] - Basic Command
#ifndef _CMDPCLS
#define _CMDPCLS 43200
#endif

// Decimal 43207 (0xA8C7) [Value] - Clears grapics screen to value in B
#ifndef _GRCLEARGRSCREEN
#define _GRCLEARGRSCREEN 43207
#endif

// Decimal 43220 (0xA8D4) [Value] - Basic Command
#ifndef _CMDCOLOR
#define _CMDCOLOR 43220
#endif

// Decimal 43304 (0xA928) [Value] - Sets up colours in low memory
#ifndef _GRSETCOLOURS
#define _GRSETCOLOURS 43304
#endif

// Decimal 43320 (0xA938) [Value] - Sets Text or Graphics screen, if Z=1 then text
#ifndef _GRSELECTDISPLAY
#define _GRSELECTDISPLAY 43320
#endif

// Decimal 43322 (0xA93A) [Value] - Resets to text mode and screen base address of $400
#ifndef _TEXTRESETVDU
#define _TEXTRESETVDU 43322
#endif

// Decimal 43401 (0xA989) [Value] - Set VDG to mode in A register
#ifndef _GRSETVDGMODE
#define _GRSETVDGMODE 43401
#endif

// Decimal 43421 (0xA99D) [Value] - Set VDG offset to page in A
#ifndef _GRSETVDGOFFSET
#define _GRSETVDGOFFSET 43421
#endif

// Decimal 43428 (0xA9A4) [Value] - Select colour set from data in GrColourSet
#ifndef _GRSELECTVDGCOLSET
#define _GRSELECTVDGCOLSET 43428
#endif

// Decimal 43439 (0xA9AF) [Value] - Basic Command
#ifndef _CMDPMODE
#define _CMDPMODE 43439
#endif

// Decimal 43489 (0xA9E1) [Value] - On entry B contains Pmode page to be used
#ifndef _GRSELECTPAGE
#define _GRSELECTPAGE 43489
#endif

// Decimal 43518 (0xA9FE) [Value] - Basic Command
#ifndef _CMDSCREEN
#define _CMDSCREEN 43518
#endif

// Decimal 43536 (0xAA10) [Value] - Selects colour set dependent on B
#ifndef _GRSELECTCOLOURSET
#define _GRSELECTCOLOURSET 43536
#endif

// Decimal 43545 (0xAA19) [Value] - Basic Command
#ifndef _CMDPCLEAR
#define _CMDPCLEAR 43545
#endif

// Decimal 43555 (0xAA23) [Value] - Reserves memory for graphics, no graphics pages in B
#ifndef _GRRESERVEGRRAM
#define _GRRESERVEGRRAM 43555
#endif

// Decimal 43655 (0xAA87) [Value] - Initialise beginning of basic after graphics screen, no of pages in A
#ifndef _BASLOCATESCREEN
#define _BASLOCATESCREEN 43655
#endif

// Decimal 43710 (0xAABE) [Value] - Basic Command
#ifndef _CMDPCOPY
#define _CMDPCOPY 43710
#endif

// Decimal 43760 (0xAAF0) [Value] - Basic Command
#ifndef _CMDGET
#define _CMDGET 43760
#endif

// Decimal 43763 (0xAAF3) [Value] - Basic Command
#ifndef _CMDPUT
#define _CMDPUT 43763
#endif

// Decimal 44167 (0xAC87) [Value] - Basic Command
#ifndef _CMDPAINT
#define _CMDPAINT 44167
#endif

// Decimal 44477 (0xADBD) [Value] - Basic Command
#ifndef _CMDPLAY
#define _CMDPLAY 44477
#endif

// Decimal 44698 (0xAE9A) [Value] - Plays a note from the A register (ASCII)
#ifndef _SNDPLAYNOTE
#define _SNDPLAYNOTE 44698
#endif

// Decimal 45137 (0xB051) [Value] - Draw on pmode screen as in DRAW command
#ifndef _GRDRAW
#define _GRDRAW 45137
#endif

// Decimal 45137 (0xB051) [Value] - Basic Command
#ifndef _CMDDRAW
#define _CMDDRAW 45137
#endif

// Decimal 45624 (0xB238) [Value] - Basic Command
#ifndef _CMDCIRCLE
#define _CMDCIRCLE 45624
#endif

// Decimal 46004 (0xB3B4) [Value] - Perform soft reset, as if reset button pressed
#ifndef _SYSRESET
#define _SYSRESET 46004
#endif

// Decimal 46080 (0xB400) [Value] - Restart basic, as if power on, also deletes current program
#ifndef _BASBOOTBASIC
#define _BASBOOTBASIC 46080
#endif

// Decimal 46159 (0xB44F) [Value] - Warm start routine
#ifndef _WARMSTART
#define _WARMSTART 46159
#endif

// Decimal 46258 (0xB4B2) [Value] - Signon message address, for CoCo this is for Extended basic.
#ifndef _BASSIGNONMESS
#define _BASSIGNONMESS 46258
#endif

// Decimal 46341 (0xB505) [Value] - Same as TextWaitKey, but with cursor
#ifndef _TEXTWAITKEYCURS2
#define _TEXTWAITKEYCURS2 46341
#endif

// Decimal 46410 (0xB54A) [Value] - Outputs character in A to screen
#ifndef _TEXTOUTCHAR
#define _TEXTOUTCHAR 46410
#endif

// Decimal 46547 (0xB5D3) [Value] - Read input buffer at X as basic input
#ifndef _BASINBUFFFROMX
#define _BASINBUFFFROMX 46547
#endif

// Decimal 46669 (0xB64D) [Value] - Basic Command
#ifndef _CMDCLOSE
#define _CMDCLOSE 46669
#endif

// Decimal 46687 (0xB65F) [Value] - Close any open cassete file
#ifndef _CASCLOSFILES
#define _CASCLOSFILES 46687
#endif

// Decimal 46723 (0xB683) [Value] - Basic Command
#ifndef _CMDCSAVE
#define _CMDCSAVE 46723
#endif

// Decimal 46757 (0xB6A5) [Value] - Write tokenized basic program out, similar to CSAVE
#ifndef _CASWRITEBASIC
#define _CASWRITEBASIC 46757
#endif

// Decimal 46805 (0xB6D5) [Value] - Basic Command
#ifndef _CMDCLOAD
#define _CMDCLOAD 46805
#endif

// Decimal 46920 (0xB748) [Value] - Read in a binary file, similar to CLOADM
#ifndef _CASREADBIN
#define _CASREADBIN 46920
#endif

// Decimal 46961 (0xB771) [Value] - Basic Command
#ifndef _CMDEXEC
#define _CMDEXEC 46961
#endif

// Decimal 46999 (0xB797) [Value] - Basic Command
#ifndef _CMDINKEYS
#define _CMDINKEYS 46999
#endif

// Decimal 47052 (0xB7CC) [Value] - Copy B bytes from X to U
#ifndef _UTILCOPYBXTOU
#define _UTILCOPYBXTOU 47052
#endif

// Decimal 47060 (0xB7D4) [Value] - Get dev no from line & validate
#ifndef _BASGETDEVNO
#define _BASGETDEVNO 47060
#endif

// Decimal 47105 (0xB801) [Value] - Basic Command
#ifndef _CMDEOF
#define _CMDEOF 47105
#endif

// Decimal 47135 (0xB81F) [Value] - Basic Command
#ifndef _CMDSKIPF
#define _CMDSKIPF 47135
#endif

// Decimal 47145 (0xB829) [Value] - Basic Command
#ifndef _CMDOPEN
#define _CMDOPEN 47145
#endif

// Decimal 47157 (0xB835) [Value] - Entry into Basic open command used by Dragon/SuperDos
#ifndef _CMDOPENENTRY
#define _CMDOPENENTRY 47157
#endif

// Decimal 47176 (0xB848) [Value] - Print ?FM Error and return to basic
#ifndef _BASFMERROR
#define _BASFMERROR 47176
#endif

// Decimal 47283 (0xB8B3) [Value] - Searches a tape for specified filename
#ifndef _CASFINDFILE
#define _CASFINDFILE 47283
#endif

// Decimal 47411 (0xB933) [Value] - Turns on motor, reads header and then first block into CasIOBufAddr
#ifndef _CASREADBLOCK1
#define _CASREADBLOCK1 47411
#endif

// Decimal 47422 (0xB93E) [Value] - Reads a block into the cassete buffer pointed to by CasIOBuffAddr
#ifndef _CASBLOCKIN
#define _CASBLOCKIN 47422
#endif

// Decimal 47490 (0xB982) [Value] - Basic Command
#ifndef _CMDMOTOR
#define _CMDMOTOR 47490
#endif

// Decimal 47505 (0xB991) [Value] - Turn on motor, write leader and then first block
#ifndef _CASWRITEBLOCK1
#define _CASWRITEBLOCK1 47505
#endif

// Decimal 47513 (0xB999) [Value] - Write a block to cassete pointed to by CasIOBuffAddr
#ifndef _CASBLOCKOUT
#define _CASBLOCKOUT 47513
#endif

// Decimal 47571 (0xB9D3) [Value] - Basic Command
#ifndef _CMDSET
#define _CMDSET 47571
#endif

// Decimal 47583 (0xB9DF) [Value] - Sets lo res pixel
#ifndef _GRSETLRGPIXEL
#define _GRSETLRGPIXEL 47583
#endif

// Decimal 47620 (0xBA04) [Value] - Basic Command
#ifndef _CMDRESET
#define _CMDRESET 47620
#endif

// Decimal 47623 (0xBA07) [Value] - ReSets lo res pixel
#ifndef _GRRESETLRGPIXEL
#define _GRRESETLRGPIXEL 47623
#endif

// Decimal 47656 (0xBA28) [Value] - Calculates Lo-res pixel pos from data on stack
#ifndef _GRCALCPIXELPOS
#define _GRCALCPIXELPOS 47656
#endif

// Decimal 47685 (0xBA45) [Value] - Basic Command
#ifndef _CMDPOINT
#define _CMDPOINT 47685
#endif

// Decimal 47712 (0xBA60) [Value] - Basic Command
#ifndef _CMDCLS
#define _CMDCLS 47712
#endif

// Decimal 47735 (0xBA77) [Value] - Clear text mode screen, resets cursor to top left
#ifndef _TEXTCLS
#define _TEXTCLS 47735
#endif

// Decimal 47737 (0xBA79) [Value] - Clears srcrren to character in B register & resets cursor
#ifndef _TEXTCLSCHAR
#define _TEXTCLSCHAR 47737
#endif

// Decimal 47771 (0xBA9B) [Value] - Basic Command
#ifndef _CMDSOUND
#define _CMDSOUND 47771
#endif

// Decimal 47776 (0xBAA0) [Value] - Play a beep duration in B, frequency in SndPitch
#ifndef _SNDBEEP
#define _SNDBEEP 47776
#endif

// Decimal 47811 (0xBAC3) [Value] - Disables D/A sound output
#ifndef _SNDDISABLE
#define _SNDDISABLE 47811
#endif

// Decimal 47811 (0xBAC3) [Value] - Turn off audio from cassette
#ifndef _CASAUDIOOFF
#define _CASAUDIOOFF 47811
#endif

// Decimal 47813 (0xBAC5) [Value] - Enables D/A sound output
#ifndef _SNDENABLE
#define _SNDENABLE 47813
#endif

// Decimal 47828 (0xBAD4) [Value] - Reset D/A converter to $7E
#ifndef _SYSRESETDA
#define _SYSRESETDA 47828
#endif

// Decimal 47830 (0xBAD6) [Value] - Write value in A to D/A, bits 0 &1 should be 0
#ifndef _SYSWRITEDA
#define _SYSWRITEDA 47830
#endif

// Decimal 47839 (0xBADF) [Value] - Basic Command
#ifndef _CMDAUDIO
#define _CMDAUDIO 47839
#endif

// Decimal 47852 (0xBAEC) [Value] - Turn on Audio from cassete to speaker
#ifndef _CASAUDIOON
#define _CASAUDIOON 47852
#endif

// Decimal 47853 (0xBAED) [Value] - Turn on audio to D/A converter
#ifndef _SNDDTOAON
#define _SNDDTOAON 47853
#endif

// Decimal 47885 (0xBB0D) [Value] - Basic Command
#ifndef _CMDJOYSTK
#define _CMDJOYSTK 47885
#endif

// Decimal 48000 (0xBB80) [Value] - Dragon 64 only, boots basic into all ram mode, with 48K available to basic.
#ifndef _SYSBOOT64
#define _SYSBOOT64 48000
#endif

// Decimal 48053 (0xBBB5) [Value] - Decrements TextCursFlashCnt, if zero resets and flashes cursor
#ifndef _TEXTUPDATECURS
#define _TEXTUPDATECURS 48053
#endif

// Decimal 48101 (0xBBE5) [Value] - Scan keyboard, return Char in A, Zero flag set if no key
#ifndef _TEXTSCANKBD
#define _TEXTSCANKBD 48101
#endif

// Decimal 48288 (0xBCA0) [Value] - Clears a VDU line from current cursor pos to EOL
#ifndef _TEXTCLEARLINE
#define _TEXTCLEARLINE 48288
#endif

// Decimal 48299 (0xBCAB) [Value] - Outputs Char in A to VDU, does not reset screen.
#ifndef _TEXTVDUOUT
#define _TEXTVDUOUT 48299
#endif

// Decimal 48373 (0xBCF5) [Value] - Sends character in A register to printer (uncooked)
#ifndef _PRINTERDIROUT
#define _PRINTERDIROUT 48373
#endif

// Decimal 48394 (0xBD0A) [Value] - Moves printer head to next line.
#ifndef _PRINTERCRLF
#define _PRINTERCRLF 48394
#endif

// Decimal 48410 (0xBD1A) [Value] - Sends character in A register to printer
#ifndef _PRINTEROUT
#define _PRINTEROUT 48410
#endif

// Decimal 48449 (0xBD41) [Value] - Select joystick alue to read from A
#ifndef _SYSSELJOYSTICK
#define _SYSSELJOYSTICK 48449
#endif

// Decimal 48466 (0xBD52) [Value] - Read hardware joystick values & update BasJoyVal0..3
#ifndef _SYSREADJOYSTICK
#define _SYSREADJOYSTICK 48466
#endif

// Decimal 48549 (0xBDA5) [Value] - Reads a bity into the 'Z' flag
#ifndef _CASBITIN
#define _CASBITIN 48549
#endif

// Decimal 48557 (0xBDAD) [Value] - Reads a single byte into the A register
#ifndef _CASBYTEIN
#define _CASBYTEIN 48557
#endif

// Decimal 48591 (0xBDCF) [Value] - Turn on motor, and wait for delay in CasMotorDelay
#ifndef _CASMOTORON
#define _CASMOTORON 48591
#endif

// Decimal 48604 (0xBDDC) [Value] - Turn off cassette motor
#ifndef _CASMOTOROFF
#define _CASMOTOROFF 48604
#endif

// Decimal 48615 (0xBDE7) [Value] - Turn on motor and read past leader
#ifndef _CASREADLEADER
#define _CASREADLEADER 48615
#endif

// Decimal 48658 (0xBE12) [Value] - Write byte in A register to cassete
#ifndef _CASBYTEOUT
#define _CASBYTEOUT 48658
#endif

// Decimal 65287 (0xFF07) [Value] - Serial baud rate, note on Dragon 64, this is the actual hardware baud rate reg.
#ifndef _TEXTSERBAUDRATE
#define _TEXTSERBAUDRATE 65287
#endif

// Decimal 0 (0x0) [Value] - Offset of number of reserved words
#ifndef _STUBRESWORDSOFS
#define _STUBRESWORDSOFS 0
#endif

// Decimal 1 (0x1) [Value] - Offset of reserved word lookup table
#ifndef _STUBRESLOOKUPOFS
#define _STUBRESLOOKUPOFS 1
#endif

// Decimal 3 (0x3) [Value] - Offset of reserved word jump table
#ifndef _STUBRESJUMPOFS
#define _STUBRESJUMPOFS 3
#endif

// Decimal 5 (0x5) [Value] - Offset of nummber of functions
#ifndef _STUBFUNCSOFS
#define _STUBFUNCSOFS 5
#endif

// Decimal 6 (0x6) [Value] - Offset of function lookup table
#ifndef _STUBFUNCSLOOKUPOFS
#define _STUBFUNCSLOOKUPOFS 6
#endif

// Decimal 8 (0x8) [Value] - Offset of functions jump table
#ifndef _STUBFUNCSJUMPOFS
#define _STUBFUNCSJUMPOFS 8
#endif

// Decimal 33 (0x21) [Value] - Skip 1 byte (BRN)
#ifndef _SKIP1
#define _SKIP1 33
#endif

// Decimal 140 (0x8C) [Value] - Skip 2 bytes (CMPX)
#ifndef _SKIP2
#define _SKIP2 140
#endif

// Decimal 134 (0x86) [Value] - Skip 1 byte (LDA)
#ifndef _SKIP1LD
#define _SKIP1LD 134
#endif

// Decimal 0 (0x0) [Value] - Vector dest for 167
#ifndef _COCOVEC167
#define _COCOVEC167 0
#endif

// Decimal 0 (0x0) [Value] - Vector dest for 16A
#ifndef _COCOVECT16A
#define _COCOVECT16A 0
#endif

// Decimal 0 (0x0) [Value] - Vector dest for 176
#ifndef _COCOVECT176
#define _COCOVECT176 0
#endif

// Decimal 0 (0x0) [Value] - Vector dest for 179
#ifndef _COCOVECT179
#define _COCOVECT179 0
#endif

// Decimal 0 (0x0) [Value] - Vector dest for 18B
#ifndef _COCOVECT18B
#define _COCOVECT18B 0
#endif

// Decimal 0 (0x0) [Value] - Vector dest for 191
#ifndef _COCOVECT191
#define _COCOVECT191 0
#endif

// Decimal 0 (0x0) [Value] - Vector Dest for 194
#ifndef _COCOVECT194
#define _COCOVECT194 0
#endif

// Decimal 0 (0x0) [Value] - Vector Dest for 197
#ifndef _COCOVECT197
#define _COCOVECT197 0
#endif

// Decimal 0 (0x0) [Value] - Vector Dest for 19A
#ifndef _COCOVECT19A
#define _COCOVECT19A 0
#endif

// Decimal 0 (0x0) [Value] - Vector Dest for 1A3
#ifndef _COCOVECT1A3
#define _COCOVECT1A3 0
#endif

// Decimal 0 (0x0) [Value] - Timeourt for DLOAD, unknown for Dragon
#ifndef _SERDLTIMEOUT
#define _SERDLTIMEOUT 0
#endif

// Decimal 0 (0x0) [Value] - Baud rate for DLOAD, unknown for Dragon
#ifndef _SERDLBAUD
#define _SERDLBAUD 0
#endif

// Decimal 0 (0x0) [Value] - Break flag, +ve=stop,-ve=end
#ifndef _BASBREAKFLAG
#define _BASBREAKFLAG 0
#endif

// Decimal 1 (0x1) [Value] - First string delimiter
#ifndef _BASDELIM1
#define _BASDELIM1 1
#endif

// Decimal 2 (0x2) [Value] - Second string delimiter
#ifndef _BASDELIM2
#define _BASDELIM2 2
#endif

// Decimal 3 (0x3) [Value] - General count/scratch var
#ifndef _BASGENCOUNT
#define _BASGENCOUNT 3
#endif

// Decimal 4 (0x4) [Value] - If count - how many in a line
#ifndef _BASIFCOUNT
#define _BASIFCOUNT 4
#endif

// Decimal 5 (0x5) [Value] - Array evaluation flag, 0=eval, 1=dimensioning
#ifndef _BASARRAYEVAL
#define _BASARRAYEVAL 5
#endif

// Decimal 6 (0x6) [Value] - Variable type flag 0=numeric, $ff=string
#ifndef _BASVARTYPE
#define _BASVARTYPE 6
#endif

// Decimal 7 (0x7) [Value] - Garbage collection flag
#ifndef _BASGARBAGEFLAG
#define _BASGARBAGEFLAG 7
#endif

// Decimal 8 (0x8) [Value] - Disable array search flag, 0=allow 0<>disable
#ifndef _BASDISARRAYSEARCH
#define _BASDISARRAYSEARCH 8
#endif

// Decimal 9 (0x9) [Value] - Iinput/read flag, 0=input 0<>read
#ifndef _BASINPUTFLAG
#define _BASINPUTFLAG 9
#endif

// Decimal 10 (0xA) [Value] - Relational operator flag
#ifndef _BASRELATEFLAG
#define _BASRELATEFLAG 10
#endif

// Decimal 11 (0xB) [Value] - First free temory string space pointer
#ifndef _BASSTRFIRSTFREETEMP
#define _BASSTRFIRSTFREETEMP 11
#endif

// Decimal 13 (0xD) [Value] - Last used tempory string space pointer
#ifndef _BASSTRLASTUSEDTEMP
#define _BASSTRLASTUSEDTEMP 13
#endif

// Decimal 15 (0xF) [Value] - Tempory pointer
#ifndef _BASTEMPPTR
#define _BASTEMPPTR 15
#endif

// Decimal 17 (0x11) [Value] - Tempory discriptor pointer (stack search)
#ifndef _BASTEMPPTR1
#define _BASTEMPPTR1 17
#endif

// Decimal 19 (0x13) [Value] - Tempory FPA Mantissa for FPA2
#ifndef _BASTEMPFPA2
#define _BASTEMPFPA2 19
#endif

// Decimal 23 (0x17) [Value] - Bottom of stack at last check
#ifndef _BASBOTSTACK
#define _BASBOTSTACK 23
#endif

// Decimal 25 (0x19) [Value] - Start addr of basic program
#ifndef _BASSTARTPROG
#define _BASSTARTPROG 25
#endif

// Decimal 27 (0x1B) [Value] - Start address of simple variables
#ifndef _BASVARSIMPLEADDR
#define _BASVARSIMPLEADDR 27
#endif

// Decimal 29 (0x1D) [Value] - Start address of Array table
#ifndef _BASVARARRAYADDR
#define _BASVARARRAYADDR 29
#endif

// Decimal 31 (0x1F) [Value] - End of storage in use by basic
#ifndef _BASVAREND
#define _BASVAREND 31
#endif

// Decimal 33 (0x21) [Value] - Base address of string space (and stack)
#ifndef _BASVARSTRINGBASE
#define _BASVARSTRINGBASE 33
#endif

// Decimal 33 (0x21) [Value] - Address of top of machine stack
#ifndef _ADDRSTACK
#define _ADDRSTACK 33
#endif

// Decimal 35 (0x23) [Value] - Top of string space in use
#ifndef _BASVARSTRTOP
#define _BASVARSTRTOP 35
#endif

// Decimal 37 (0x25) [Value] - Utility string pointer
#ifndef _BASSTRUTIL
#define _BASSTRUTIL 37
#endif

// Decimal 39 (0x27) [Value] - Top of firmware RAM CLEAR xxx,yyyy set this to yyyy
#ifndef _ADDRFWARERAMTOP
#define _ADDRFWARERAMTOP 39
#endif

// Decimal 41 (0x29) [Value] - Line no used by CONT
#ifndef _BASCONTLINE
#define _BASCONTLINE 41
#endif

// Decimal 43 (0x2B) [Value] - Tempory line no
#ifndef _BASTEMPLINE
#define _BASTEMPLINE 43
#endif

// Decimal 45 (0x2D) [Value] - Pointer to saved input during a STOP
#ifndef _BASOLDINPUTPTR
#define _BASOLDINPUTPTR 45
#endif

// Decimal 47 (0x2F) [Value] - Direct mode text pointer
#ifndef _BASDIRECTTEXTPTR
#define _BASDIRECTTEXTPTR 47
#endif

// Decimal 49 (0x31) [Value] - Line number of current data statement
#ifndef _BASVARDATALINE
#define _BASVARDATALINE 49
#endif

// Decimal 51 (0x33) [Value] - Address of next item in data
#ifndef _BASVARDATAADDR
#define _BASVARDATAADDR 51
#endif

// Decimal 53 (0x35) [Value] - Address of keyboard input buffer
#ifndef _TEXTKBDBUFFADDR
#define _TEXTKBDBUFFADDR 53
#endif

// Decimal 55 (0x37) [Value] - Pointer to variable last in use
#ifndef _BASVARLASTINUSE
#define _BASVARLASTINUSE 55
#endif

// Decimal 57 (0x39) [Value] - Poiinter to VARPTR last in use
#ifndef _BASVARPTRLAST
#define _BASVARPTRLAST 57
#endif

// Decimal 59 (0x3B) [Value] - Pointer to a tempory var descriptor
#ifndef _BASTEMPVARDESC
#define _BASTEMPVARDESC 59
#endif

// Decimal 63 (0x3F) [Value] - Tempory relational operator flag
#ifndef _BASTEMPRELATEFLAG
#define _BASTEMPRELATEFLAG 63
#endif

// Decimal 64 (0x40) [Value] - Floating point accumulator 3 (packed)
#ifndef _BASVARFPACC3
#define _BASVARFPACC3 64
#endif

// Decimal 69 (0x45) [Value] - Floating point accumulator 4 (packed)
#ifndef _BASVARFPACC4
#define _BASVARFPACC4 69
#endif

// Decimal 74 (0x4A) [Value] - Floating point accumulator 5 (packed)
#ifndef _BASVARFPACC5
#define _BASVARFPACC5 74
#endif

// Decimal 79 (0x4F) [Value] - Floating point acumulator 1
#ifndef _BASVARFPACC1
#define _BASVARFPACC1 79
#endif

// Decimal 82 (0x52) [Value] - Part of FPA1, used for 16bit assigns
#ifndef _BASVARASSIGN16
#define _BASVARASSIGN16 82
#endif

// Decimal 92 (0x5C) [Value] - Floating point acumulator 2
#ifndef _BASVARFPACC2
#define _BASVARFPACC2 92
#endif

// Decimal 102 (0x66) [Value] - Current line during list
#ifndef _BASLISTLINE
#define _BASLISTLINE 102
#endif

// Decimal 104 (0x68) [Value] - Current line no $FFFF in direct mode
#ifndef _BASCURRENTLINE
#define _BASCURRENTLINE 104
#endif

// Decimal 106 (0x6A) [Value] - VDU comma width field
#ifndef _TEXTVDUCOMMAW
#define _TEXTVDUCOMMAW 106
#endif

// Decimal 107 (0x6B) [Value] - VDU last comma field, should be VDU line width - VDU comma width
#ifndef _TEXTVDULASTCOMMA
#define _TEXTVDULASTCOMMA 107
#endif

// Decimal 108 (0x6C) [Value] - Current column for VDU output
#ifndef _TEXTVDUCURRCOL
#define _TEXTVDUCURRCOL 108
#endif

// Decimal 109 (0x6D) [Value] - VDU line width, normally 32
#ifndef _TEXTVDULINEW
#define _TEXTVDULINEW 109
#endif

// Decimal 110 (0x6E) [Value] - Cassette IO Flag, set to $FF when IO in progress
#ifndef _CASIOFLAG
#define _CASIOFLAG 110
#endif

// Decimal 111 (0x6F) [Value] - Current device number
#ifndef _TEXTDEVN
#define _TEXTDEVN 111
#endif

// Decimal 112 (0x70) [Value] - Cassette IO Flag, nonzero if EOF reached
#ifndef _CASEOFFLAG
#define _CASEOFFLAG 112
#endif

// Decimal 113 (0x71) [Value] - Warm start flag $55=warm start, else cold start
#ifndef _WARMSTARTFLAG
#define _WARMSTARTFLAG 113
#endif

// Decimal 114 (0x72) [Value] - Secondary Reset vector address, must point to NOP
#ifndef _INDVECRESET
#define _INDVECRESET 114
#endif

// Decimal 116 (0x74) [Value] - Physical end of RAM (4K, 16K, 32K or 64K).
#ifndef _ADDRRAMTOP
#define _ADDRRAMTOP 116
#endif

// Decimal 118 (0x76) [Value] - 2 unused bytes
#ifndef _BASUNUSED1
#define _BASUNUSED1 118
#endif

// Decimal 120 (0x78) [Value] - Cassette status byte, 0=cassette closed, 1=open for input, 2=open for output
#ifndef _CASSTATUS
#define _CASSTATUS 120
#endif

// Decimal 121 (0x79) [Value] - Size of cassette IO buffer
#ifndef _CASIOBUFFSIZE
#define _CASIOBUFFSIZE 121
#endif

// Decimal 122 (0x7A) [Value] - Address of cassette file header
#ifndef _CASHEADBUFFADDR
#define _CASHEADBUFFADDR 122
#endif

// Decimal 124 (0x7C) [Value] - Cassete block type, 0=filename, 1=data, 255=EOF
#ifndef _CASBLOCKTYPE
#define _CASBLOCKTYPE 124
#endif

// Decimal 125 (0x7D) [Value] - Cassete block length, number of bytes read, or to be written
#ifndef _CASBLOCKLEN
#define _CASBLOCKLEN 125
#endif

// Decimal 126 (0x7E) [Value] - Cassette IO buffer address, where data will be read/written
#ifndef _CASIOBUFFADDR
#define _CASIOBUFFADDR 126
#endif

// Decimal 128 (0x80) [Value] - Used by cassette routines for calculating checksum
#ifndef _CASCKSUM
#define _CASCKSUM 128
#endif

// Decimal 129 (0x81) [Value] - Cassette IO error code 0=no error, 1=CRC, 2=attempt to load in non-ram area
#ifndef _CASIOERRORCODE
#define _CASIOERRORCODE 129
#endif

// Decimal 130 (0x82) [Value] - Cassette tempory storage
#ifndef _CASTEMP
#define _CASTEMP 130
#endif

// Decimal 131 (0x83) [Value] - Cassette bit counter
#ifndef _CASBITCOUNT
#define _CASBITCOUNT 131
#endif

// Decimal 132 (0x84) [Value] - Cassette Phase flag
#ifndef _CASPHASEFLAG
#define _CASPHASEFLAG 132
#endif

// Decimal 133 (0x85) [Value] - Casette last sine tabe entry
#ifndef _CASLASTSINE
#define _CASLASTSINE 133
#endif

// Decimal 134 (0x86) [Value] - Data for Lo-res set/reset
#ifndef _GRSETRESETDATA
#define _GRSETRESETDATA 134
#endif

// Decimal 135 (0x87) [Value] - ASCII code of last keypress, not cleard by key release
#ifndef _TEXTLASTKEY
#define _TEXTLASTKEY 135
#endif

// Decimal 136 (0x88) [Value] - Current VDU cursor address
#ifndef _TEXTVDUCURSADDR
#define _TEXTVDUCURSADDR 136
#endif

// Decimal 138 (0x8A) [Value] - Misc 16 bit scratch register (always zero ??)
#ifndef _MISC16BITSCRATCH
#define _MISC16BITSCRATCH 138
#endif

// Decimal 140 (0x8C) [Value] - Sound pitch value
#ifndef _SNDPITCH
#define _SNDPITCH 140
#endif

// Decimal 141 (0x8D) [Value] - Sound duration
#ifndef _SNDLENGTH
#define _SNDLENGTH 141
#endif

// Decimal 143 (0x8F) [Value] - Cusrsor flash counter
#ifndef _TEXTCURSFALSHCNT
#define _TEXTCURSFALSHCNT 143
#endif

// Decimal 144 (0x90) [Value] - Cassete leader count, number of $55 bytes in the leader
#ifndef _CASLEADCOUNT
#define _CASLEADCOUNT 144
#endif

// Decimal 146 (0x92) [Value] - Cassette 1200/2400 partition
#ifndef _CASPARTRT
#define _CASPARTRT 146
#endif

// Decimal 147 (0x93) [Value] - Cassette Upper limit of 1200Hz
#ifndef _CASMAX12
#define _CASMAX12 147
#endif

// Decimal 148 (0x94) [Value] - Cassette Upper limit of 2400Hz
#ifndef _CASMAX24
#define _CASMAX24 148
#endif

// Decimal 149 (0x95) [Value] - Cassette motor on delay (also inter-block gap)
#ifndef _CASMOTORDELAY
#define _CASMOTORDELAY 149
#endif

// Decimal 151 (0x97) [Value] - Keyboard scan delay constant, used to debounce
#ifndef _TEXTKBDDELAY
#define _TEXTKBDDELAY 151
#endif

// Decimal 153 (0x99) [Value] - Printer comma width
#ifndef _TEXTPRNCOMMAW
#define _TEXTPRNCOMMAW 153
#endif

// Decimal 154 (0x9A) [Value] - Printer last comma width, should be printer line width - prinnter comma width
#ifndef _TEXTPRNLASTCOMMA
#define _TEXTPRNLASTCOMMA 154
#endif

// Decimal 155 (0x9B) [Value] - Printer line width
#ifndef _TEXTPRNLINEW
#define _TEXTPRNLINEW 155
#endif

// Decimal 156 (0x9C) [Value] - Printer current column
#ifndef _TEXTPRNCURRCOL
#define _TEXTPRNCURRCOL 156
#endif

// Decimal 157 (0x9D) [Value] - Exec address, on D64, at startup points to routine to boot all ram mode
#ifndef _BASEXECADDR
#define _BASEXECADDR 157
#endif

// Decimal 159 (0x9F) [Value] - Get next basic character routine
#ifndef _BASCHRGET
#define _BASCHRGET 159
#endif

// Decimal 165 (0xA5) [Value] - Get current basic ccharacter
#ifndef _BASCHRGETCURR
#define _BASCHRGETCURR 165
#endif

// Decimal 166 (0xA6) [Value] - Address of current significant bit in command line
#ifndef _BASADDRSIGBYTE
#define _BASADDRSIGBYTE 166
#endif

// Decimal 171 (0xAB) [Value] - Used by RND
#ifndef _BASRNDDATA
#define _BASRNDDATA 171
#endif

// Decimal 175 (0xAF) [Value] - Tron flag nonzero=trace on
#ifndef _BASTRONFLAG
#define _BASTRONFLAG 175
#endif

// Decimal 176 (0xB0) [Value] - Address of USR address table
#ifndef _BASUSRTABLEADDR
#define _BASUSRTABLEADDR 176
#endif

// Decimal 178 (0xB2) [Value] - Current foreground colour
#ifndef _GRFOREGROUND
#define _GRFOREGROUND 178
#endif

// Decimal 179 (0xB3) [Value] - Current background colour
#ifndef _GRBACKGROUND
#define _GRBACKGROUND 179
#endif

// Decimal 180 (0xB4) [Value] - Tempory colour in use
#ifndef _GRCOLOURTEMP
#define _GRCOLOURTEMP 180
#endif

// Decimal 181 (0xB5) [Value] - Byte value for current colour, to set all pixels in byte to that colour
#ifndef _GRCURRCOLOUR
#define _GRCURRCOLOUR 181
#endif

// Decimal 182 (0xB6) [Value] - Current PMODE number
#ifndef _GRCURRPMODE
#define _GRCURRPMODE 182
#endif

// Decimal 183 (0xB7) [Value] - Address of last byte in current display
#ifndef _GRLASTDISPLAYADDR
#define _GRLASTDISPLAYADDR 183
#endif

// Decimal 185 (0xB9) [Value] - Number of byts/lin in current mode
#ifndef _GRBYTESPERLINE
#define _GRBYTESPERLINE 185
#endif

// Decimal 186 (0xBA) [Value] - Address of first byte in current display
#ifndef _GRDISPLAYSTARTADDR
#define _GRDISPLAYSTARTADDR 186
#endif

// Decimal 188 (0xBC) [Value] - Page number of Start of graphics pages
#ifndef _GRSTARTPAGES
#define _GRSTARTPAGES 188
#endif

// Decimal 189 (0xBD) [Value] - Current X cursor pos
#ifndef _GRCURRX
#define _GRCURRX 189
#endif

// Decimal 191 (0xBF) [Value] - Current Y cursor pos
#ifndef _GRCURRY
#define _GRCURRY 191
#endif

// Decimal 193 (0xC1) [Value] - Colour set currently in use
#ifndef _GRCOLOURSET
#define _GRCOLOURSET 193
#endif

// Decimal 194 (0xC2) [Value] - Plot/Unplot flag, 0=reset, nonzero=set
#ifndef _GRPLOTFLAG
#define _GRPLOTFLAG 194
#endif

// Decimal 195 (0xC3) [Value] - Current horizontal pixel no
#ifndef _GRPIXELNOX
#define _GRPIXELNOX 195
#endif

// Decimal 197 (0xC5) [Value] - Current vertical pixel number
#ifndef _GRPIXELNOY
#define _GRPIXELNOY 197
#endif

// Decimal 199 (0xC7) [Value] - Current Cursor X
#ifndef _GRCURRXCO
#define _GRCURRXCO 199
#endif

// Decimal 201 (0xC9) [Value] - Current Cursor Y
#ifndef _GRCURRYCO
#define _GRCURRYCO 201
#endif

// Decimal 203 (0xCB) [Value] - Circle command X
#ifndef _GRCIRCLEXCO
#define _GRCIRCLEXCO 203
#endif

// Decimal 205 (0xCD) [Value] - Circle command Y
#ifndef _GRCIRCLEYCO
#define _GRCIRCLEYCO 205
#endif

// Decimal 207 (0xCF) [Value] - Renum increment value
#ifndef _BASRENUMVAL
#define _BASRENUMVAL 207
#endif

// Decimal 208 (0xD0) [Value] - Circle radius
#ifndef _GRCIRCLERADIUS
#define _GRCIRCLERADIUS 208
#endif

// Decimal 209 (0xD1) [Value] - Renum start line no
#ifndef _BASRENUMSTART
#define _BASRENUMSTART 209
#endif

// Decimal 211 (0xD3) [Value] - 2s complement of CLOADM offset
#ifndef _BASCLOADMOFFS
#define _BASCLOADMOFFS 211
#endif

// Decimal 213 (0xD5) [Value] - Renum start line number
#ifndef _BASRENUMSTARTLINE
#define _BASRENUMSTARTLINE 213
#endif

// Decimal 215 (0xD7) [Value] - Editor line length
#ifndef _BASEDITORLINELEN
#define _BASEDITORLINELEN 215
#endif

// Decimal 219 (0xDB) [Value] - Flag to tell if graphics screen has changed
#ifndef _GRDIRTYFLAG
#define _GRDIRTYFLAG 219
#endif

// Decimal 222 (0xDE) [Value] - Sound octave value for PLAY
#ifndef _SNDOCTAVE
#define _SNDOCTAVE 222
#endif

// Decimal 223 (0xDF) [Value] - Sound volume for PLAY
#ifndef _SNDVOLUME
#define _SNDVOLUME 223
#endif

// Decimal 225 (0xE1) [Value] - Note length for PLAY
#ifndef _SNDNOTELEN
#define _SNDNOTELEN 225
#endif

// Decimal 226 (0xE2) [Value] - Tempo for PLAY
#ifndef _SNDTEMPO
#define _SNDTEMPO 226
#endif

// Decimal 227 (0xE3) [Value] - Timer for the Play command
#ifndef _SNDTIMERPLAY
#define _SNDTIMERPLAY 227
#endif

// Decimal 229 (0xE5) [Value] - Dotted note scale factor for Play
#ifndef _SNDDOTNOTESCALE
#define _SNDDOTNOTESCALE 229
#endif

// Decimal 232 (0xE8) [Value] - Current angle for DRAW command
#ifndef _GRDRAWANGLE
#define _GRDRAWANGLE 232
#endif

// Decimal 233 (0xE9) [Value] - Current scale for DRAW command
#ifndef _GRDRAWSCALE
#define _GRDRAWSCALE 233
#endif

// Decimal 256 (0x100) [Value] - Secondary SWI3 vector JMP+ address
#ifndef _SECVECSWI3
#define _SECVECSWI3 256
#endif

// Decimal 259 (0x103) [Value] - Secondary SWI2 vector JMP+ address
#ifndef _SECVECSWI2
#define _SECVECSWI2 259
#endif

// Decimal 262 (0x106) [Value] - Secondary NMI vector JMP+ address
#ifndef _SECVECSWI
#define _SECVECSWI 262
#endif

// Decimal 265 (0x109) [Value] - Secondary NMI vector JMP+ address
#ifndef _SECVECNMI
#define _SECVECNMI 265
#endif

// Decimal 268 (0x10C) [Value] - Secondary IRQ vector JMP+ address
#ifndef _SECVECIRQ
#define _SECVECIRQ 268
#endif

// Decimal 271 (0x10F) [Value] - Secondary FIRQ vector JMP+ address
#ifndef _SECVECFIRQ
#define _SECVECFIRQ 271
#endif

// Decimal 274 (0x112) [Value] - Current value of system timer
#ifndef _SYSTIMEVAL
#define _SYSTIMEVAL 274
#endif

// Decimal 277 (0x115) [Value] - Random number seed for RND function
#ifndef _BASRANDOMSEED
#define _BASRANDOMSEED 277
#endif

// Decimal 288 (0x120) [Value] - Number of basic commands
#ifndef _BASNUMCMDS
#define _BASNUMCMDS 288
#endif

// Decimal 288 (0x120) [Value] - Basic Stub 0 (All basic on Dragon, Colour basic on Tandy)
#ifndef _BASSTUB0
#define _BASSTUB0 288
#endif

// Decimal 289 (0x121) [Value] - Address of basic command list
#ifndef _BASADDRCMDLIST
#define _BASADDRCMDLIST 289
#endif

// Decimal 291 (0x123) [Value] - Address of basic command dispatch
#ifndef _BASADDRCMDDISP
#define _BASADDRCMDDISP 291
#endif

// Decimal 293 (0x125) [Value] - Number of basic functions
#ifndef _BASNUMFUNCS
#define _BASNUMFUNCS 293
#endif

// Decimal 294 (0x126) [Value] - Address of basic function list
#ifndef _BASADDRFUNCLIST
#define _BASADDRFUNCLIST 294
#endif

// Decimal 296 (0x128) [Value] - Address of basic function dispatcher
#ifndef _BASADDRFUNCDISP
#define _BASADDRFUNCDISP 296
#endif

// Decimal 298 (0x12A) [Value] - Number of disk basic commands
#ifndef _BASNUMDSKCMDS
#define _BASNUMDSKCMDS 298
#endif

// Decimal 298 (0x12A) [Value] - Basic stub 1 (Disk basic on Dragon, Extended basic on Tandy)
#ifndef _BASSTUB1
#define _BASSTUB1 298
#endif

// Decimal 299 (0x12B) [Value] - Address of disk basic command list
#ifndef _BASADDRDSKCMDLIST
#define _BASADDRDSKCMDLIST 299
#endif

// Decimal 301 (0x12D) [Value] - Address of disk basic command dispatch
#ifndef _BASADDRDSKCMDDISP
#define _BASADDRDSKCMDDISP 301
#endif

// Decimal 303 (0x12F) [Value] - Number of disk basic functions
#ifndef _BASNUMDSKFUNCS
#define _BASNUMDSKFUNCS 303
#endif

// Decimal 304 (0x130) [Value] - Address of disk basic function list
#ifndef _BASADDRDSKFUNCLIST
#define _BASADDRDSKFUNCLIST 304
#endif

// Decimal 306 (0x132) [Value] - Address of disk basic function dispatcher
#ifndef _BASADDRDSKFUNCDISP
#define _BASADDRDSKFUNCDISP 306
#endif

// Decimal 308 (0x134) [Value] - USR vector tabl when basic not installed
#ifndef _BASUSRVECNODISK
#define _BASUSRVECNODISK 308
#endif

// Decimal 308 (0x134) [Value] - Basic Stub 2 (Null on dragon, Disk basic on Tandy)
#ifndef _BASSTUB2
#define _BASSTUB2 308
#endif

// Decimal 318 (0x13E) [Value] - Basic Stub 3 (do not use on dragon, user stub on Tandy)
#ifndef _BASSTUB3
#define _BASSTUB3 318
#endif

// Decimal 328 (0x148) [Value] - Printer auto EOL flag, nonzero will send EOL sequence at end of line
#ifndef _TEXTPRNAUTOCRLF
#define _TEXTPRNAUTOCRLF 328
#endif

// Decimal 329 (0x149) [Value] - Capslock flag, nonzero=uppercase
#ifndef _TEXTCAPSLOCK
#define _TEXTCAPSLOCK 329
#endif

// Decimal 330 (0x14A) [Value] - Number of characters in EOL sequence 1..4
#ifndef _TEXTPRNEOLCNT
#define _TEXTPRNEOLCNT 330
#endif

// Decimal 331 (0x14B) [Value] - End of line characters
#ifndef _TEXTPRNEOLSEQ
#define _TEXTPRNEOLSEQ 331
#endif

// Decimal 336 (0x150) [Value] - Rollover table, to check for key releases
#ifndef _TEXTKBDROLLOVER
#define _TEXTKBDROLLOVER 336
#endif

// Decimal 346 (0x15A) [Value] - Joystick(0) value
#ifndef _BASJOYVAL0
#define _BASJOYVAL0 346
#endif

// Decimal 347 (0x15B) [Value] - Joystick(1) value
#ifndef _BASJOYVAL1
#define _BASJOYVAL1 347
#endif

// Decimal 348 (0x15C) [Value] - Joystick(2) value
#ifndef _BASJOYVAL2
#define _BASJOYVAL2 348
#endif

// Decimal 349 (0x15D) [Value] - Joystick(3) value
#ifndef _BASJOYVAL3
#define _BASJOYVAL3 349
#endif

// Decimal 350 (0x15E) [Value] - Called before a device is opened
#ifndef _VECTDEVOPEN
#define _VECTDEVOPEN 350
#endif

// Decimal 350 (0x15E) [Value] - Base address of ram hooks/vectors
#ifndef _VECTBASE
#define _VECTBASE 350
#endif

// Decimal 353 (0x161) [Value] - Called when a device number is verified
#ifndef _VECTDEVNO
#define _VECTDEVNO 353
#endif

// Decimal 356 (0x164) [Value] - Called before initialising a device
#ifndef _VECTDEVINIT
#define _VECTDEVINIT 356
#endif

// Decimal 359 (0x167) [Value] - Called before outputting char in A to a device
#ifndef _VECTOUTCHAR
#define _VECTOUTCHAR 359
#endif

// Decimal 362 (0x16A) [Value] - Called before inputting a char to A
#ifndef _VECTINCHAR
#define _VECTINCHAR 362
#endif

// Decimal 365 (0x16D) [Value] - Called before inputting from a file
#ifndef _VECTINPUTFILE
#define _VECTINPUTFILE 365
#endif

// Decimal 368 (0x170) [Value] - Called before outputting to a file
#ifndef _VECTOUTPUTFILE
#define _VECTOUTPUTFILE 368
#endif

// Decimal 371 (0x173) [Value] - Called before closing all files
#ifndef _VECTCLOSEALLFILES
#define _VECTCLOSEALLFILES 371
#endif

// Decimal 374 (0x176) [Value] - Called before closing a file
#ifndef _VECTCLOSEFILE
#define _VECTCLOSEFILE 374
#endif

// Decimal 377 (0x179) [Value] - Called before interpreting a token in A
#ifndef _VECTCMDINTERP
#define _VECTCMDINTERP 377
#endif

// Decimal 380 (0x17C) [Value] - Called before re-requesing input from keyboard
#ifndef _VECTREREQESTIN
#define _VECTREREQESTIN 380
#endif

// Decimal 383 (0x17F) [Value] - Called before keyboard is scanned for BREAK,SHIFT-@
#ifndef _VECTCHECKKEYS
#define _VECTCHECKKEYS 383
#endif

// Decimal 386 (0x182) [Value] - Called before LINE INPUT is executed
#ifndef _VECTLINEINPUTFILE
#define _VECTLINEINPUTFILE 386
#endif

// Decimal 389 (0x185) [Value] - Called before closing an ASCII file read in as basic
#ifndef _VECTCLOSEFILECMD
#define _VECTCLOSEFILECMD 389
#endif

// Decimal 392 (0x188) [Value] - called before checking for end of file
#ifndef _VECTCHECKEOF
#define _VECTCHECKEOF 392
#endif

// Decimal 395 (0x18B) [Value] - Called before evaluating expression
#ifndef _VECTEVALUATEEXPR
#define _VECTEVALUATEEXPR 395
#endif

// Decimal 398 (0x18E) [Value] - Can be patched by user to trap error messages
#ifndef _VECTUSERERROR
#define _VECTUSERERROR 398
#endif

// Decimal 401 (0x191) [Value] - Can be patched by system to trap error messages
#ifndef _VECTSYSERROR
#define _VECTSYSERROR 401
#endif

// Decimal 404 (0x194) [Value] - Called when RUN about to be executed
#ifndef _VECTRUNLINK
#define _VECTRUNLINK 404
#endif

// Decimal 407 (0x197) [Value] - Called before changing BASIC memory vectors after LOAD etc
#ifndef _VECTRESETBASMEM
#define _VECTRESETBASMEM 407
#endif

// Decimal 410 (0x19A) [Value] - Called before fetching next command to be executed by BASIC
#ifndef _VECTGETNEXTCMD
#define _VECTGETNEXTCMD 410
#endif

// Decimal 413 (0x19D) [Value] - Called before assigning string to string variable
#ifndef _VECTASSIGNSTR
#define _VECTASSIGNSTR 413
#endif

// Decimal 416 (0x1A0) [Value] - Called before CLS, GET & PUT are executed
#ifndef _VECTACCESSSCREEN
#define _VECTACCESSSCREEN 416
#endif

// Decimal 419 (0x1A3) [Value] - Called before an ASCII line is tokenized
#ifndef _VECTTOKENIZE
#define _VECTTOKENIZE 419
#endif

// Decimal 422 (0x1A6) [Value] - Called before a line is de-tokenized
#ifndef _VECTDETOKENIZE
#define _VECTDETOKENIZE 422
#endif

// Decimal 425 (0x1A9) [Value] - String descriptor stack
#ifndef _BASSTRDESCSTACK
#define _BASSTRDESCSTACK 425
#endif

// Decimal 465 (0x1D1) [Value] - Length of cassette filename can be 0 to 8
#ifndef _CASFNAMELEN
#define _CASFNAMELEN 465
#endif

// Decimal 466 (0x1D2) [Value] - Cassete filename to search for or write out
#ifndef _CASFNAME
#define _CASFNAME 466
#endif

// Decimal 474 (0x1DA) [Value] - Filename found, when reading
#ifndef _CASFNAMEFOUND
#define _CASFNAMEFOUND 474
#endif

// Decimal 474 (0x1DA) [Value] - COS default IO buffer, if this contains filename block then folloing are valid
#ifndef _CASIOBUFF
#define _CASIOBUFF 474
#endif

// Decimal 482 (0x1E2) [Value] - File type 0=tokenized basic, 1=ASCII data, 2=Binary
#ifndef _CASFTYPE
#define _CASFTYPE 482
#endif

// Decimal 483 (0x1E3) [Value] - ASCII flag byte
#ifndef _CASASCIIFLAG
#define _CASASCIIFLAG 483
#endif

// Decimal 484 (0x1E4) [Value] - Gap flag byte
#ifndef _CASGAPFLAG
#define _CASGAPFLAG 484
#endif

// Decimal 485 (0x1E5) [Value] - Entry address for MC programs
#ifndef _CASENTRYADDR
#define _CASENTRYADDR 485
#endif

// Decimal 487 (0x1E7) [Value] - Load address
#ifndef _CASLOADADDR
#define _CASLOADADDR 487
#endif

// Decimal 730 (0x2DA) [Value] - Basic line input buffer header
#ifndef _BASLININPHEAD
#define _BASLININPHEAD 730
#endif

// Decimal 732 (0x2DC) [Value] - Basic line input buffer
#ifndef _BASLININPBUFF
#define _BASLININPBUFF 732
#endif

// Decimal 983 (0x3D7) [Value] - Basic buffer space
#ifndef _BASBUFFER
#define _BASBUFFER 983
#endif

// Decimal 1021 (0x3FD) [Value] - End of line delay for serial port on Dragon 64 & CoCo
#ifndef _TEXTSEREOLDELAY
#define _TEXTSEREOLDELAY 1021
#endif

// Decimal 1023 (0x3FF) [Value] - Dragon 64 printer selection flag, 0=paralell port, nonzero=RS232
#ifndef _TEXTPRNSELFLAG
#define _TEXTPRNSELFLAG 1023
#endif

// Decimal 32768 (0x8000) [Value] - Hardware initialisation
#ifndef _BASICHWINIT
#define _BASICHWINIT 32768
#endif

// Decimal 32771 (0x8003) [Value] - Software initialisation
#ifndef _BASICSWINIT
#define _BASICSWINIT 32771
#endif

// Decimal 32774 (0x8006) [Value] - Keyboard input
#ifndef _BASICKBDIN
#define _BASICKBDIN 32774
#endif

// Decimal 32777 (0x8009) [Value] - Cursor blink
#ifndef _BASICCURSORB
#define _BASICCURSORB 32777
#endif

// Decimal 32780 (0x800C) [Value] - Screen output
#ifndef _BASICSCREENOUT
#define _BASICSCREENOUT 32780
#endif

// Decimal 32783 (0x800F) [Value] - Printer output
#ifndef _BASICPRINTOUT
#define _BASICPRINTOUT 32783
#endif

// Decimal 32786 (0x8012) [Value] - Joystick input
#ifndef _BASICJOYIN
#define _BASICJOYIN 32786
#endif

// Decimal 32789 (0x8015) [Value] - Cassette player motor on
#ifndef _BASICCASSON
#define _BASICCASSON 32789
#endif

// Decimal 32792 (0x8018) [Value] - Cassette player motor off
#ifndef _BASICCASSOFF
#define _BASICCASSOFF 32792
#endif

// Decimal 32795 (0x801B) [Value] - Cassette write leader
#ifndef _BASICWRITELEAD
#define _BASICWRITELEAD 32795
#endif

// Decimal 32795 (0x801B) [Value] - Turn on motor and write out leader
#ifndef _CASWRITELEADER
#define _CASWRITELEADER 32795
#endif

// Decimal 32798 (0x801E) [Value] - Cassette byte output
#ifndef _BASICCASSBYOUT
#define _BASICCASSBYOUT 32798
#endif

// Decimal 32801 (0x8021) [Value] - Cassette on for reading
#ifndef _BASICCASSONRD
#define _BASICCASSONRD 32801
#endif

// Decimal 32804 (0x8024) [Value] - Cassette byte input
#ifndef _BASICCASSBYIN
#define _BASICCASSBYIN 32804
#endif

// Decimal 32807 (0x8027) [Value] - Cassette bit input
#ifndef _BASICCASSBITIN
#define _BASICCASSBITIN 32807
#endif

// Decimal 32810 (0x802A) [Value] - Read a byte from serial
#ifndef _BASICSERIN
#define _BASICSERIN 32810
#endif

// Decimal 32813 (0x802D) [Value] - Write a byte to serial port
#ifndef _BASICSEROUT
#define _BASICSEROUT 32813
#endif

// Decimal 32816 (0x8030) [Value] - Set baud rate
#ifndef _BASICSETBAUD
#define _BASICSETBAUD 32816
#endif

// Decimal 33449 (0x82A9) [Value] - List of 2 byte error codes eg 'SN' 'OM' 'UL' etc
#ifndef _BASERRORCODETABLE
#define _BASERRORCODETABLE 33449
#endif

// Decimal 33564 (0x831C) [Value] - Check memory space at top of arrays + move arrays
#ifndef _BASCHKARRSPACEMV
#define _BASCHKARRSPACEMV 33564
#endif

// Decimal 33585 (0x8331) [Value] - Check B*2 bytes free above Arrays, OM error if not
#ifndef _BASCHKB2FREE
#define _BASCHKB2FREE 33585
#endif

// Decimal 33602 (0x8342) [Value] - Print ?OM Error and return to basic
#ifndef _BASOMERROR
#define _BASOMERROR 33602
#endif

// Decimal 33604 (0x8344) [Value] - Report error code in B register, cleanup and return to basic
#ifndef _SYSERR
#define _SYSERR 33604
#endif

// Decimal 33630 (0x835E) [Value] - Report error in B, do NOT hook to RAM, or turn of cas etc
#ifndef _SYSERR2
#define _SYSERR2 33630
#endif

// Decimal 33649 (0x8371) [Value] - Return to command mode
#ifndef _BASCMDMODE
#define _BASCMDMODE 33649
#endif

// Decimal 33773 (0x83ED) [Value] - Finalises setup of basic vectors (after load), should be preceeded by call to BasVect1
#ifndef _BASVECT2
#define _BASVECT2 33773
#endif

// Decimal 33791 (0x83FF) [Value] - Find a line number in basic program
#ifndef _BASFINDLINENO
#define _BASFINDLINENO 33791
#endif

// Decimal 33813 (0x8415) [Value] - Basic Command
#ifndef _CMDNEW
#define _CMDNEW 33813
#endif

// Decimal 33815 (0x8417) [Value] - Remove current basic program from meory, like NEW command
#ifndef _BASNEW
#define _BASNEW 33815
#endif

// Decimal 33823 (0x841F) [Value] - Sets up various basic vectors (after load), should be followed by call to BasVect2
#ifndef _BASVECT1
#define _BASVECT1 33823
#endif

// Decimal 33844 (0x8434) [Value] - Reset basic stack to initial position
#ifndef _BASRESETSTACK
#define _BASRESETSTACK 33844
#endif

// Decimal 33864 (0x8448) [Value] - Basic Command
#ifndef _CMDFOR
#define _CMDFOR 33864
#endif

// Decimal 33951 (0x849F) [Value] - Run basic program in memory, like RUN
#ifndef _BASRUN
#define _BASRUN 33951
#endif

// Decimal 34010 (0x84DA) [Value] - BRA to main loop, used by DOS
#ifndef _BASBRARUN
#define _BASBRARUN 34010
#endif

// Decimal 34029 (0x84ED) [Value] - Do command dispatech, X must point to dispatch table
#ifndef _BASDODIPATCH
#define _BASDODIPATCH 34029
#endif

// Decimal 34068 (0x8514) [Value] - Basic Command
#ifndef _CMDRESTORE
#define _CMDRESTORE 34068
#endif

// Decimal 34075 (0x851B) [Value] - Basic, poll keyboard and check for break
#ifndef _BASPOLLKEYBOARD
#define _BASPOLLKEYBOARD 34075
#endif

// Decimal 34091 (0x852B) [Value] - Wait for a keypress, calls TextScanKbd, also handles break
#ifndef _TEXTWAITKEY
#define _TEXTWAITKEY 34091
#endif

// Decimal 34098 (0x8532) [Value] - Basic Command
#ifndef _CMDEND
#define _CMDEND 34098
#endif

// Decimal 34105 (0x8539) [Value] - Basic Command
#ifndef _CMDSTOP
#define _CMDSTOP 34105
#endif

// Decimal 34144 (0x8560) [Value] - Basic Command
#ifndef _CMDCONT
#define _CMDCONT 34144
#endif

// Decimal 34161 (0x8571) [Value] - Basic Command
#ifndef _CMDCLEAR
#define _CMDCLEAR 34161
#endif

// Decimal 34213 (0x85A5) [Value] - Basic Command
#ifndef _CMDRUN
#define _CMDRUN 34213
#endif

// Decimal 34233 (0x85B9) [Value] - Basic Command
#ifndef _CMDGO
#define _CMDGO 34233
#endif

// Decimal 34279 (0x85E7) [Value] - Skip past line no in basic line, UL error if no line no.
#ifndef _BASSKIPLINENO
#define _BASSKIPLINENO 34279
#endif

// Decimal 34286 (0x85EE) [Value] - Sets basic program pointer to X-1
#ifndef _BASSETPROGPTRX
#define _BASSETPROGPTRX 34286
#endif

// Decimal 34291 (0x85F3) [Value] - Basic Command
#ifndef _CMDRETURN
#define _CMDRETURN 34291
#endif

// Decimal 34323 (0x8613) [Value] - Basic Command
#ifndef _CMDDATA
#define _CMDDATA 34323
#endif

// Decimal 34326 (0x8616) [Value] - Basic Command
#ifndef _CMDREM
#define _CMDREM 34326
#endif

// Decimal 34375 (0x8647) [Value] - Basic Command
#ifndef _CMDIF
#define _CMDIF 34375
#endif

// Decimal 34421 (0x8675) [Value] - Basic Command
#ifndef _CMDON
#define _CMDON 34421
#endif

// Decimal 34458 (0x869A) [Value] - Get line no and store in BasTempLine
#ifndef _BASGETLINENO
#define _BASGETLINENO 34458
#endif

// Decimal 34492 (0x86BC) [Value] - Basic Command
#ifndef _CMDLET
#define _CMDLET 34492
#endif

// Decimal 34603 (0x872B) [Value] - Basic Command
#ifndef _CMDINPUT
#define _CMDINPUT 34603
#endif

// Decimal 34679 (0x8777) [Value] - Basic Command
#ifndef _CMDREAD
#define _CMDREAD 34679
#endif

// Decimal 34682 (0x877A) [Value] - As basic READ command but ptr in X supplied by caller
#ifndef _CMDREADFROMX
#define _CMDREADFROMX 34682
#endif

// Decimal 34857 (0x8829) [Value] - Basic Command
#ifndef _CMDNEXT
#define _CMDNEXT 34857
#endif

// Decimal 34932 (0x8874) [Value] - Evaluate and put the VARPTR of experssion which follows in BasVarAssign16 (carry clear)
#ifndef _VARGETEXPRCC
#define _VARGETEXPRCC 34932
#endif

// Decimal 34935 (0x8877) [Value] - Evaluate and put the VARPTR of experssion which follows in BasVarAssign16 (carry set)
#ifndef _VARGETEXPR
#define _VARGETEXPR 34935
#endif

// Decimal 34946 (0x8882) [Value] - Print ?TM Error and return to basic
#ifndef _BASTMERROR
#define _BASTMERROR 34946
#endif

// Decimal 34951 (0x8887) [Value] - Compiles string and moves to free string space, should be followed by VarGetExpr
#ifndef _VARGETSTR
#define _VARGETSTR 34951
#endif

// Decimal 35236 (0x89A4) [Value] - Check for Close bracket ')' in command line, SNError if not
#ifndef _VARCKCLBRAC
#define _VARCKCLBRAC 35236
#endif

// Decimal 35239 (0x89A7) [Value] - Check for Open bracket '(' in command line, SNError if not
#ifndef _VARCKOPBRAC
#define _VARCKOPBRAC 35239
#endif

// Decimal 35242 (0x89AA) [Value] - Check for Comma in command line, SNError if not
#ifndef _VARCKCOMMA
#define _VARCKCOMMA 35242
#endif

// Decimal 35244 (0x89AC) [Value] - Check for char in B register in command line, SNError if not
#ifndef _VARCKCHAR
#define _VARCKCHAR 35244
#endif

// Decimal 35252 (0x89B4) [Value] - Print ?SN Error and return to basic
#ifndef _BASSNERROR
#define _BASSNERROR 35252
#endif

// Decimal 35345 (0x8A11) [Value] - Basic Command
#ifndef _CMDOR
#define _CMDOR 35345
#endif

// Decimal 35346 (0x8A12) [Value] - Basic Command
#ifndef _CMDAND
#define _CMDAND 35346
#endif

// Decimal 35467 (0x8A8B) [Value] - Basic Command
#ifndef _CMDDIM
#define _CMDDIM 35467
#endif

// Decimal 35476 (0x8A94) [Value] - Gets VARPTR address of following name and places in BasVarPtrLast
#ifndef _VARGETVAR
#define _VARGETVAR 35476
#endif

// Decimal 35625 (0x8B29) [Value] - Returns argument to USRnn as a 16bit no in D
#ifndef _VARGETUSR
#define _VARGETUSR 35625
#endif

// Decimal 35725 (0x8B8D) [Value] - Print ?FC Error and return to basic
#ifndef _BASFCERROR
#define _BASFCERROR 35725
#endif

// Decimal 35889 (0x8C31) [Value] - Basic Command
#ifndef _CMDMEM
#define _CMDMEM 35889
#endif

// Decimal 35893 (0x8C35) [Value] - Assigns value in D register to a variable, and returns to basic
#ifndef _VARASSIGN16BIT
#define _VARASSIGN16BIT 35893
#endif

// Decimal 35894 (0x8C36) [Value] - Assigns value in B register to a variable, and returns to basic
#ifndef _VARASSIGN8BIT
#define _VARASSIGN8BIT 35894
#endif

// Decimal 35895 (0x8C37) [Value] - Assigns value in D register to a variable, and returns to basic (1 less instruction!).
#ifndef _VARASSIGN16BIT2
#define _VARASSIGN16BIT2 35895
#endif

// Decimal 35904 (0x8C40) [Value] - Basic Command
#ifndef _CMDSTRS
#define _CMDSTRS 35904
#endif

// Decimal 35922 (0x8C52) [Value] - Reserve B bytes of string space return start in X, setup low mem vars
#ifndef _BASRESSTR
#define _BASRESSTR 35922
#endif

// Decimal 36019 (0x8CB3) [Value] - Reserve B bytes of string space return start in X
#ifndef _BASRESSTR2
#define _BASRESSTR2 36019
#endif

// Decimal 36055 (0x8CD7) [Value] - Forces garbage collection in string space
#ifndef _VARGARBAGECOLLECT
#define _VARGARBAGECOLLECT 36055
#endif

// Decimal 36250 (0x8D9A) [Value] - Get string len in B and address in X of string desc in FPA2
#ifndef _BASGETSTRLENADDR
#define _BASGETSTRLENADDR 36250
#endif

// Decimal 36255 (0x8D9F) [Value] - Frees up storage used by a variable
#ifndef _VARDELVAR
#define _VARDELVAR 36255
#endif

// Decimal 36295 (0x8DC7) [Value] - Basic Command
#ifndef _CMDLEN
#define _CMDLEN 36295
#endif

// Decimal 36306 (0x8DD2) [Value] - Basic Command
#ifndef _CMDCHRS
#define _CMDCHRS 36306
#endif

// Decimal 36326 (0x8DE6) [Value] - Basic Command
#ifndef _CMDASC
#define _CMDASC 36326
#endif

// Decimal 36330 (0x8DEA) [Value] - Get first character of string into B
#ifndef _BASGETSTRFIRST
#define _BASGETSTRFIRST 36330
#endif

// Decimal 36337 (0x8DF1) [Value] - Basic Command
#ifndef _CMDLEFTS
#define _CMDLEFTS 36337
#endif

// Decimal 36366 (0x8E0E) [Value] - Basic Command
#ifndef _CMDRIGHTS
#define _CMDRIGHTS 36366
#endif

// Decimal 36373 (0x8E15) [Value] - Basic Command
#ifndef _CMDMIDS
#define _CMDMIDS 36373
#endif

// Decimal 36433 (0x8E51) [Value] - Returns value of variable in B,FCError if more than 8 bits
#ifndef _VARGET8BIT
#define _VARGET8BIT 36433
#endif

// Decimal 36444 (0x8E5C) [Value] - Basic Command
#ifndef _CMDVAL
#define _CMDVAL 36444
#endif

// Decimal 36478 (0x8E7E) [Value] - Checks for comman then gets 8 bit.
#ifndef _VARGETCOMMA8
#define _VARGETCOMMA8 36478
#endif

// Decimal 36483 (0x8E83) [Value] - Returns value of variable in D,FCError if more than 16 bits
#ifndef _VARGET16BIT
#define _VARGET16BIT 36483
#endif

// Decimal 36502 (0x8E96) [Value] - Basic Command
#ifndef _CMDPEEK
#define _CMDPEEK 36502
#endif

// Decimal 36509 (0x8E9D) [Value] - Basic Command
#ifndef _CMDPOKE
#define _CMDPOKE 36509
#endif

// Decimal 36516 (0x8EA4) [Value] - Basic Command
#ifndef _CMDLLIST
#define _CMDLLIST 36516
#endif

// Decimal 36522 (0x8EAA) [Value] - Basic Command
#ifndef _CMDLIST
#define _CMDLIST 36522
#endif

// Decimal 36522 (0x8EAA) [Value] - List basic program to SysDevN A must be 0 on entry
#ifndef _BASLIST
#define _BASLIST 36522
#endif

// Decimal 36925 (0x903D) [Value] - Basic Command
#ifndef _CMDPRINT
#define _CMDPRINT 36925
#endif

// Decimal 37025 (0x90A1) [Value] - Outputs an EOL sequence to the screen
#ifndef _TEXTOUTCRLF
#define _TEXTOUTCRLF 37025
#endif

// Decimal 37093 (0x90E5) [Value] - Outputs string pointed to by X to screen, X should point to byte before first byte of string
#ifndef _TEXTOUTSTRING
#define _TEXTOUTSTRING 37093
#endif

// Decimal 37109 (0x90F5) [Value] - Outputs a space to screen
#ifndef _TEXTOUTSPACE
#define _TEXTOUTSPACE 37109
#endif

// Decimal 37112 (0x90F8) [Value] - Outputs a question mark to screen
#ifndef _TEXTOUTQUESTION
#define _TEXTOUTQUESTION 37112
#endif

// Decimal 37125 (0x9105) [Value] - Basic Command
#ifndef _CMDMINUS
#define _CMDMINUS 37125
#endif

// Decimal 37134 (0x910E) [Value] - Basic Command
#ifndef _CMDPLUS
#define _CMDPLUS 37134
#endif

// Decimal 37221 (0x9165) [Value] - Normalize FPA0
#ifndef _VARNORMFPA0
#define _VARNORMFPA0 37221
#endif

// Decimal 37436 (0x923C) [Value] - Basic Command
#ifndef _CMDLOG
#define _CMDLOG 37436
#endif

// Decimal 37493 (0x9275) [Value] - Basic Command
#ifndef _CMDMULTIPLY
#define _CMDMULTIPLY 37493
#endif

// Decimal 37692 (0x933C) [Value] - Basic Command
#ifndef _CMDDIVIDE
#define _CMDDIVIDE 37692
#endif

// Decimal 37925 (0x9425) [Value] - Basic Command
#ifndef _CMDSGN
#define _CMDSGN 37925
#endif

// Decimal 37950 (0x943E) [Value] - Basic Command
#ifndef _CMDABS
#define _CMDABS 37950
#endif

// Decimal 38041 (0x9499) [Value] - Basic Command
#ifndef _CMDINT
#define _CMDINT 38041
#endif

// Decimal 38266 (0x957A) [Value] - Outputs unsigned integer in D to the TextDevN device
#ifndef _TEXTOUTNUM16
#define _TEXTOUTNUM16 38266
#endif

// Decimal 38274 (0x9582) [Value] - Outputs number in FPA0 to screen
#ifndef _TEXTOUTNUMFPA0
#define _TEXTOUTNUMFPA0 38274
#endif

// Decimal 38551 (0x9697) [Value] - Basic Command
#ifndef _CMDSQR
#define _CMDSQR 38551
#endif

// Decimal 38560 (0x96A0) [Value] - Basic Command
#ifndef _CMDEXPONET
#define _CMDEXPONET 38560
#endif

// Decimal 38675 (0x9713) [Value] - Basic Command
#ifndef _CMDEXP
#define _CMDEXP 38675
#endif

// Decimal 38770 (0x9772) [Value] - Basic Command
#ifndef _CMDRND
#define _CMDRND 38770
#endif

// Decimal 38798 (0x978E) [Value] - Generate an 8 bit random number and place in BasRandomSeed+1
#ifndef _BASRANDOM8
#define _BASRANDOM8 38798
#endif

// Decimal 38859 (0x97CB) [Value] - Basic Command
#ifndef _CMDCOS
#define _CMDCOS 38859
#endif

// Decimal 38865 (0x97D1) [Value] - Basic Command
#ifndef _CMDSIN
#define _CMDSIN 38865
#endif

// Decimal 38934 (0x9816) [Value] - Basic Command
#ifndef _CMDTAN
#define _CMDTAN 38934
#endif

// Decimal 39031 (0x9877) [Value] - Basic Command
#ifndef _CMDATN
#define _CMDATN 39031
#endif

// Decimal 39195 (0x991B) [Value] - Write a binary file out push return address, then start,end and entry addresses and then JMP to this
#ifndef _CASWRITEBIN
#define _CASWRITEBIN 39195
#endif

// Decimal 39254 (0x9956) [Value] - Basic Command
#ifndef _CMDFIX
#define _CMDFIX 39254
#endif

// Decimal 39269 (0x9965) [Value] - Basic Command
#ifndef _CMDEDIT
#define _CMDEDIT 39269
#endif

// Decimal 39641 (0x9AD9) [Value] - Basic Command
#ifndef _CMDTRON
#define _CMDTRON 39641
#endif

// Decimal 39642 (0x9ADA) [Value] - Basic Command
#ifndef _CMDTROFF
#define _CMDTROFF 39642
#endif

// Decimal 39646 (0x9ADE) [Value] - Basic Command
#ifndef _CMDPOS
#define _CMDPOS 39646
#endif

// Decimal 39668 (0x9AF4) [Value] - Basic Command
#ifndef _CMDVARPTR
#define _CMDVARPTR 39668
#endif

// Decimal 39812 (0x9B84) [Value] - Basic Command
#ifndef _CMDSTRINGS
#define _CMDSTRINGS 39812
#endif

// Decimal 39860 (0x9BB4) [Value] - Basic Command
#ifndef _CMDINSTR
#define _CMDINSTR 39860
#endif

// Decimal 39998 (0x9C3E) [Value] - Assigns value in BasVarAssign16 to a variable, and returns to basic
#ifndef _VARASSIGN16BITB
#define _VARASSIGN16BITB 39998
#endif

// Decimal 40054 (0x9C76) [Value] - Check for direct mode, ID Error if so
#ifndef _BASCHKDIRECT
#define _BASCHKDIRECT 40054
#endif

// Decimal 40065 (0x9C81) [Value] - Basic Command
#ifndef _CMDDEF
#define _CMDDEF 40065
#endif

// Decimal 40221 (0x9D1D) [Value] - Basic Command
#ifndef _CMDUSR
#define _CMDUSR 40221
#endif

// Decimal 40253 (0x9D3D) [Value] - Basic IRQ routine, increments timer
#ifndef _BASIRQVEC
#define _BASIRQVEC 40253
#endif

// Decimal 40281 (0x9D59) [Value] - Basic Command
#ifndef _CMDTIMER
#define _CMDTIMER 40281
#endif

// Decimal 40289 (0x9D61) [Value] - Basic Command
#ifndef _CMDDELETE
#define _CMDDELETE 40289
#endif

// Decimal 40369 (0x9DB1) [Value] - Line input command
#ifndef _CMDLINEINPUT
#define _CMDLINEINPUT 40369
#endif

// Decimal 40409 (0x9DD9) [Value] - Entry into LINE INPUT routine, used by DOS
#ifndef _BASLINEINPUTENTRY
#define _BASLINEINPUTENTRY 40409
#endif

// Decimal 40442 (0x9DFA) [Value] - Basic Command
#ifndef _CMDRENUM
#define _CMDRENUM 40442
#endif

// Decimal 40960 (0xA000) [Value] - Indirect keyboard input jsr()
#ifndef _INDKEYINPUT
#define _INDKEYINPUT 40960
#endif

// Decimal 40962 (0xA002) [Value] - Indirect Character output
#ifndef _INDCHAROUTPUT
#define _INDCHAROUTPUT 40962
#endif

// Decimal 40964 (0xA004) [Value] - Indirect prepare cassette for read
#ifndef _INDCASONREAD
#define _INDCASONREAD 40964
#endif

// Decimal 40966 (0xA006) [Value] - Indirect Read cassette block
#ifndef _INDCASBLOCKIN
#define _INDCASBLOCKIN 40966
#endif

// Decimal 40968 (0xA008) [Value] - Indirect Write cassete block
#ifndef _INDCASBLOCKOUT
#define _INDCASBLOCKOUT 40968
#endif

// Decimal 40970 (0xA00A) [Value] - Indirect joystick in
#ifndef _INDJOYSTICKIN
#define _INDJOYSTICKIN 40970
#endif

// Decimal 40972 (0xA00C) [Value] - Indirect Write cassette leader
#ifndef _INDCASWRITELEAD
#define _INDCASWRITELEAD 40972
#endif

// Decimal 40974 (0xA00E) [Value] - Basic Command
#ifndef _CMDHEXS
#define _CMDHEXS 40974
#endif

// Decimal 41033 (0xA049) [Value] - Basic Command
#ifndef _CMDDLOAD
#define _CMDDLOAD 41033
#endif

// Decimal 41194 (0xA0EA) [Value] - Same as TextWaitKey, but with cursor
#ifndef _TEXTWAITKEYCURS
#define _TEXTWAITKEYCURS 41194
#endif

// Decimal 42603 (0xA66B) [Value] - Pixel mask table 2 colour mode
#ifndef _PIXMASKTABLE2COL
#define _PIXMASKTABLE2COL 42603
#endif

// Decimal 42611 (0xA673) [Value] - Pixel mask table 4 colour mode
#ifndef _PIXMASKTABLE4COL
#define _PIXMASKTABLE4COL 42611
#endif

// Decimal 42695 (0xA6C7) [Value] - Basic Command
#ifndef _CMDPPOINT
#define _CMDPPOINT 42695
#endif

// Decimal 42735 (0xA6EF) [Value] - Basic Command
#ifndef _CMDPSET
#define _CMDPSET 42735
#endif

// Decimal 42739 (0xA6F3) [Value] - Basic Command
#ifndef _CMDPRESET
#define _CMDPRESET 42739
#endif

// Decimal 42825 (0xA749) [Value] - Basic Command
#ifndef _CMDLINE
#define _CMDLINE 42825
#endif

// Decimal 43200 (0xA8C0) [Value] - Basic Command
#ifndef _CMDPCLS
#define _CMDPCLS 43200
#endif

// Decimal 43207 (0xA8C7) [Value] - Clears grapics screen to value in B
#ifndef _GRCLEARGRSCREEN
#define _GRCLEARGRSCREEN 43207
#endif

// Decimal 43220 (0xA8D4) [Value] - Basic Command
#ifndef _CMDCOLOR
#define _CMDCOLOR 43220
#endif

// Decimal 43304 (0xA928) [Value] - Sets up colours in low memory
#ifndef _GRSETCOLOURS
#define _GRSETCOLOURS 43304
#endif

// Decimal 43320 (0xA938) [Value] - Sets Text or Graphics screen, if Z=1 then text
#ifndef _GRSELECTDISPLAY
#define _GRSELECTDISPLAY 43320
#endif

// Decimal 43322 (0xA93A) [Value] - Resets to text mode and screen base address of $400
#ifndef _TEXTRESETVDU
#define _TEXTRESETVDU 43322
#endif

// Decimal 43401 (0xA989) [Value] - Set VDG to mode in A register
#ifndef _GRSETVDGMODE
#define _GRSETVDGMODE 43401
#endif

// Decimal 43421 (0xA99D) [Value] - Set VDG offset to page in A
#ifndef _GRSETVDGOFFSET
#define _GRSETVDGOFFSET 43421
#endif

// Decimal 43428 (0xA9A4) [Value] - Select colour set from data in GrColourSet
#ifndef _GRSELECTVDGCOLSET
#define _GRSELECTVDGCOLSET 43428
#endif

// Decimal 43439 (0xA9AF) [Value] - Basic Command
#ifndef _CMDPMODE
#define _CMDPMODE 43439
#endif

// Decimal 43489 (0xA9E1) [Value] - On entry B contains Pmode page to be used
#ifndef _GRSELECTPAGE
#define _GRSELECTPAGE 43489
#endif

// Decimal 43518 (0xA9FE) [Value] - Basic Command
#ifndef _CMDSCREEN
#define _CMDSCREEN 43518
#endif

// Decimal 43536 (0xAA10) [Value] - Selects colour set dependent on B
#ifndef _GRSELECTCOLOURSET
#define _GRSELECTCOLOURSET 43536
#endif

// Decimal 43545 (0xAA19) [Value] - Basic Command
#ifndef _CMDPCLEAR
#define _CMDPCLEAR 43545
#endif

// Decimal 43555 (0xAA23) [Value] - Reserves memory for graphics, no graphics pages in B
#ifndef _GRRESERVEGRRAM
#define _GRRESERVEGRRAM 43555
#endif

// Decimal 43655 (0xAA87) [Value] - Initialise beginning of basic after graphics screen, no of pages in A
#ifndef _BASLOCATESCREEN
#define _BASLOCATESCREEN 43655
#endif

// Decimal 43710 (0xAABE) [Value] - Basic Command
#ifndef _CMDPCOPY
#define _CMDPCOPY 43710
#endif

// Decimal 43760 (0xAAF0) [Value] - Basic Command
#ifndef _CMDGET
#define _CMDGET 43760
#endif

// Decimal 43763 (0xAAF3) [Value] - Basic Command
#ifndef _CMDPUT
#define _CMDPUT 43763
#endif

// Decimal 44167 (0xAC87) [Value] - Basic Command
#ifndef _CMDPAINT
#define _CMDPAINT 44167
#endif

// Decimal 44477 (0xADBD) [Value] - Basic Command
#ifndef _CMDPLAY
#define _CMDPLAY 44477
#endif

// Decimal 44698 (0xAE9A) [Value] - Plays a note from the A register (ASCII)
#ifndef _SNDPLAYNOTE
#define _SNDPLAYNOTE 44698
#endif

// Decimal 45137 (0xB051) [Value] - Draw on pmode screen as in DRAW command
#ifndef _GRDRAW
#define _GRDRAW 45137
#endif

// Decimal 45137 (0xB051) [Value] - Basic Command
#ifndef _CMDDRAW
#define _CMDDRAW 45137
#endif

// Decimal 45624 (0xB238) [Value] - Basic Command
#ifndef _CMDCIRCLE
#define _CMDCIRCLE 45624
#endif

// Decimal 46004 (0xB3B4) [Value] - Perform soft reset, as if reset button pressed
#ifndef _SYSRESET
#define _SYSRESET 46004
#endif

// Decimal 46080 (0xB400) [Value] - Restart basic, as if power on, also deletes current program
#ifndef _BASBOOTBASIC
#define _BASBOOTBASIC 46080
#endif

// Decimal 46159 (0xB44F) [Value] - Warm start routine
#ifndef _WARMSTART
#define _WARMSTART 46159
#endif

// Decimal 46258 (0xB4B2) [Value] - Signon message address, for CoCo this is for Extended basic.
#ifndef _BASSIGNONMESS
#define _BASSIGNONMESS 46258
#endif

// Decimal 46341 (0xB505) [Value] - Same as TextWaitKey, but with cursor
#ifndef _TEXTWAITKEYCURS2
#define _TEXTWAITKEYCURS2 46341
#endif

// Decimal 46410 (0xB54A) [Value] - Outputs character in A to screen
#ifndef _TEXTOUTCHAR
#define _TEXTOUTCHAR 46410
#endif

// Decimal 46547 (0xB5D3) [Value] - Read input buffer at X as basic input
#ifndef _BASINBUFFFROMX
#define _BASINBUFFFROMX 46547
#endif

// Decimal 46669 (0xB64D) [Value] - Basic Command
#ifndef _CMDCLOSE
#define _CMDCLOSE 46669
#endif

// Decimal 46687 (0xB65F) [Value] - Close any open cassete file
#ifndef _CASCLOSFILES
#define _CASCLOSFILES 46687
#endif

// Decimal 46723 (0xB683) [Value] - Basic Command
#ifndef _CMDCSAVE
#define _CMDCSAVE 46723
#endif

// Decimal 46757 (0xB6A5) [Value] - Write tokenized basic program out, similar to CSAVE
#ifndef _CASWRITEBASIC
#define _CASWRITEBASIC 46757
#endif

// Decimal 46805 (0xB6D5) [Value] - Basic Command
#ifndef _CMDCLOAD
#define _CMDCLOAD 46805
#endif

// Decimal 46920 (0xB748) [Value] - Read in a binary file, similar to CLOADM
#ifndef _CASREADBIN
#define _CASREADBIN 46920
#endif

// Decimal 46961 (0xB771) [Value] - Basic Command
#ifndef _CMDEXEC
#define _CMDEXEC 46961
#endif

// Decimal 46999 (0xB797) [Value] - Basic Command
#ifndef _CMDINKEYS
#define _CMDINKEYS 46999
#endif

// Decimal 47052 (0xB7CC) [Value] - Copy B bytes from X to U
#ifndef _UTILCOPYBXTOU
#define _UTILCOPYBXTOU 47052
#endif

// Decimal 47060 (0xB7D4) [Value] - Get dev no from line & validate
#ifndef _BASGETDEVNO
#define _BASGETDEVNO 47060
#endif

// Decimal 47105 (0xB801) [Value] - Basic Command
#ifndef _CMDEOF
#define _CMDEOF 47105
#endif

// Decimal 47135 (0xB81F) [Value] - Basic Command
#ifndef _CMDSKIPF
#define _CMDSKIPF 47135
#endif

// Decimal 47145 (0xB829) [Value] - Basic Command
#ifndef _CMDOPEN
#define _CMDOPEN 47145
#endif

// Decimal 47157 (0xB835) [Value] - Entry into Basic open command used by Dragon/SuperDos
#ifndef _CMDOPENENTRY
#define _CMDOPENENTRY 47157
#endif

// Decimal 47176 (0xB848) [Value] - Print ?FM Error and return to basic
#ifndef _BASFMERROR
#define _BASFMERROR 47176
#endif

// Decimal 47283 (0xB8B3) [Value] - Searches a tape for specified filename
#ifndef _CASFINDFILE
#define _CASFINDFILE 47283
#endif

// Decimal 47411 (0xB933) [Value] - Turns on motor, reads header and then first block into CasIOBufAddr
#ifndef _CASREADBLOCK1
#define _CASREADBLOCK1 47411
#endif

// Decimal 47422 (0xB93E) [Value] - Reads a block into the cassete buffer pointed to by CasIOBuffAddr
#ifndef _CASBLOCKIN
#define _CASBLOCKIN 47422
#endif

// Decimal 47490 (0xB982) [Value] - Basic Command
#ifndef _CMDMOTOR
#define _CMDMOTOR 47490
#endif

// Decimal 47505 (0xB991) [Value] - Turn on motor, write leader and then first block
#ifndef _CASWRITEBLOCK1
#define _CASWRITEBLOCK1 47505
#endif

// Decimal 47513 (0xB999) [Value] - Write a block to cassete pointed to by CasIOBuffAddr
#ifndef _CASBLOCKOUT
#define _CASBLOCKOUT 47513
#endif

// Decimal 47571 (0xB9D3) [Value] - Basic Command
#ifndef _CMDSET
#define _CMDSET 47571
#endif

// Decimal 47583 (0xB9DF) [Value] - Sets lo res pixel
#ifndef _GRSETLRGPIXEL
#define _GRSETLRGPIXEL 47583
#endif

// Decimal 47620 (0xBA04) [Value] - Basic Command
#ifndef _CMDRESET
#define _CMDRESET 47620
#endif

// Decimal 47623 (0xBA07) [Value] - ReSets lo res pixel
#ifndef _GRRESETLRGPIXEL
#define _GRRESETLRGPIXEL 47623
#endif

// Decimal 47656 (0xBA28) [Value] - Calculates Lo-res pixel pos from data on stack
#ifndef _GRCALCPIXELPOS
#define _GRCALCPIXELPOS 47656
#endif

// Decimal 47685 (0xBA45) [Value] - Basic Command
#ifndef _CMDPOINT
#define _CMDPOINT 47685
#endif

// Decimal 47712 (0xBA60) [Value] - Basic Command
#ifndef _CMDCLS
#define _CMDCLS 47712
#endif

// Decimal 47735 (0xBA77) [Value] - Clear text mode screen, resets cursor to top left
#ifndef _TEXTCLS
#define _TEXTCLS 47735
#endif

// Decimal 47737 (0xBA79) [Value] - Clears srcrren to character in B register & resets cursor
#ifndef _TEXTCLSCHAR
#define _TEXTCLSCHAR 47737
#endif

// Decimal 47771 (0xBA9B) [Value] - Basic Command
#ifndef _CMDSOUND
#define _CMDSOUND 47771
#endif

// Decimal 47776 (0xBAA0) [Value] - Play a beep duration in B, frequency in SndPitch
#ifndef _SNDBEEP
#define _SNDBEEP 47776
#endif

// Decimal 47811 (0xBAC3) [Value] - Disables D/A sound output
#ifndef _SNDDISABLE
#define _SNDDISABLE 47811
#endif

// Decimal 47811 (0xBAC3) [Value] - Turn off audio from cassette
#ifndef _CASAUDIOOFF
#define _CASAUDIOOFF 47811
#endif

// Decimal 47813 (0xBAC5) [Value] - Enables D/A sound output
#ifndef _SNDENABLE
#define _SNDENABLE 47813
#endif

// Decimal 47828 (0xBAD4) [Value] - Reset D/A converter to $7E
#ifndef _SYSRESETDA
#define _SYSRESETDA 47828
#endif

// Decimal 47830 (0xBAD6) [Value] - Write value in A to D/A, bits 0 &1 should be 0
#ifndef _SYSWRITEDA
#define _SYSWRITEDA 47830
#endif

// Decimal 47839 (0xBADF) [Value] - Basic Command
#ifndef _CMDAUDIO
#define _CMDAUDIO 47839
#endif

// Decimal 47852 (0xBAEC) [Value] - Turn on Audio from cassete to speaker
#ifndef _CASAUDIOON
#define _CASAUDIOON 47852
#endif

// Decimal 47853 (0xBAED) [Value] - Turn on audio to D/A converter
#ifndef _SNDDTOAON
#define _SNDDTOAON 47853
#endif

// Decimal 47885 (0xBB0D) [Value] - Basic Command
#ifndef _CMDJOYSTK
#define _CMDJOYSTK 47885
#endif

// Decimal 48000 (0xBB80) [Value] - Dragon 64 only, boots basic into all ram mode, with 48K available to basic.
#ifndef _SYSBOOT64
#define _SYSBOOT64 48000
#endif

// Decimal 48053 (0xBBB5) [Value] - Decrements TextCursFlashCnt, if zero resets and flashes cursor
#ifndef _TEXTUPDATECURS
#define _TEXTUPDATECURS 48053
#endif

// Decimal 48101 (0xBBE5) [Value] - Scan keyboard, return Char in A, Zero flag set if no key
#ifndef _TEXTSCANKBD
#define _TEXTSCANKBD 48101
#endif

// Decimal 48288 (0xBCA0) [Value] - Clears a VDU line from current cursor pos to EOL
#ifndef _TEXTCLEARLINE
#define _TEXTCLEARLINE 48288
#endif

// Decimal 48299 (0xBCAB) [Value] - Outputs Char in A to VDU, does not reset screen.
#ifndef _TEXTVDUOUT
#define _TEXTVDUOUT 48299
#endif

// Decimal 48373 (0xBCF5) [Value] - Sends character in A register to printer (uncooked)
#ifndef _PRINTERDIROUT
#define _PRINTERDIROUT 48373
#endif

// Decimal 48394 (0xBD0A) [Value] - Moves printer head to next line.
#ifndef _PRINTERCRLF
#define _PRINTERCRLF 48394
#endif

// Decimal 48410 (0xBD1A) [Value] - Sends character in A register to printer
#ifndef _PRINTEROUT
#define _PRINTEROUT 48410
#endif

// Decimal 48449 (0xBD41) [Value] - Select joystick alue to read from A
#ifndef _SYSSELJOYSTICK
#define _SYSSELJOYSTICK 48449
#endif

// Decimal 48466 (0xBD52) [Value] - Read hardware joystick values & update BasJoyVal0..3
#ifndef _SYSREADJOYSTICK
#define _SYSREADJOYSTICK 48466
#endif

// Decimal 48549 (0xBDA5) [Value] - Reads a bity into the 'Z' flag
#ifndef _CASBITIN
#define _CASBITIN 48549
#endif

// Decimal 48557 (0xBDAD) [Value] - Reads a single byte into the A register
#ifndef _CASBYTEIN
#define _CASBYTEIN 48557
#endif

// Decimal 48591 (0xBDCF) [Value] - Turn on motor, and wait for delay in CasMotorDelay
#ifndef _CASMOTORON
#define _CASMOTORON 48591
#endif

// Decimal 48604 (0xBDDC) [Value] - Turn off cassette motor
#ifndef _CASMOTOROFF
#define _CASMOTOROFF 48604
#endif

// Decimal 48615 (0xBDE7) [Value] - Turn on motor and read past leader
#ifndef _CASREADLEADER
#define _CASREADLEADER 48615
#endif

// Decimal 48658 (0xBE12) [Value] - Write byte in A register to cassete
#ifndef _CASBYTEOUT
#define _CASBYTEOUT 48658
#endif

// Decimal 65287 (0xFF07) [Value] - Serial baud rate, note on Dragon 64, this is the actual hardware baud rate reg.
#ifndef _TEXTSERBAUDRATE
#define _TEXTSERBAUDRATE 65287
#endif


#endif
